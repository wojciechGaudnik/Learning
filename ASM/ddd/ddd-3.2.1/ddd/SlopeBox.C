// $Id: SlopeBox.C,v 1.12 1999/08/19 11:27:51 andreas Exp $
// Slope boxes

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

char SlopeBox_rcsid[] = 
    "$Id: SlopeBox.C,v 1.12 1999/08/19 11:27:51 andreas Exp $";

#ifdef __GNUG__
#pragma implementation
#endif

#include "SlopeBox.h"
#include "printBox.h"

#include <X11/Xlib.h>
#include <X11/Intrinsic.h>

DEFINE_TYPE_INFO_1(SlopeBox, LineBox)
DEFINE_TYPE_INFO_1(FallBox, SlopeBox)
DEFINE_TYPE_INFO_1(RiseBox, SlopeBox)


// FallBox

// Draw
void FallBox::__draw(Widget w, 
		     const BoxRegion& r, 
		     const BoxRegion&, 
		     GC gc,
		     bool) const
{
    BoxSize space   = r.space();
    BoxPoint origin = r.origin();

    XDrawLine(XtDisplay(w), XtWindow(w), gc, origin[X], origin[Y],
	origin[X] + space[X], origin[Y] + space[Y]);
}

// Print
void FallBox::_print(ostream& os, 
		     const BoxRegion& region, 
		     const PrintGC& gc) const
{
    BoxPoint origin = region.origin() ;
    BoxPoint space = region.space();

    if (gc.isFig()) {
	os << LINEHEAD1 ;
	os << linethickness() << LINEHEAD2 ;
	os << origin[X] << " " << origin[Y] << " " ;
	os << origin[X] + space[X] << " " ;
	os << origin[Y] + space[Y] << " " ;
	os << "9999 9999\n" ;
    } else if (gc.isPostScript()) {
	os << origin[X] << " " << origin[Y] << " " ;
	os << origin[X] + space[X] << " " ;
	os << origin[Y] + space[Y] << " " ;
	os << linethickness() << " line*\n";
    }
}



void FallBox::dump(ostream& s) const
{
    s << "fall()";
}



// RiseBox

// Draw
void RiseBox::__draw(Widget w, 
		     const BoxRegion& r, 
		     const BoxRegion&, 
		     GC gc,
		     bool) const
{
    BoxSize space   = r.space();
    BoxPoint origin = r.origin();

    XDrawLine(XtDisplay(w), XtWindow(w), gc, origin[X], origin[Y] + space[Y],
	origin[X] + space[X], origin[Y]);
}

// Print
void RiseBox::_print(ostream& os, 
		     const BoxRegion& region, 
		     const PrintGC& gc) const
{
    BoxPoint origin = region.origin();
    BoxPoint space  = region.space();
	
    if (gc.isFig()) {
	os << LINEHEAD1 ;
	os << linethickness() << LINEHEAD2 ;
	os << origin[X] << " " << origin[Y] + space[Y] << " " ;
	os << origin[X] + space[X] << " " << origin[Y] << " " ;
	os << "9999 9999\n" ;
    } else if (gc.isPostScript()) {
	os << origin[X] << " " << origin[Y] + space[Y] << " " ;
	os << origin[X] + space[X] << " " << origin[Y] << " " ;
	os << linethickness() << " line*\n";
    }
}
    
void RiseBox::dump(ostream& s) const
{
    s << "rise()";
}
