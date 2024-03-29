# $Id: yacctoC.h,v 1.8 1999/08/19 11:29:05 andreas Exp $
# Adapt BISON/YACC header output for C++ usage

# Copyright (C) 1995 Technische Universitaet Braunschweig, Germany.
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
// using $RCSfile: yacctoC.h,v $ $Revision: 1.8 $\

# Make YYSTYPE a struct such that we can store class objects
# (use anonymous unions to save space!)
s!^typedef union\(.*\)$!typedef struct _YYSTYPE \1!

# Avoid conflicting re-definitions
s!YYSTYPE!IGNORED_&!g
s!yylval!IGNORED_&!g
