// $Id: VSLDefList.h,v 1.13 1999/08/19 11:28:05 andreas Exp $
// List of VSLDefs

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

#ifndef _DDD_VSLDefList_h
#define _DDD_VSLDefList_h

#ifdef __GNUG__
#pragma interface
#endif


#include "assert.h"
#include <limits.h>
#include <iostream.h>
#include "strclass.h"
#include "bool.h"
#include "TypeInfo.h"

class VSLLib;
class VSLDef;
class VSLNode;

class VSLDefList {
public:
    DECLARE_TYPE_INFO

private:
    string _func_name;      // Function name
    VSLDef *_first;         // first definition for this name
    VSLDef *_last;          // last definition for this name
    unsigned _ndefs;        // Number of definitions
    VSLDefList *_next;      // Next function name
    bool _global;	    // True iff global

public:
    VSLLib *lib;            // Library of this node
    unsigned hashcode;      // Index into has table of library

    int references;         // #occurrences in VSLNode's
    int self_references;    // #occurrences in own defs (-1: unknown)

    // Constructor
    VSLDefList(VSLLib* l, unsigned hash, 
	string func_nm, bool g = false)
	: _func_name(func_nm), _first(0), _last(0), _ndefs(0),
	_next(0), _global(g), lib(l), hashcode(hash), 
	references(0), self_references(-1)
    {}


private:
    VSLDefList(const VSLDefList&)
	: _func_name(), _first(0), _last(0), _ndefs(0),
	_next(0), _global(false), lib(0), hashcode(0), 
	references(0), self_references(0)
    {
	assert(0);
    }

    VSLDefList& operator = (const VSLDefList&) 
    { 
	assert(0); return *this; 
    }

public:
    // Add new function
    VSLDef *add(bool& newFlag,
		VSLNode *pattern, VSLNode *expr = 0,
		string filename = "builtin", int lineno = 0);

    // Get a function def
    VSLDef *def(Box *arglist) const;
    VSLDef *firstdef() const { assert (_ndefs == 1); return _first; }

    // Resources
    string func_name() const { return _func_name; }
    bool &global()        { return _global; }
    bool global() const   { return _global; }

    string f_name() const
    {
	if (_func_name[0] == '#')
	{
	    string tmp = _func_name;
	    return tmp.from(1);
	}
	else
	    return _func_name; 
    }

    VSLDef* first()     { return _first; }
    VSLDefList*& next() { return _next; }
    unsigned ndefs()    { return _ndefs; }

    // Evaluate
    const Box *eval(Box *arg) const;

    // Rename
    void override()     
    { 
	_func_name += '\'';     // Just append a ' to the name
    }

    // Delete defs
    void replace();

    // Destroy
    virtual ~VSLDefList();

    // Representation invariant
    bool OK() const;
};

#endif
