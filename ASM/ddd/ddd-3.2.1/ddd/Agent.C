// $Id: Agent.C,v 1.24 1999/08/19 11:27:01 andreas Exp $
// Three-channel Agent Interface

// Copyright (C) 1995 Technische Universitaet Braunschweig, Germany.
// Written by Andreas Zeller <zeller@gnu.org>.
// 
// This file is part of DDD.
// 
// DDD is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public
// License as published by the Free Software Foundation; either
// version 2 of the License, or (at your option) any later version.
// 
// DDD is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
// See the GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public
// License along with DDD -- see the file COPYING.
// If not, write to the Free Software Foundation, Inc.,
// 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
// 
// DDD is the data display debugger.
// For details, see the DDD World-Wide-Web page, 
// `http://www.gnu.org/software/ddd/',
// or send a mail to the DDD developers <ddd@gnu.org>.

char Agent_rcsid[] = 
    "$Id: Agent.C,v 1.24 1999/08/19 11:27:01 andreas Exp $";

#ifdef __GNUG__
#pragma implementation
#endif

#include "assert.h"
#include "config.h"

#include <iostream.h>

#include <errno.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

extern "C" {
#include <sys/types.h>
#include <sys/wait.h>
}

#ifndef EXIT_SUCCESS
#define EXIT_SUCCESS 0
#endif

#ifndef EXIT_FAILURE
#define EXIT_FAILURE 1
#endif


#include "sigName.h"
#include "Agent.h"
#include "AgentM.h"

DEFINE_TYPE_INFO_0(Agent)

// Child Status Change Handler
void Agent::childStatusChange(int sig)
{
    // Notify agents of their new status
    runningAgents.childStatusChange();

    // Reinstall ourselves (for SVR4 and others)
    signal(sig, SignalProc(Agent::childStatusChange));
}

// Default I/O error handler
void Agent::defaultHandler(Agent *source, void *, void *call_data)
{
    string msg = (char *)call_data;
    if (msg != "Exit 0")
	cerr << source->name() << ": " << msg << "\n";
}

void Agent::addDefaultHandler(unsigned type)
{
    addHandler(type, defaultHandler);
}


// All running agents
AgentManager Agent::runningAgents((SignalProc)Agent::childStatusChange);

// Running states
void Agent::setRunning()
{
    bool was_running = _running;
    _running = true;

#if 0
    Agent *agent = runningAgents.search(pid());
    if (agent != 0)
	cerr << "Warning: Agent " << agent->name() << " started twice\n";
#endif

    runningAgents += this;
    activateIO();

    if (!was_running)
	callHandlers(Started, (char *)path());
}

void Agent::unsetRunning()
{
    if (_running)
	callHandlers(Stopped, (char *)path());

    deactivateIO();
    runningAgents -= this;
    _running = false;
}


// Duplicator
Agent::Agent(const Agent& c):
    _pid(c._pid), _inputfp(0), _outputfp(0), _errorfp(0), 
    _running(c._running),
    _beingTerminated(c._beingTerminated), _lastStatus(c._lastStatus),
    _terminateTimeOut(c._terminateTimeOut),
    _hangupTimeOut(c._hangupTimeOut),
    _killTimeOut(c._killTimeOut),
    handlers(c.handlers), next(0), _path(c._path)
{
    // Assume running unless shown otherwise
    setRunning();
}


void Agent::restoreParentIO()
{
    // Nothing specific to do here
}

// start Agent
void Agent::start()
{
    // Start child process if we're not listening to stdin
    if (pid() >= 0)
	startChildProcess();
    else
	setRunning();
}

// Start the child process
void Agent::startChildProcess()
{
    if (running())
    {
	// Kill whatever's still running there
	terminate();
    }

    if (setupCommunication())
    {
	raiseMsg("communication setup failed");
	return;
    }
    
    if ((_pid = fork()) == 0)
    {
	if (setupChildCommunication())
	{
	    raiseMsg("child communication setup failed");
	    exit(EXIT_FAILURE);
	}
	
	executeChild();
    }

    if (pid() == -1)
    {
	_pid = 0;
	raiseIOMsg("cannot fork");
	return;
    }

    if (setupParentCommunication())
    {
	raiseMsg("parent communication setup failed");
	return;
    }

    // agent is now set up and running
    setRunning();
}


// Setup common communication
int Agent::setupCommunication()
{
    // open pipes for stdin, stdout and stderr
    if (pipe(to_child) < 0)
    {
	raiseIOMsg("cannot open stdin pipe");
	return -1;
    }

    if (pipe(to_parent) < 0)
    {
	raiseIOMsg("cannot open stdout pipe");
	return -1;
    }

    if (pipe(to_parent_error) < 0)
    {
	raiseIOMsg("cannot open stderr pipe");
	return -1;
    }

    return 0;
}

// Setup child communication
int Agent::setupChildCommunication()
{
    // I am the child:
    // close unused pipe ends
    close(to_child[WRITE]);
    close(to_parent[READ]);
    close(to_parent_error[READ]);

    // assign stdin to to_child, stdout to to_parent, and
    // stderr to to_parent_error
    dup2(to_child[READ], fileno(stdin));
    close(to_child[READ]);

    dup2(to_parent[WRITE], fileno(stdout));
    close(to_parent[WRITE]);

    dup2(to_parent_error[WRITE], fileno(stderr));
    close(to_parent_error[WRITE]);

    return 0;
}

// Setup parent communication
int Agent::setupParentCommunication()
{
    // I am the parent: close unused pipe ends
    close(to_child[READ]);
    close(to_parent[WRITE]);
    close(to_parent_error[WRITE]);

    // access remaining pipe ends via stream I/O
    // using error, in and out...
    _errorfp = fdopen(to_parent_error[READ], "r");
    if (errorfp() == NULL)
    {
	raiseIOMsg("cannot fdopen child's stdin pipe");
	terminate();
	return -1;
    }

    _inputfp = fdopen(to_parent[READ], "r");
    if (inputfp() == NULL)
    {
	raiseIOMsg("cannot fdopen child's stdout pipe");
	terminate();
	return -1;
    }

    _outputfp = fdopen(to_child[WRITE], "w");
    if (outputfp() == NULL)
    {
	raiseIOMsg("cannot fdopen child's stderr pipe");
	terminate();
	return -1;
    }

    return 0;
}

// Actually execute the child
void Agent::executeChild()
{
    // start child
    string exec_str = "exec " + path();
    char *exec_cmd = exec_str;
    execl("/bin/sh", "sh", "-c", exec_cmd, (char *)0);

    // could not find child: send message to parent via stderr
    perror("/bin/sh");
    _exit(EXIT_FAILURE);
}


// process all status changes since last call and check if still running
bool Agent::running()
{
    if (_running && pid() >= 0)
    {
	// Ignore interrupts for a while
	SignalProc istat = SignalProc(signal(SIGINT,  SignalProc(SIG_IGN)));
	SignalProc qstat = SignalProc(signal(SIGQUIT, SignalProc(SIG_IGN)));
	SignalProc hstat = SignalProc(signal(SIGHUP,  SignalProc(SIG_IGN)));

	// Query current process state
	pid_t r;
	int status;
	if ((r = waitpid(pid(), &status, WNOHANG)) > 0)
	{
	    // Agent stopped or terminated
	    assert(r == pid());
	    hasNewStatus(status);
	}
	else if (r < 0)
	{
	    if (errno == ECHILD)
	    {
		// No such child: agent is not running
		abort();
	    }
	    else
		_raiseIOMsg("wait failed");
	}

        // restore interrupts
	signal(SIGINT,  istat);
	signal(SIGQUIT, qstat);
	signal(SIGHUP,  hstat);
    }

    return _running;
}


// child status change
void Agent::hasNewStatus(int state)
{
    _lastStatus = state;

    if (WIFEXITED(((state))) || WIFSIGNALED(((state))))
    {
	// agent died: inhibit further communication
	abort();
    }
}


// terminate process
void Agent::terminate(bool onExit)
{
    if (onExit)
    {
	// We're exiting: call only the default handlers
	removeAllHandlers();
	addDefaultHandler(Panic);
	addDefaultHandler(Died);
    }

    if (!running())
    {
	restoreParentIO();
	return;
    }

    _beingTerminated = true;
    if (onExit)
    {
	// close files
	Agent::abort();
    }
    else
    {
	// call subclasses abort handlers
	abort();
    }
    _beingTerminated = false;

    if (pid() >= 0)
    {
	// wait until we're terminated
	if (onExit)
	    Agent::waitToTerminate();
	else
	    waitToTerminate();
    }

    // now, we're really done.
    unsetRunning();
}


// send KILL signal
void Agent::_kill(int sig)
{
    if (running() && pid() >= 0)
    {
	// Hasta la vista, agent

	if (kill(pid(), sig) < 0)
	    raiseIOMsg("Could not kill");
    }
}


// Wait for agent to terminate, sending signals
void Agent::waitToTerminate()
{
    int sig = 0;

    for (int seconds = 0; running(); seconds++)
    {
	sig = 0;

	if (seconds == terminateTimeOut())
	    sig = SIGTERM;

	if (seconds == hangupTimeOut())
	    sig = SIGHUP;

	if (seconds == killTimeOut())
	    sig = SIGKILL;

        if (sig)
	    _kill(sig);

        if (running())
	    sleep(1);
    }

    if (sig)
	raiseMsg(string("Agent wouldn't die (") + sigName(sig) + ")");
}


// Wait for agent to terminate, not sending signals
void Agent::wait()
{
    while (running())
    {
	int status;
	pid_t ret = waitpid(pid(), &status, 0);
	if (ret > 0)
	{
	    // Agent stopped or terminated
	    assert(ret == pid());
	    hasNewStatus(status);
	}
    }
}


// Close channel
// This handles several file pointers addressing one file
void Agent::closeChannel(FILE *fp)
{
    if (fp == 0)
	return;

    bool err = (fclose(fp) == EOF);

    if (fp == inputfp())
    {
	_inputfp = 0;
	if (err)
	    raiseIOMsg("couldn't close input channel");
    }

    if (fp == errorfp())
    {
	_errorfp = 0;
	if (err)
	    raiseIOMsg("couldn't close error channel");
    }

    if (fp == outputfp())
    {
	_outputfp = 0;
	if (err)
	    raiseIOMsg("couldn't close output channel");
    }
}

// send an EOF to agent
void Agent::shutdown()
{
    // We NEVER close stdout and stderr
    if (outputfp() == stdout || outputfp() == stderr)
	return;

    // Close output pipe
    closeChannel(outputfp());
}

// EOF on input detected
void Agent::inputEOF()
{
    // Check if we're still running
    running();

    // Call handlers
    callHandlers(InputEOF);

    // Clear error condition
    if (inputfp() != 0)
	clearerr(inputfp());
}

// EOF on error detected
void Agent::errorEOF()
{
    // Check if we're still running
    running();

    // Call handlers
    callHandlers(ErrorEOF);

    // Clear error condition
    if (errorfp() != 0)
	clearerr(errorfp());
}

// Inhibit further communication
void Agent::abort()
{
    restoreParentIO();

    // Close pipes.  We deliberately ignore any error messages here.
    shutdown();
    closeChannel(inputfp());
    closeChannel(errorfp());

    if (!_beingTerminated)
    {
	// Declare agent as "not running"
	unsetRunning();
    }

    if (_lastStatus >= 0)
    {
	// Call "Died" message handlers
	callHandlers(Died, statusName(_lastStatus));
	_lastStatus = -1;
    }
}

// Destructor
Agent::~Agent()
{
    // terminate agent gracefully
    terminate();
}
