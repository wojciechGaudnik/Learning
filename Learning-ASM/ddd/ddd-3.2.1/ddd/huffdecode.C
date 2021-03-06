// $Id: huffdecode.C,v 1.11 1999/08/19 11:28:39 andreas Exp $ -*- C++ -*-
// Huffman-decode a text encoded with `huffencode'

// Copyright (C) 1996 Technische Universitaet Braunschweig, Germany.
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

static char huffdecode_rcsid[] = 
    "$Id: huffdecode.C,v 1.11 1999/08/19 11:28:39 andreas Exp $";

#ifdef __GNUG__
#pragma implementation
#endif

#include "strclass.h"

struct HuffCode { 
    const HuffCode *left;	// Left child  (0 if leaf)
    const HuffCode *right;	// Right child (value if leaf)
};

#ifdef HUFFTEXT
#include HUFFTEXT
#endif

static void huffdecode(ostream& os)
{
    (void) huffdecode_rcsid;	  // Use it

    int p = 0;			  // Run across hufftext
    int i = 7;			  // Run across bits
    const HuffCode *h = huffcode; // Run around in the code

    int n = 0;

    while (n < hufflength)
    {
	if (h->left == 0)
	{
	    // Arrived at character
	    os << (char)h->right;
	    n++;
	    h = huffcode;
	}

	if (h->left != 0)
	{
	    // Find next position
	    if (((unsigned char)(hufftext[p])) & (1 << i))
		h = h->right;
	    else
		h = h->left;
	}

	if (--i < 0)
	{
	    // Find next bit
	    p++;
	    i = 7;
	}
    }
}

#ifdef MAIN
#include <stdlib.h>

#ifndef EXIT_SUCCESS
#define EXIT_SUCCESS 0
#endif

#ifndef EXIT_FAILURE
#define EXIT_FAILURE 1
#endif

int main()
{
    huffdecode(cout);
    return EXIT_SUCCESS;
}
#endif
