# $Id: yacctoC.bison,v 1.11 1999/08/19 11:29:05 andreas Exp $
# Adapt BISON output for C++ usage

# Copyright (C) 1995-1999 Technische Universitaet Braunschweig, Germany.
# Written by Andreas Zeller <zeller@gnu.org>.
# 
# This file is part of the ICE Library.
# 
# The ICE Library is free software; you can redistribute it and/or
# modify it under the terms of the GNU Library General Public
# License as published by the Free Software Foundation; either
# version 2 of the License, or (at your option) any later version.
# 
# The ICE Library is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
# See the GNU Library General Public License for more details.
# 
# You should have received a copy of the GNU Library General Public
# License along with the ICE Library -- see the file COPYING.LIB.
# If not, write to the Free Software Foundation, Inc.,
# 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
# 
# ICE is the incremental configuration environment.
# For details, see the ICE World-Wide-Web page, 
# `http://www.cs.tu-bs.de/softech/ice/',
# or send a mail to the ICE developers <ice@ips.cs.tu-bs.de>.

# Declare functions
1i\
// This file was modified for -*- C++ -*-\
// using $RCSfile: yacctoC.bison,v $ $Revision: 1.11 $\
extern void yyerror(char *s);\
extern int yylex();\

# Make YYSTYPE a struct such that we can store class objects
# (use anonymous unions to save space!)
s!^typedef union\(.*\)$!typedef struct _YYSTYPE \1!

# We cannot use alloca with class objects.
# Thus, we use new/delete instead (rather ugly).

# Make sure all is deleted when we exit
\!^#define YYERRCODE.*!a\
\
// This deletes the "kill" array upon destruction.\
// Will be used as automatic variable in yyparse().\
// Added by $RCSfile: yacctoC.bison,v $\
struct YYMEMHANDLER {\
    YYSTYPE *kill;\
\
    YYMEMHANDLER():\
	kill(0)\
    {}\
    ~YYMEMHANDLER()\
    {\
	if (kill != 0)\
    	delete[] kill;\
        kill = 0;\
    }\
};\

\!.int yystacksize!a\
  YYMEMHANDLER yymem; // Added by $RCSfile: yacctoC.bison,v $

# stack reallocation -> own code
\!.*yyvs = (YYSTYPE \*!,\!unsigned int!c\
\
      // Added by $RCSfile: yacctoC.bison,v $. \
      YYSTYPE *new_yyvs = new YYSTYPE [yystacksize];\
      if (new_yyvs == 0)\
      {\
          yyerror("parser stack overflow");\
          return 2;\
      }\
      for (int yycopy = 0; yycopy < yystacksize; yycopy++)\
      {\
          new_yyvs[yycopy] = yyvs[yycopy];\
      }\
      delete[] yyvs; yyvs = new_yyvs;\
      yymem.kill = yyvs; // make sure yyvs is deleted upon return \


# malloc/free -> new/delete
s!(\([^)]*\) *\*) *malloc *(\([^)]*\))!new \1[\2]!g
s!free *(\([^)]*\))!delete [] \1!g

# malloc.h -> stdlib.h
s!<malloc\.h>!<stdlib.h>!
