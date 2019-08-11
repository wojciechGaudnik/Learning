// $Id: IntIntAA.h,v 1.7 1999/08/19 11:27:37 andreas Exp $ -*- C++ -*-
// Assoc<int, VarArray<int> > and Assoc<string, VarArray<int> >.

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

#ifndef _DDD_IntIntArrayAssoc_h
#define _DDD_IntIntArrayAssoc_h

#ifdef __GNUG__
#pragma interface
#endif

#include "Assoc.h"
#include "IntArray.h"
#include "strclass.h"

typedef Assoc<int, VarIntArray> IntIntArrayAssoc;
typedef AssocIter<int, VarIntArray> IntIntArrayAssocIter;

typedef Assoc<string, VarIntArray> StringIntArrayAssoc;
typedef AssocIter<string, VarIntArray> StringIntArrayAssocIter;

typedef VarArray<IntArray> IntArrayArray;

typedef Assoc<string, IntArrayArray> StringIntArrayArrayAssoc;
typedef AssocIter<string, IntArrayArray> StringIntArrayArrayAssocIter;

#endif // _DDD_IntIntArrayAssoc_h
// DON'T ADD ANYTHING BEHIND THIS #endif
