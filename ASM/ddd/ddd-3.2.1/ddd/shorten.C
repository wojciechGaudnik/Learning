// $Id: shorten.C,v 1.13 1999/08/19 11:28:54 andreas Exp $ -*- C++ -*-
// Shorten an expression

// Copyright (C) 1997 Technische Universitaet Braunschweig, Germany.
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

char shorten_rcsid[] = 
    "$Id: shorten.C,v 1.13 1999/08/19 11:28:54 andreas Exp $";

#ifdef __GNUG__
#pragma implementation
#endif

#include "shorten.h"
#include "cook.h"
#include "regexps.h"
#include "IntArray.h"
#include <ctype.h>

static string shorten_replacement = "...";

// Shorten EXPR such that it is at most MAX_LENGTH characters long.
void shorten(string& expr, unsigned max_length)
{
    // Strip excessive whitespace
    int source = 0;
    int target = 0;
    bool at_space = true;

    while (source < int(expr.length()))
    {
	if (isspace(expr[source]))
	{
	    if (!at_space)
		expr[target++] = ' ';
	    
	    at_space = true;
	    source++;
	}
	else
	{
	    expr[target++] = expr[source++];
	    at_space = false;
	}
    }
    while (target > 0 && target <= int(expr.length()) && 
	   expr[target - 1] == ' ')
    {
	target--;
    }
    expr.from(target) = "";

    // Remove text from the middle
    if (expr.length() > max_length)
    {
	int keep = (max_length - shorten_replacement.length()) / 2;
	expr = expr.through(keep) 
	    + shorten_replacement
	    + expr.from(int(expr.length()) - keep);
    }
}
