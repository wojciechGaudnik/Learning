// $Id: vr.h.in,v 1.11 1999/08/19 11:29:02 andreas Exp $ -*- C++ -*-
// DDD name and version number
// Generated automatically from vr.h.in by configure.

// Copyright (C) 1998 Technische Universitaet Braunschweig, Germany.
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

#ifndef _DDD_version_h
#define _DDD_version_h

// NOTE: This is not the place where names and version numbers are stored!
// To change the name or the version number, see `configure.in'.

// The product name.
#define ddd_NAME     "ddd"
#define Ddd_NAME     "Ddd"
#define DDD_NAME     "DDD"

// The product version, as `MAJOR-NUMBER.MINOR-NUMBER[.PATCHLEVEL]'.
// A version in the form `YYYY-MM-DD' is a release-of-the-day, i.e. a
// snapshot of the current development tree.
#define DDD_VERSION  "3.2.1"

// The product expiration date, in ISO 8601 YYYY-MM-DD format.  After
// this date, users are requested to update the product.  An empty
// expiration date means no expiration.
#define DDD_EXPIRES  ""

// The nickname of this version.
#define DDD_NICKNAME "Liftoff"

#endif // _DDD_version_h
// DON'T ADD ANYTHING BEHIND THIS #endif
