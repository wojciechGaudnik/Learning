// $Id: dbx-lookup.C,v 1.37 1999/08/19 11:28:17 andreas Exp $ -*- C++ -*-
// Lookup a DBX function

// Copyright (C) 1996-1998 Technische Universitaet Braunschweig, Germany.
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

char dbx_lookup_rcsid[] = 
    "$Id: dbx-lookup.C,v 1.37 1999/08/19 11:28:17 andreas Exp $";

#ifdef __GNUG__
#pragma implementation
#endif

#include "dbx-lookup.h"

#include "StringSA.h"
#include "cook.h"
#include "ddd.h"
#include "post.h"
#include "misc.h"
#include "question.h"
#include "regexps.h"
#include "index.h"
#include "string-fun.h"
#include "GDBAgent.h"
#include "SourceView.h"

#include <stdlib.h>

//-----------------------------------------------------------------------------
// Lookup location of FUNC using DBX
//-----------------------------------------------------------------------------

static StringStringAssoc pos_cache;

string dbx_lookup(const string& func_name, bool silent)
{
    // Protect against `1' or `' being looked up as function names
    if (!func_name.contains(rxidentifier, 0))
	return "";		// Bad function name

    if (pos_cache.has(func_name))
    {
	string pos = pos_cache[func_name];
	if (silent || pos != "")
	    return pos;
    }

    string reply;
    switch (gdb->type())
    {
    case GDB:
    case DBX:
    case JDB:
    case PYDB:
	reply = gdb_question("list " + func_name, 0, true);
	break;

    case XDB:
	reply = gdb_question("v " + func_name, 0, true);
	break;

    case PERL:
	reply = gdb_question("l " + func_name, 0, true);
	break;
    }

    if (reply == NO_GDB_ANSWER)
    {
	// post_gdb_busy();
	return "";
    }

    string file = "";
    int line    = 0;
    switch (gdb->type())
    {
    case GDB:
    case PYDB:	// XXX
    {
	file = reply.from('\"');
	file = file.before('\"');
	string line_s = reply.after("Line ");
	line = atoi(line_s);
	break;
    }

    case DBX:
	line = line_of_listing(reply, silent);
	if (line > 0)
	{
	    file = gdb_question("file");
	    strip_trailing_space(file);
	}
	break;

    case JDB:
    case PERL:
	line = line_of_listing(reply, silent);
	file = source_view->line_of_cursor();
	file = file.before(':');
	break;

    case XDB:
    {
#if RUNTIME_REGEX
	static regex rxcolons("[^:]*:[^:]*: *[0-9][0-9]*.*");
#endif
	if (reply.matches(rxcolons))
	{
	    file = reply.before(':');
	    reply = reply.after(':'); // Skip file
	    reply = reply.after(':'); // Skip function
	    strip_leading_space(reply);
	    string line_s = reply.before(':');
	    line = atoi(line_s);
	}
	else
	{
	    // post_gdb_message(reply);
	    return "";
	}
	break;
    }
    }

    string pos = "";
    if (line > 0)
	pos = file + ":" + itostring(line);

    pos_cache[func_name] = pos;
    return pos;
}

// Find path of source file SOURCE
string dbx_path(const string& source)
{
    string path;
    if (gdb->has_setenv_command() && gdb->has_edit_command())
    {
	// The DBX `file' command issues only the base name of the
	// current file.  The `edit' command, however, invokes an
	// editor with the entire path.  So, we misuse the `edit'
	// command such that it reports the entire path.
	gdb_question("setenv EDITOR \"echo\"");
	path = gdb_question("edit " + source);
	gdb_question(string("setenv EDITOR ") + 
		     quote(getenv("EDITOR") ? getenv("EDITOR") : "vi"));
    }
    else if (gdb->type() == DBX)
    {
	// We have DBX, but no `setenv' and no `edit' command.  Check
	// whether the `file' command with no arguments provides the
	// full path, as in AIX DBX 3.1.  This shouldn't affect other
	// DBX variants as `file' will simply return the same thing
	// already contained in source.
	gdb_question("file " + source);
	path = gdb_question("file");
    }

    strip_leading_space(path);
    if (!path.contains('/', 0) || path.contains(' '))
	path = source;		// Sanity check

    strip_trailing_space(path);
    return path;
}

void clear_dbx_lookup_cache()
{
    static StringStringAssoc empty;
    pos_cache = empty;
}

int line_of_listing(string& listing, bool silent)
{
    string message;
    while (listing != ""
	   && !listing.contains('>', 0) 
	   && !listing.contains('*', 1) 
	   && atoi(listing) == 0)
    {
	message += listing.through('\n');
	listing = listing.after('\n');
    }

    if (!silent)
	post_gdb_message(message);

    int idx = -1;

    if (idx < 0 && gdb->type() == JDB)
    {
	// JDB issues `=>' in the listed line
	int idx = listing.index("\t=> \t");
	while (idx > 0 && listing[idx - 1] != '\n')
	    idx--;
    }

    if (idx < 0 && gdb->type() == DBX)
    {
	// SGI DBX issues `*' in column 2 before the `list'ed line.
	// Quite useful.
#if RUNTIME_REGEX
	static regex rxnlstar("\n.[*]");
#endif
	int idx = index(listing, rxnlstar, "\n");
	if (idx < 0 && listing.contains('*', 1))
	    idx = 1;
    }

    if (idx < 0 && gdb->type() == DBX)
    {
	// DEC and SGI DBX issue `>' in column 1 before the current
	// execution line.  Quite useful.
	int idx = listing.index("\n>");
	if (idx < 0 && listing.contains('>', 0))
	    idx = 0;
    }

    // Use the first number found.
    int num_idx = listing.index(rxint, max(idx, 0));
    int line = 0;
    if (num_idx >= 0)
	line = atoi(listing.chars() + num_idx);

    if (line == 0)
    {
	// Weird.  No source?
    }
    else if (idx < 0)
    {
	// No indicator found - 
	// the position we are looking for is in the middle
	line += (listing.freq('\n') + 1) / 2 - 1;
    }

    return line;
}
