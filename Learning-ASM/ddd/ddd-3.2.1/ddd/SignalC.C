// $Id: SignalC.C,v 1.10 1999/08/19 11:27:51 andreas Exp $
// Call destructors on signal

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

char SignalCatcher_rcsid[] = 
    "$Id: SignalC.C,v 1.10 1999/08/19 11:27:51 andreas Exp $";

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

#include "SignalC.h"
#include "AgentM.h"
#include "sigName.h"

#ifdef __GNUG__
extern "C" {
#if __GNUG__ < 2
    void __do_global_cleanup(void);
#else
    void __do_global_dtors(void);
#endif
    void _exit(int);
    void _cleanup();
}
#endif

#ifndef EXIT_SUCCESS
#define EXIT_SUCCESS 0
#endif

#ifndef EXIT_FAILURE
#define EXIT_FAILURE 1
#endif


// Kill all agents when an interrupt signal is received
static void cleanupOnSignal(int sig)
{
    // restore default action (if we're killed another time, this will make it)
    signal(sig, SignalProc(SIG_DFL));

    fprintf(stderr, "%s\nCleaning up... ", sigName(sig));

#ifdef __GNUG__
#if __GNUG__ < 2
    // Using a GNU compiler, we can call the cleanup actions
    // directly, rather than going through exit().
    __do_global_cleanup();
#else
    // same for version 2.0 and above
    __do_global_dtors();
#endif
#endif

    fprintf(stderr, "done.\n");

#ifdef __GNUG__
#ifdef sun
    // Using a SUN, we can also close all open files
    _cleanup();
#endif
    // Now exit gracefully, without calling destructors
    _exit(EXIT_FAILURE);
#else
    // Exit gracefully: this calls all destructors (but leaves no core)
    exit(EXIT_FAILURE);
#endif
}



// Constructor: catch them all
SignalCleanup::SignalCleanup()
{
    // if $NO_SIGNAL_CLEANUP is set, don't do anything
    if (getenv("NO_SIGNAL_CLEANUP") != NULL)
	return;

    // catch "typical" interrupt signals

#ifdef SIGHUP
    signal(SIGHUP,  cleanupOnSignal);	// hangup
#endif

#ifdef SIGINT
    signal(SIGINT,  cleanupOnSignal);	// interrupt
#endif

#ifdef SIGQUIT
    signal(SIGQUIT, cleanupOnSignal);	// quit
#endif

#ifdef SIGILL
    signal(SIGILL,  cleanupOnSignal);	// illegal instruction
#endif

#ifdef SIGABRT
    signal(SIGABRT, cleanupOnSignal);	// abort
#endif

#ifdef SIGFPE
    signal(SIGFPE,  cleanupOnSignal);	// floating point exception
#endif

#ifdef SIGBUS
    signal(SIGBUS,  cleanupOnSignal);	// bus error
#endif

#ifdef SIGSEGV
    signal(SIGSEGV, cleanupOnSignal);	// segmentation violation
#endif

#ifdef SIGSYS
    signal(SIGSYS,  cleanupOnSignal);	// bad argument to system call
#endif

#ifdef SIGTERM
    signal(SIGTERM, cleanupOnSignal);	// software termination signal
#endif

}
