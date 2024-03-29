// $Id: events.C,v 1.10 1999/08/19 11:28:31 andreas Exp $
// Event access

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

char events_rcsid[] =
    "$Id: events.C,v 1.10 1999/08/19 11:28:31 andreas Exp $";

#include "events.h"

static void invalid_event(char *func)
{
    cerr << func << ": invalid event\n";
}

// Event location
BoxPoint point(XEvent *ev)
{
    if (ev == 0)
    {
	// LessTif 0.79 and Motif 1.1 sometimes pass NULL as event;
	// provide some reasonable default
	invalid_event("point");
	return BoxPoint();
    }

    switch (ev->type)
    {
	case KeyPress:
	case KeyRelease:
	    return BoxPoint(ev->xkey.x,
			    ev->xkey.y);

	case ButtonPress:
	case ButtonRelease:
	    return BoxPoint(ev->xbutton.x,
			    ev->xbutton.y);

	case MotionNotify:
	    return BoxPoint(ev->xmotion.x,
			    ev->xmotion.y);

	case EnterNotify:
	case LeaveNotify:
	    return BoxPoint(ev->xcrossing.x,
			    ev->xcrossing.y);

	case Expose:
	    return BoxPoint(ev->xexpose.x,
			    ev->xexpose.y);

	case GraphicsExpose:
	    return BoxPoint(ev->xgraphicsexpose.x,
			    ev->xgraphicsexpose.y);

	case CreateNotify:
	    return BoxPoint(ev->xcreatewindow.x,
			    ev->xcreatewindow.y);

	case ReparentNotify:
	    return BoxPoint(ev->xreparent.x,
			    ev->xreparent.y);

	case ConfigureNotify:
	    return BoxPoint(ev->xconfigure.x,
			    ev->xconfigure.y);

	case GravityNotify:
	    return BoxPoint(ev->xgravity.x,
			    ev->xgravity.y);

	case ConfigureRequest:
	    return BoxPoint(ev->xconfigurerequest.x,
			    ev->xconfigurerequest.y);

	default:
	    invalid_event("point");
	    return BoxPoint();
    }
}


// Event time
Time time(XEvent *ev)
{
    if (ev == 0)
    {
	// LessTif 0.79 and Motif 1.1 sometimes pass NULL as event;
	// provide some reasonable default
	invalid_event("time");
	return CurrentTime;
    }

    switch (ev->type)
    {
	case KeyPress:
	case KeyRelease:
	    return ev->xkey.time;

	case ButtonPress:
	case ButtonRelease:
	    return ev->xbutton.time;

	case MotionNotify:
	    return ev->xbutton.time;

	case EnterNotify:
	case LeaveNotify:
	    return ev->xcrossing.time;

	case PropertyNotify:
	    return ev->xproperty.time;

	case SelectionClear:
	    return ev->xselectionclear.time;

	case SelectionRequest:
	    return ev->xselectionrequest.time;

	case SelectionNotify:
	    return ev->xselection.time;

	default:
	    invalid_event("time");
	    return CurrentTime;
    }
}


// Event size
BoxSize size(XEvent *ev)
{
    if (ev == 0)
    {
	// LessTif 0.79 and Motif 1.1 sometimes pass NULL as event;
	// provide some reasonable default
	invalid_event("size");
	return BoxSize(0, 0);
    }

    switch (ev->type)
    {
	case Expose:
	    return BoxSize(ev->xexpose.width,
			   ev->xexpose.height);

	case GraphicsExpose:
	    return BoxSize(ev->xgraphicsexpose.width,
			   ev->xgraphicsexpose.height);

	case CreateNotify:
	    return BoxSize(ev->xcreatewindow.width,
			   ev->xcreatewindow.height);

	case ConfigureNotify:
	    return BoxSize(ev->xconfigure.width,
			   ev->xconfigure.height);

	case ResizeRequest:
	    return BoxSize(ev->xresizerequest.width,
			   ev->xresizerequest.height);

	case ConfigureRequest:
	    return BoxSize(ev->xconfigurerequest.width, 
			   ev->xconfigurerequest.height);

	default:
	    invalid_event("size");
	    return BoxSize(0, 0);
    }
}
