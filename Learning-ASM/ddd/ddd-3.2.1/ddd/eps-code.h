// $Id: eps-code.x,v 1.10 1999/08/19 11:28:31 andreas Exp $ -*- C++ -*-

// Copyright (C) 1995 Technische Universitaet Braunschweig, Germany.
// Written by Christian Lindig <lindig@ips.cs.tu-bs.de>.
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

//
// $Id: eps-code.x,v 1.10 1999/08/19 11:28:31 andreas Exp $
//
// This file is only a template for generating eps-code.h!
// Do not edit this file directly!  Edit the *.ps code and
// call make(1).
//

char eps_code_rcsid[] = 
    "$Id: eps-code.x,v 1.10 1999/08/19 11:28:31 andreas Exp $";

static const char prolog[] = 
"% $Id: header.ps,v 1.12 1999/08/19 11:28:38 andreas Exp $\n"
"% Header for DDD PostScript Box output\n"
"\n"
"% Copyright (C) 1995-1998 Technische Universitaet Braunschweig, Germany.\n"
"% Written by Christian Lindig <lindig@ips.cs.tu-bs.de>.\n"
"% \n"
"% This file is part of DDD.\n"
"% \n"
"% DDD is free software; you can redistribute it and/or\n"
"% modify it under the terms of the GNU General Public\n"
"% License as published by the Free Software Foundation; either\n"
"% version 2 of the License, or (at your option) any later version.\n"
"% \n"
"% DDD is distributed in the hope that it will be useful,\n"
"% but WITHOUT ANY WARRANTY; without even the implied warranty of\n"
"% MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.\n"
"% See the GNU General Public License for more details.\n"
"% \n"
"% You should have received a copy of the GNU General Public\n"
"% License along with DDD -- see the file COPYING.\n"
"% If not, write to the Free Software Foundation, Inc.,\n"
"% 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.\n"
"% \n"
"% DDD is the data display debugger.\n"
"% For details, see the DDD World-Wide-Web page, \n"
"% `http://www.gnu.org/software/ddd/',\n"
"% or send a mail to the DDD developers <ddd@gnu.org>.\n"
"\n"
"% Make all definitions local to the ddddict dictionary\n"
"/ddddict 25 dict def \n"
"\n"
"ddddict begin		% make dict active \n"
"\n"
"\n"
"% Global variables\n"
"/fontSize+ 12 def\n"
"/font+ /Courier def  \n"
"\n"
"\n"
"% Some small utilities\n"
"/cm { 28.34646 mul } bind def\n"
"\n"
"\n"
"% ISOLATIN1* - reencode a font to ISO Latin 1 encoding\n"
"%\n"
"% newfont table oldfont isolatin1*\n"
"\n"
"/isolatin1* {\n"
"	findfont\n"
"	dup maxlength dict begin\n"
"	{\n"
"		1 index /FID ne { def } { pop pop } ifelse\n"
"	} forall\n"
"	/Encoding exch def\n"
"	dup /FontName exch def\n"
"	currentdict end definefont pop\n"
"} bind def\n"
"\n"
"\n"
"% Define the ISO Latin 1 encoding of a font\n"
" \n"
"/isotable[\n"
"/.notdef/.notdef/.notdef/.notdef/.notdef/.notdef/.notdef/.notdef/.notdef\n"
"/.notdef/.notdef/.notdef/.notdef/.notdef/.notdef/.notdef/.notdef/.notdef\n"
"/.notdef/.notdef/.notdef/.notdef/.notdef/.notdef/.notdef/.notdef/.notdef\n"
"/.notdef/.notdef/.notdef/.notdef/.notdef/space/exclam/quotedbl/numbersign\n"
"/dollar/percent/ampersand/quoteright/parenleft/parenright/asterisk/plus/comma\n"
"/hyphen/period/slash/zero/one/two/three/four/five/six/seven/eight/nine/colon\n"
"/semicolon/less/equal/greater/question/at/A/B/C/D/E/F/G/H/I/J/K/L/M/N/O/P/Q/R/S\n"
"/T/U/V/W/X/Y/Z/bracketleft/backslash/bracketright/asciicircum/underscore\n"
"/quoteleft/a/b/c/d/e/f/g/h/i/j/k/l/m/n/o/p/q/r/s/t/u/v/w/x/y/z/braceleft/bar\n"
"/braceright/asciitilde/.notdef/.notdef/.notdef/.notdef/.notdef/.notdef/.notdef\n"
"/.notdef/.notdef/.notdef/.notdef/.notdef/.notdef/.notdef/.notdef/.notdef\n"
"/.notdef/dotlessi/grave/acute/circumflex/tilde/macron/breve/dotaccent/dieresis\n"
"/.notdef/ring/cedilla/.notdef/hungarumlaut/ogonek/caron/.notdef/exclamdown/cent\n"
"/sterling/currency/yen/brokenbar/section/dieresis/copyright/ordfeminine\n"
"/guilsinglleft/logicalnot/hyphen/registered/macron/degree/plusminus/twosuperior\n"
"/threesuperior/acute/mu/paragraph/periodcentered/cedilla/onesuperior\n"
"/ordmasculine/guilsinglright/onequarter/onehalf/threequarters/questiondown\n"
"/Agrave/Aacute/Acircumflex/Atilde/Adieresis/Aring/AE/Ccedilla/Egrave/Eacute\n"
"/Ecircumflex/Edieresis/Igrave/Iacute/Icircumflex/Idieresis/Eth/Ntilde/Ograve\n"
"/Oacute/Ocircumflex/Otilde/Odieresis/multiply/Oslash/Ugrave/Uacute/Ucircumflex\n"
"/Udieresis/Yacute/Thorn/germandbls/agrave/aacute/acircumflex/atilde/adieresis\n"
"/aring/ae/ccedilla/egrave/eacute/ecircumflex/edieresis/igrave/iacute\n"
"/icircumflex/idieresis/eth/ntilde/ograve/oacute/ocircumflex/otilde/odieresis\n"
"/divide/oslash/ugrave/uacute/ucircumflex/udieresis/yacute/thorn/ydieresis\n"
"] def\n"
"\n"
"\n"
"% YCORRECT*\n"
"% The reference point of a string ist NOT its lower left corner but \n"
"% its baseline.  Therefore, the y coordinate must be corrected.  \n"
"% Returns the correction for the current font.\n"
"%\n"
"% ycorrect* y\n"
"\n"
"/ycorrect* {\n"
"	currentfont /FontBBox get\n"
"	aload pop pop pop\n"
"	currentfont /FontMatrix get dtransform\n"
"	exch pop\n"
"} def \n"
"\n"
"\n"
"% TEXT*\n"
"% print out a string and make sure not to require more space than\n"
"% specified.\n"
"% font xsize ysize xorigin yorigin (string) text*\n"
"\n"
"/text* {\n"
"\n"
"	/string+ exch def		% set up some variables ..\n"
"	moveto				% move to (xorigin,yorigin)\n"
"	/ysize+ exch def\n"
"	/xsize+ exch def\n"
"	/thefont+ exch def\n"
"\n"
"	% is the right font already selected ?\n"
"\n"
"	thefont+ font+ ne \n"
"	ysize+ fontSize+ ne\n"
"	or {	\n"
"		% set up the right font - reencode it	\n"
"		\n"
"		/Symbol thefont+ eq \n"
"		{\n"
"			thefont+ findfont\n"
"		}{\n"
"\n"
"			/isofont+ isotable thefont+ isolatin1*	\n"
"			/isofont+ findfont\n"
"		}ifelse\n"
"\n"
"		[ysize+ 0 0 ysize+ neg 0 0] makefont\n"
"		setfont\n"
"		\n"
"		/font+ thefont+ def\n"
"		/fontSize+ ysize+ def\n"
"	} if\n"
"\n"
"	% correct current point \n"
"\n"
"	0 ycorrect* neg rmoveto\n"
"\n"
"	% string too long?  Scale it down ...\n"
"	% The actual font is scaled. There is a good chance,\n"
"	% that this will not happen too often when the font is not\n"
"	% changed during the calls of text*\n"
"\n"
"	xsize+ string+ stringwidth pop div dup dup\n"
"	1 lt {\n"
"		0 0 1 0 0 6 array astore currentfont exch \n"
"		makefont setfont\n"
"		pop\n"
"	}{ \n"
"		% string is too short ... scale it up\n"
"\n"
"		1.05 gt {\n"
"			0 0 1 0 0 6 array astore currentfont exch \n"
"			makefont setfont	\n"
"		}{\n"
"			pop\n"
"\n"
"		} ifelse\n"
"	} ifelse\n"
"	\n"
"	string+ show\n"
"\n"
"} bind def\n"
"\n"
"	\n"
"% ARROWLINE*\n"
"% Draw a line of given width with an arrow at its end\n"
"% len gives the height of the triangle forming the head of the arrow\n"
"% and angle the angle at its top\n"
"%	\n"
"% angle len  x1 y1 x2 y2 linewidth arrowline*\n"
"\n"
"/arrowline* {\n"
"	setlinewidth			% angle len x1 y1 x2 y2\n"
"	/y2 exch def\n"
"	/x2 exch def\n"
"	/y1 exch def\n"
"	/x1 exch def\n"
"	/len+ exch def			% height of triangle\n"
"\n"
"	/alpha+ \n"
"		y2 y1 sub		% define alpha+\n"
"		x2 x1 sub\n"
"		atan\n"
"	def\n"
"\n"
"	/base+				% define half of baseline\n"
"		exch \n"
"		2 div dup		% angle angle\n"
"		sin exch cos 	 	% sin(angle) cos(angle)\n"
"		div			% tan(angle)\n"
"		len+\n"
"		mul			% half of baseline\n"
"	def  \n"
"	\n"
"	newpath				% draw the line\n"
"	x1 y1 moveto \n"
"	x2 len+ alpha+ cos mul sub 	% shorten the line to the end  \n"
"	y2 len+ alpha+ sin mul sub 	% of the triangle\n"
"	lineto\n"
"	stroke		\n"
"\n"
"	gsave				% set the origin to the head of\n"
"	0 setlinewidth			% the arrow and rotate the system\n"
"	x2 y2 \n"
"	translate			% origin now at x2 y2\n"
"\n"
"	alpha+ 90 sub rotate 		% rotate the system\n"
"\n"
"	newpath				% draw a triangle\n"
"	0 0 moveto\n"
"	base+ len+ neg rlineto\n"
"	base+ 2 mul neg 0 rlineto\n"
"	closepath\n"
"	fill\n"
"	\n"
"	grestore\n"
"} bind def\n"
"\n"
"% ARROWHEAD*\n"
"% draw an arrow head inclined by alpha at (x,y)\n"
"%\n"
"% angle len alpha x y\n"
"\n"
"/arrowhead* {\n"
"	/y exch def\n"
"	/x exch def\n"
"	/alpha+ exch def\n"
"	/len+ exch def			% height of triangle\n"
"\n"
"	/base+				% define half of baseline\n"
"		exch \n"
"		2 div dup		% angle angle\n"
"		sin exch cos 	 	% sin(angle) cos(angle)\n"
"		div			% tan(angle)\n"
"		len+\n"
"		mul			% half of baseline\n"
"	def\n"
"\n"
"	gsave				% set the origin to the head of\n"
"	0 setlinewidth			% the arrow and rotate the system\n"
"	x y \n"
"	translate			% origin now at x y\n"
"\n"
"	alpha+ 90 sub rotate 		% rotate the system\n"
"\n"
"	newpath				% draw a triangle\n"
"	0 0 moveto\n"
"	base+ len+ neg rlineto\n"
"	base+ 2 mul neg 0 rlineto\n"
"	closepath\n"
"	fill\n"
"	\n"
"	grestore\n"
"} bind def\n"
"\n"
"\n"
"% LINE*\n"
"% draw a line of given width from (x1,y1) to (x2,y2)\n"
"%\n"
"% x1 y1 x2 y2 width line*\n"
"\n"
"/line* {\n"
"	setlinewidth	% x1 y1 x2 y2\n"
"	newpath\n"
"	4 2 roll 	% x2 y2 x1 y1\n"
"	moveto		% x2 y2\n"
"	lineto		\n"
"	stroke\n"
"} bind def\n"
"\n"
"\n"
"% CLEAN*\n"
"%\n"
"% fill a box given by four points with white colour ..\n"
"% x1 y1 x2 y2 x3 y3 x4 y4 clean*\n"
"\n"
"/clean* {\n"
"	gsave\n"
"	1 setgray\n"
"	0 setlinewidth\n"
"	newpath\n"
"	moveto  lineto  lineto lineto\n"
"	closepath\n"
"	fill\n"
"	grestore\n"
"} bind def\n"
"\n"
"\n"
"% BOX*\n"
"% fill a box given by four points\n"
"%\n"
"% x1 y1 x2 y2 x3 y3 x4 y4 box*\n"
"\n"
"/box* {\n"
"	0 setlinewidth\n"
"	newpath\n"
"	moveto 	lineto 	lineto lineto\n"
"	closepath\n"
"	fill\n"
"} bind def\n"
"\n"
"\n"
"% ARC*\n"
"% draw an ellipse with center (cx,cy), radius dx dy, starting at start\n"
"% and ending at end.\n"
"%\n"
"% start end dx dy cx cy width arc*\n"
"\n"
"/arc* {\n"
"	gsave\n"
"	setlinewidth\n"
"	translate\n"
"	newpath\n"
"	dup 3 1 roll		% start end dy dx dy\n"
"	div 1 scale		% dy dx/dy 1 scale => start end dy\n"
"	\n"
"	0 exch  0 exch		% start end 0 0 dy \n"
"	5 -2 roll 		% 0 0 dy start end\n"
"\n"
"	dup\n"
"	0 eq {			% replace 0 by 360\n"
"		pop \n"
"		360\n"
"	} if\n"
"	arc\n"
"	stroke\n"
"	grestore\n"
"} bind def\n"
"\n"
"\n"
"% BEGINCOLOR* / ENDCOLOR*\n"
"% Draw something using a specific foreground color\n"
"%\n"
"% red green blue begincolor* SOMETHING endcolor*\n"
"\n"
"/begincolor* {\n"
"        currentrgbcolor         % red green blue red' green' blue'\n"
"        6 3 roll                % red' green' blue' red green blue\n"
"	setrgbcolor             % red' green' blue'\n"
"} bind def\n"
"\n"
"/endcolor* {\n"
"	setrgbcolor\n"
"} bind def\n"
"\n"
"\n"
"% Set up the right font to the right size\n"
"\n"
"/isofont+ isotable font+ isolatin1* 	% reencode font+\n"
"					% and make it the current font\n"
"/isofont+ findfont\n"
"[fontSize+ 0 0 fontSize+ neg 0 0] makefont\n"
"setfont\n"
"\n"
"\n"
"%%EndProlog\n"
;


static const char trailer[] =
"%%Trailer\n"
"\n"
"% $Id: trailer.ps,v 1.3 1996/08/15 13:17:36 zeller Exp $\n"
"% Trailer for DDD PostScript Box output\n"
"\n"
"grestore\n"
"showpage\n"
"end		% of ddddict \n"
;

