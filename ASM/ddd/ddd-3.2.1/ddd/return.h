// $Id: return.h,v 1.7 1999/08/19 11:28:50 andreas Exp $ -*- C++ -*-
// Macros for named return values (GNU C++ extension)

// Copyright (C) 1995 Technische Universitaet Braunschweig, Germany.
// Written by Andreas Zeller <zeller@gnu.org>.
// 
// This file is part of the ICE Library.
// 
// The ICE Library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Library General Public
// License as published by the Free Software Foundation; either
// version 2 of the License, or (at your option) any later version.
// 
// The ICE Library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
// See the GNU Library General Public License for more details.
// 
// You should have received a copy of the GNU Library General Public
// License along with the ICE Library -- see the file COPYING.LIB.
// If not, write to the Free Software Foundation, Inc.,
// 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
// 
// ICE is the incremental configuration environment.
// For details, see the ICE World-Wide-Web page, 
// `http://www.cs.tu-bs.de/softech/ice/',
// or send a mail to the ICE developers <ice@ips.cs.tu-bs.de>.

#ifndef _ICE_return_h
#define _ICE_return_h

#include "config.h"

// Use these macros for optional support of GNU C++ named return values
//
// Usage pattern:
//
// string f() RETURNS(x)
// {
//     RETURN_OBJECT(string, x);
//     x = <some value>;
//     RETURN(x);
// }

#if HAVE_NAMED_RETURN_VALUES

#define RETURN(r) return
#define RETURNS(r) return r;
#define RETURN_OBJECT(TYPE, NAME) /* nothing */

#else

#define RETURN(r) return r
#define RETURNS(r) /* nothing */
#define RETURN_OBJECT(TYPE, NAME) TYPE NAME;

#endif

#endif // _ICE_return_h
// DON'T ADD ANYTHING BEHIND THIS #endif
