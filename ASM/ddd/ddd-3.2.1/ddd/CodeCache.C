// $Id: CodeCache.C,v 1.10 1999/08/19 11:27:11 andreas Exp $ -*- C++ -*-
// Machine Code Cache

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

char CodeCache_rcsid[] = 
    "$Id: CodeCache.C,v 1.10 1999/08/19 11:27:11 andreas Exp $";

#ifdef __GNUG__
#pragma implementation
#pragma implementation "VarArray.h"
#pragma implementation "DynArray.h"
#endif

#include <Xm/Xm.h>
#include "CodeCache.h"

// Return digit value
inline int xdigit(char c)
{
    switch (c)
    {
    case '0':           return 0;
    case '1':           return 1;
    case '2':           return 2;
    case '3':           return 3;
    case '4':           return 4;
    case '5':           return 5;
    case '6':           return 6;
    case '7':           return 7;
    case '8':           return 8;
    case '9':           return 9;
    case 'a': case 'A': return 10;
    case 'b': case 'B': return 11;
    case 'c': case 'C': return 12;
    case 'd': case 'D': return 13;
    case 'e': case 'E': return 14;
    case 'f': case 'F': return 15;
    default:            return -1;
    }
}

// Compare addresses: 
// return Z such that Z < 0 if X < Y, Z == 0 if X == Y, Z > 0 if X > Y
int compare_address(const string& x, const string& y)
{
    unsigned int px = 0;
    unsigned int py = 0;

    while (px < x.length() && is_leading_zero(x[px]))
	px++;
    while (py < y.length() && is_leading_zero(y[py]))
	py++;

    unsigned int lx = x.length() - px;
    unsigned int ly = y.length() - py;

    while (lx > 0 && is_trailing_zero(x[px + lx - 1]))
	lx--;
    while (ly > 0 && is_trailing_zero(y[py + ly - 1]))
	ly--;

    int ret = lx - ly;
    for (unsigned i = 0; ret == 0 && i < lx; i++)
	ret = xdigit(x[px + i]) - xdigit(y[py + i]);

#if 0
    if (ret < 0)
	clog << x << " < " << y << "\n";
    else if (ret > 0)
	clog << x << " > " << y << "\n";
    else
	clog << x << " = " << y << "\n";
#endif

    return ret;
}
