// $Id: ExitCB.C,v 1.18 1999/08/19 11:27:27 andreas Exp $
// Exit Callbacks

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

char ExitCB_rcsid[] = 
    "$Id: ExitCB.C,v 1.18 1999/08/19 11:27:27 andreas Exp $";

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>		// perror()
#include <Xm/Xm.h>
#include <Xm/MessageB.h>

#include "findParent.h"
#include "ExitCB.h"
#include "verify.h"

extern char **environ;

// Callbacks

// Leave program
void ExitCB(Widget, XtPointer client_data, XtPointer)
{
    exit((int)(long)client_data);
}

static char **_saved_argv    = 0;
static char **_saved_environ = 0;

// Return environment
char **saved_argv()    { return _saved_argv; }
char **saved_environ() { return _saved_environ; }

// Restart program
void RestartCB(Widget, XtPointer, XtPointer)
{
    environ = saved_environ();
    execvp(saved_argv()[0], saved_argv());

    // Could not restart - just exit
    perror(saved_argv()[0]);
    exit(EXIT_FAILURE);
}

// Save argv
void register_argv(char *argv[])
{
    int argc = 0;
    while (argv[argc] != 0)
	argc++;

    _saved_argv = new char *[argc + 1];
    for (int i = 0; i < argc; i++)
    {
	_saved_argv[i] = new char[strlen(argv[i]) + 1];
	strcpy(_saved_argv[i], argv[i]);
    }
    _saved_argv[argc] = 0;
}

// Save environment
void register_environ()
{
    int envc = 0;
    while (environ[envc] != 0)
	envc++;

    _saved_environ = new char *[envc + 1];
    for (int i = 0; i < envc; i++)
    {
	_saved_environ[i] = new char[strlen(environ[i]) + 1];
	strcpy(_saved_environ[i], environ[i]);
    }
    _saved_environ[envc] = 0;
}
