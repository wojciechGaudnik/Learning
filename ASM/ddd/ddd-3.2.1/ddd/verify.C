// $Id: verify.C,v 1.8 1999/08/19 11:29:02 andreas Exp $ -*- C++ -*-
// Verify widget creation

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

char verify_rcsid[] = 
    "$Id: verify.C,v 1.8 1999/08/19 11:29:02 andreas Exp $";

#ifdef __GNUG__
#pragma implementation
#endif

#include <iostream.h>
#include <stdlib.h>

#include "verify.h"

void widget_creation_error()
{
    cerr << "fatal: widget creation failed\n";
    abort();
}
    
