// $Id: Command.h,v 1.10 1999/08/19 11:27:12 andreas Exp $ -*- C++ -*-
// DDD interface to GDB commands

// Copyright (C) 1996-1997 Technische Universitaet Braunschweig, Germany.
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

#ifndef _DDD_Command_h
#define _DDD_Command_h

#ifdef __GNUG__
#pragma interface
#endif

#include "GDBAgent.h"
#include "question.h"		// NO_GDB_ANSWER

#define COMMAND_PRIORITY_WORK  -1 // work procedures
#define COMMAND_PRIORITY_USER   0 // user-initiated commands
#define COMMAND_PRIORITY_BATCH  1 // batch jobs (auto commands)
#define COMMAND_PRIORITY_INIT   2 // init commands
#define COMMAND_PRIORITY_SYSTEM 3 // system-initiated commands
#define COMMAND_PRIORITY_AGAIN 99 // try again

// Commands
struct Command
{
    string command;		// Command text
    Widget origin;		// Origin
    OQCProc callback;		// Completion of COMMAND
    OACProc extra_callback;	// Completion of extra commands
    void *data;			// Data for callbacks
    bool echo;			// Flag: issue command in GDB console?
    bool verbose;		// Flag: issue answer in GDB console?
    bool prompt;		// Flag: issue prompt in GDB console?
    bool check;			// Flag: add extra commands to get GDB state?
    int priority;		// Priority (highest get executed first)

private:
    static void clear_origin(Widget w, XtPointer client_data, 
			     XtPointer call_data);
    void add_destroy_callback();
    void remove_destroy_callback();

public:
    Command(const string& cmd, Widget w, OQCProc cb, void *d = 0, 
	    bool v = false, bool c = false, int p = COMMAND_PRIORITY_SYSTEM)
	: command(cmd), origin(w), callback(cb), extra_callback(0), data(d), 
	  echo(v), verbose(v), prompt(v), check(c), priority(p)
    {
	add_destroy_callback();
    }
    Command(const string& cmd, Widget w = 0)
	: command(cmd), origin(w), callback(0), extra_callback(0), data(0), 
	  echo(true), verbose(true), prompt(true), check(true), 
	  priority(COMMAND_PRIORITY_USER)
    {
	add_destroy_callback();
    }
    Command(const Command& c)
	: command(c.command), origin(c.origin), callback(c.callback),
	  extra_callback(c.extra_callback), data(c.data), 
	  echo(c.echo), verbose(c.verbose), prompt(c.prompt),
	  check(c.check), priority(c.priority)
    {
	add_destroy_callback();
    }
    ~Command()
    {
	remove_destroy_callback();
    }
    Command& operator = (const Command& c)
    {
	if (this != &c)
	{
	    remove_destroy_callback();

	    command        = c.command;
	    origin         = c.origin;
	    callback       = c.callback;
	    extra_callback = c.extra_callback;
	    data           = c.data;
	    echo           = c.echo;
	    verbose        = c.verbose;
	    prompt         = c.prompt;
	    check          = c.check;
	    priority       = c.priority;

	    add_destroy_callback();
	}
	return *this;
    }
    bool operator == (const Command& c)
    {
	return this == &c || 
	    command == c.command 
	    && origin == c.origin 
	    && callback == c.callback 
	    && extra_callback == c.extra_callback 
	    && data == c.data
	    && echo == c.echo
	    && verbose == c.verbose
	    && prompt == c.prompt
	    && check == c.check
	    && priority == c.priority;
    }
};


// Enqueue COMMAND in command queue
extern void gdb_command(const Command& command);

// Custom calls
inline void gdb_command(const string& command, Widget origin,
			OQCProc callback, void *data = 0, 
			bool verbose = false, bool check = false,
			int priority = COMMAND_PRIORITY_SYSTEM)
{
    gdb_command(Command(command, origin, callback, data, 
			verbose, check, priority));
}

inline void gdb_command(const string& command, Widget origin = 0)
{
    gdb_command(Command(command, origin));
}

inline void gdb_batch(const string& command, Widget origin,
		      OQCProc callback, void *data = 0,
		      bool verbose = false, bool check = false,
		      int priority = COMMAND_PRIORITY_BATCH)
{
    gdb_command(Command(command, origin, callback, data, 
			verbose, check, priority));
}

inline void gdb_batch(const string& command, Widget origin = 0)
{
    gdb_command(Command(command, origin, OQCProc(0), 0, 
			false, true, COMMAND_PRIORITY_BATCH));
}

// Pass the COMMAND given in CLIENT_DATA to gdb_command()
extern void gdbCommandCB(Widget w, XtPointer call_data, XtPointer client_data);

// Check if command queue is empty
extern bool emptyCommandQueue();

// Clear command queue
extern void clearCommandQueue();

// Synchronize with command queue
extern void syncCommandQueue();

// Return a shell widget according to last command origin
extern Widget find_shell(Widget w = 0);

// Process next element from command queue
extern void processCommandQueue(XtPointer = 0, XtIntervalId *id = 0);

// True if GDB processed any user command (= we had user interaction)
extern bool userInteractionSeen();

// Last user reply to a `y or n' question
extern string lastUserReply();

// Translate frequently used commands
extern void translate_command(string& command);

// Add and strip auto_command prefix
extern void add_auto_command_prefix(string& command);
extern void strip_auto_command_prefix(string& command);

#endif // _DDD_Command_h
// DON'T ADD ANYTHING BEHIND THIS #endif
