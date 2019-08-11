// $Id: StringBox.h,v 1.13 1999/08/19 11:27:56 andreas Exp $
// A String Box contains a string

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

#ifndef _DDD_StringBox_h
#define _DDD_StringBox_h

#ifdef __GNUG__
#pragma interface
#endif


#include "strclass.h"
#include "Box.h"
#include "PrimitiveB.h"
#include "FontTable.h"


// StringBox

class StringBox: public PrimitiveBox {
public:
    DECLARE_TYPE_INFO

private:
    string _string;
    string _fontname;
    XFontStruct *_font;
    BoxCoordinate _ascent;

    StringBox& operator = (const StringBox&) { assert(0); return *this; }

protected:
    virtual void _draw(Widget w, 
		       const BoxRegion& region, 
		       const BoxRegion& exposed,
		       GC gc, 
		       bool context_selected) const;

    StringBox(const StringBox& box):
	PrimitiveBox(box), _string(box._string), _fontname(box._fontname),
	_font(box._font), _ascent(box._ascent)
    {}

    void dump(ostream& s) const;

    bool matches (const Box &b, const Box * = 0) const
    {
	return PrimitiveBox::matches(b) &&
	    _string == ((StringBox *)&b)->_string;  // dirty trick
    }

public:
    static FontTable* fontTable;    // Font table
    static bool quoted;          // Flag: insert \ before quotes?

    // Constructor
    StringBox(const string& s = "", const string& fontname = "fixed",
	char *t = "StringBox"):
	PrimitiveBox(BoxSize(0,0), BoxExtend(false, false), t),
	_string(s), _fontname(fontname), _font(0), _ascent(0)
    {
	newFont(fontname);
    }

    StringBox(const string& s, XFontStruct *fnt,
	char *t = "StringBox"):
	PrimitiveBox(BoxSize(0,0), BoxExtend(false, false), t),
	_string(s), _fontname("?"), _font(fnt), _ascent(0)
    {
	resize();
    }

    Box *dup() const { return new StringBox(*this); }

    void _newFont(XFontStruct *newfont)
    {
	// If this is a new font, resize
	if (newfont != _font)
	{
	    _font = newfont;
	    resize();
	}
    }

    // Assign a new font
    void newFont(const string& fontname);

    void _print(ostream& os, 
		const BoxRegion& region, 
		const PrintGC& gc) const;

    // Resources
    const XFontStruct *font() const { return _font; }
    const string& fontName() const  { return _fontname; }
    virtual string str() const { return _string; }

    Box *resize();

    bool isStringBox() const { return true; }
};

#endif
