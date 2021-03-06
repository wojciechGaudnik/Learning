"#line 1 \"ddd.vsl\"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"#line 1 \"../vsllib/std.vsl\"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"#line 1 \"../vsllib/builtin.vsl\"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"__op_halign(...);\n"
"__op_valign(...);\n"
"__op_ualign(...);\n"
"__op_talign(...);\n"
"__op_plus(...);\n"
"__op_mult(...);\n"
"__op_cons(...);\n"
"__op_minus(a, b);\n"
"__op_div(a, b);\n"
"__op_mod(a, b);\n"
"__op_eq(a, b);\n"
"__op_ne(a, b);\n"
"__op_gt(a, b);\n"
"__op_ge(a, b);\n"
"__op_lt(a, b);\n"
"__op_le(a, b);\n"
"__op_not(a);\n"
"\n"
"\n"
"__hspace(box);\n"
"__vspace(box);\n"
"__hfix(box);\n"
"__vfix(box);\n"
"__rise(linethickness);\n"
"__fall(linethickness);\n"
"__arc(start, length, linethickness);\n"
"__square(box);\n"
"__tag(box);\n"
"__string(box);\n"
"__font(box, font);\n"
"__fontfix(box);\n"
"__background(box, color);\n"
"__foreground(box, color);\n"
"\n"
"\n"
"__fill();\n"
"__rule();\n"
"__diag();\n"
"\n"
"\n"
"__fail(...);\n"
"__undef();\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"(&)(...) = __op_halign(...);\n"
"(|)(...) = __op_valign(...);\n"
"(^)(...) = __op_ualign(...);\n"
"(~)(...) = __op_talign(...);\n"
"(+)(...) = __op_plus(...);\n"
"(*)(...) = __op_mult(...);\n"
"(::)(...) = __op_cons(...);\n"
"(-)(a, b)  = __op_minus(a, b);\n"
"(/)(a, b)  = __op_div(a, b);\n"
"(%)(a, b)  = __op_mod(a, b);\n"
"(=)(a, b)  = __op_eq(a, b);\n"
"(<>)(a, b) = __op_ne(a, b);\n"
"(>)(a, b)  = __op_gt(a, b);\n"
"(>=)(a, b) = __op_ge(a, b);\n"
"(<)(a, b)  = __op_lt(a, b);\n"
"(<=)(a, b) = __op_le(a, b);\n"
"(not)(a) = __op_not(a);\n"
"\n"
"\n"
"hspace(box) = __hspace(box);\n"
"vspace(box) = __vspace(box);\n"
"hfix(box) = __hfix(box);\n"
"vfix(box) = __vfix(box);\n"
"rise(linethickness) = __rise(linethickness);\n"
"fall(linethickness) = __fall(linethickness);\n"
"arc(start, length, linethickness) = __arc(start, length, linethickness);\n"
"square(box) = __square(box);\n"
"tag(box) = __tag(box);\n"
"string(box) = __string(box);\n"
"font(box, font)                   = __font(box, font);\n"
"fontfix(box) = __fontfix(box);\n"
"background(box, color)            = __background(box, color);\n"
"foreground(box, color)            = __foreground(box, color);\n"
"fill() = __fill();\n"
"rule() = __rule();\n"
"diag() = __diag();\n"
"fail() = __fail();\n"
"fail(message) = __fail(message);\n"
"undef() = __undef();\n"
"#line 29 \"../vsllib/std.vsl\"\n"
"\n"
"\n"
"\n"
"std_version() = \"$Id: std.vsl,v 1.7 1999/08/19 11:30:21 andreas Exp $\";\n"
"\n"
"\n"
"rulethickness() = 1;\n"
"whitethickness() = 2;\n"
"indentamount() = hspace(\"  \");\n"
"true = 1;\n"
"false = 0;\n"
"\n"
"\n"
"\n"
"\n"
"max(a) = a;\n"
"max(a, b, ...) = if a > b then max(a, ...) else max(b, ...) fi;\n"
"min(a) = a;\n"
"min(a, b, ...) = if a < b then min(a, ...) else min(b, ...) fi;\n"
"\n"
"\n"
"hfill() = vfix(fill());\n"
"vfill() = hfix(fill());\n"
"\n"
"\n"
"hnull() = vfill();\n"
"vnull() = hfill();\n"
"\n"
"\n"
"hrule(thickness) = rule() & vspace(thickness);\n"
"vrule(thickness) = rule() | hspace(thickness);\n"
"hwhite(thickness) = fill() & vspace(thickness);\n"
"vwhite(thickness) = fill() | hspace(thickness);\n"
"\n"
"hrule() = hrule(rulethickness());\n"
"vrule() = vrule(rulethickness());\n"
"hwhite() = hwhite(whitethickness());\n"
"vwhite() = vwhite(whitethickness());\n"
"\n"
"\n"
"fix(a) = hfix(vfix(a));\n"
"space(a) = hspace(a) + vspace(a);\n"
"\n"
"\n"
"box(x) = x;\n"
"box(x,y) = hspace(x) + vspace(y);\n"
"\n"
"\n"
"halign(...) = (&)(...);\n"
"valign(...) = (|)(...);\n"
"talign(...) = (~)(...);\n"
"\n"
"\n"
"hralign() = hnull();\n"
"hralign(head) = head;\n"
"hralign(head, ...) = hralign(...) & head;\n"
"tralign() = hnull();\n"
"tralign(head) = head;\n"
"tralign(head, ...) = tralign(...) ~ head;\n"
"vralign() = vnull();\n"
"vralign(head) = head;\n"
"vralign(head, ...) = vralign(...) | head;\n"
"\n"
"\n"
"hlist(_) = hnull();\n"
"hlist(_, head) = head;\n"
"hlist(sep, head, ...) = head & sep & hlist(sep, ...);\n"
"\n"
"tlist(_) = hnull();\n"
"tlist(_, head) = head;\n"
"tlist(sep, head, ...) = head ~ sep ~ tlist(sep, ...);\n"
"\n"
"vlist(_) = vnull();\n"
"vlist(_, head) = head;\n"
"vlist(sep, head, ...) = head | sep | vlist(sep, ...);\n"
"\n"
"hvlist(_) = vnull();\n"
"hvlist(sep, head) = head & sep;\n"
"hvlist(sep, head, ...) = head & sep | hvlist(sep, ...);\n"
"\n"
"tvlist(_) = vnull();\n"
"tvlist(sep, head) = head ~ sep;\n"
"tvlist(sep, head, ...) = head ~ sep | tvlist(sep, ...);\n"
"\n"
"vhlist(_) = vnull();\n"
"vhlist(sep, head) = head | sep;\n"
"vhlist(sep, head, ...) = (head | sep) & vhlist(sep, ...);\n"
"\n"
"vtlist(_) = vnull();\n"
"vtlist(sep, head) = head | sep;\n"
"vtlist(sep, head, ...) = (head | sep) ~ vtlist(sep, ...);\n"
"\n"
"commalist(...) = tlist(\", \", ...);\n"
"semicolonlist(...) = tlist(\"; \", ...);\n"
"\n"
"\n"
"heven(box, align) = box ^ hspace(box + box % align);\n"
"veven(box, align) = box ^ vspace(box + box % align);\n"
"even(box, align) = heven(veven(box, align), align);\n"
"heven(box) = heven(box, 2);\n"
"veven(box) = veven(box, 2);\n"
"even(box) = heven(veven(box));\n"
"\n"
"\n"
"\n"
"num(a);\n"
"digit(0) = \"0\";\n"
"digit(1) = \"1\";\n"
"digit(2) = \"2\";\n"
"digit(3) = \"3\";\n"
"digit(4) = \"4\";\n"
"digit(5) = \"5\";\n"
"digit(6) = \"6\";\n"
"digit(7) = \"7\";\n"
"digit(8) = \"8\";\n"
"digit(9) = \"9\";\n"
"digit(10) = \"a\";\n"
"digit(11) = \"b\";\n"
"digit(12) = \"c\";\n"
"digit(13) = \"d\";\n"
"digit(14) = \"e\";\n"
"digit(15) = \"f\";\n"
"digit(_) = fail(\"invalid digit() argument\");\n"
"\n"
"\n"
"\n"
"pnum(a, base) =\n"
"if a < base then\n"
"digit(a)\n"
"else\n"
"pnum(a / base, base) & pnum(a % base, base)\n"
"fi;\n"
"\n"
"\n"
"num(a, base) =\n"
"if a < 0 then \"-\" & pnum(0 - a, base) else pnum(a, base) fi;\n"
"num(a) = num(a, 10);\n"
"\n"
"\n"
"dec(a) = num(a, 10);\n"
"oct(a) = num(a, 8);\n"
"bin(a) = num(a, 2);\n"
"hex(a) = num(a, 16);\n"
"\n"
"\n"
"n_rule() = hrule() | hwhite();\n"
"w_rule() = vrule() & vwhite();\n"
"s_rule() = hwhite() | hrule();\n"
"e_rule() = vwhite() & vrule();\n"
"\n"
"\n"
"whiteframe(box, thickness) =\n"
"hwhite(thickness)\n"
"| vwhite(thickness) & box & vwhite(thickness)\n"
"| hwhite(thickness);\n"
"whiteframe(box) = whiteframe(box, whitethickness());\n"
"\n"
"ruleframe(box, thickness) =\n"
"hrule(thickness)\n"
"| vrule(thickness) & box & vrule(thickness)\n"
"| hrule(thickness);\n"
"ruleframe(box) = ruleframe(box, rulethickness());\n"
"\n"
"frame(box) = ruleframe(whiteframe(box));\n"
"doubleframe(box) = frame(frame(box));\n"
"thickframe(box) = ruleframe(frame(box));\n"
"\n"
"\n"
"hcenter(box) = fill() & box & fill();\n"
"vcenter(box) = fill() | box | fill();\n"
"center(box) = hcenter(vcenter(box));\n"
"\n"
"\n"
"n_flush(box) = hcenter(box) | fill();\n"
"s_flush(box) = fill() | hcenter(box);\n"
"w_flush(box) = vcenter(box) & fill();\n"
"e_flush(box) = fill() & vcenter(box);\n"
"sw_flush(box) = fill() | (box & fill());\n"
"nw_flush(box) = (box & fill()) | fill();\n"
"se_flush(box) = fill() | (fill() & box);\n"
"ne_flush(box) = (fill() & box) | fill();\n"
"\n"
"\n"
"indent(box) = indentamount() & box;\n"
"\n"
"\n"
"underline(box) = box | hrule();\n"
"overline(box) = hrule() | box;\n"
"crossline(box) = hfix(box ^ vcenter(hrule()));\n"
"\n"
"\n"
"doublestrike(box) = box ^ (hspace(1) & box);\n"
"\n"
"\n"
"dquote() = \"\\\"\";\n"
"squote() = \"'\";\n"
"copyright() = \"(c)\";\n"
"#line 31 \"ddd.vsl\"\n"
"\n"
"#line 1 \"../vsllib/tab.vsl\"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"#line 1 \"../vsllib/std.vsl\"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"#line 1 \"../vsllib/builtin.vsl\"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"__op_halign(...);\n"
"__op_valign(...);\n"
"__op_ualign(...);\n"
"__op_talign(...);\n"
"__op_plus(...);\n"
"__op_mult(...);\n"
"__op_cons(...);\n"
"__op_minus(a, b);\n"
"__op_div(a, b);\n"
"__op_mod(a, b);\n"
"__op_eq(a, b);\n"
"__op_ne(a, b);\n"
"__op_gt(a, b);\n"
"__op_ge(a, b);\n"
"__op_lt(a, b);\n"
"__op_le(a, b);\n"
"__op_not(a);\n"
"\n"
"\n"
"__hspace(box);\n"
"__vspace(box);\n"
"__hfix(box);\n"
"__vfix(box);\n"
"__rise(linethickness);\n"
"__fall(linethickness);\n"
"__arc(start, length, linethickness);\n"
"__square(box);\n"
"__tag(box);\n"
"__string(box);\n"
"__font(box, font);\n"
"__fontfix(box);\n"
"__background(box, color);\n"
"__foreground(box, color);\n"
"\n"
"\n"
"__fill();\n"
"__rule();\n"
"__diag();\n"
"\n"
"\n"
"__fail(...);\n"
"__undef();\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"(&)(...) = __op_halign(...);\n"
"(|)(...) = __op_valign(...);\n"
"(^)(...) = __op_ualign(...);\n"
"(~)(...) = __op_talign(...);\n"
"(+)(...) = __op_plus(...);\n"
"(*)(...) = __op_mult(...);\n"
"(::)(...) = __op_cons(...);\n"
"(-)(a, b)  = __op_minus(a, b);\n"
"(/)(a, b)  = __op_div(a, b);\n"
"(%)(a, b)  = __op_mod(a, b);\n"
"(=)(a, b)  = __op_eq(a, b);\n"
"(<>)(a, b) = __op_ne(a, b);\n"
"(>)(a, b)  = __op_gt(a, b);\n"
"(>=)(a, b) = __op_ge(a, b);\n"
"(<)(a, b)  = __op_lt(a, b);\n"
"(<=)(a, b) = __op_le(a, b);\n"
"(not)(a) = __op_not(a);\n"
"\n"
"\n"
"hspace(box) = __hspace(box);\n"
"vspace(box) = __vspace(box);\n"
"hfix(box) = __hfix(box);\n"
"vfix(box) = __vfix(box);\n"
"rise(linethickness) = __rise(linethickness);\n"
"fall(linethickness) = __fall(linethickness);\n"
"arc(start, length, linethickness) = __arc(start, length, linethickness);\n"
"square(box) = __square(box);\n"
"tag(box) = __tag(box);\n"
"string(box) = __string(box);\n"
"font(box, font)                   = __font(box, font);\n"
"fontfix(box) = __fontfix(box);\n"
"background(box, color)            = __background(box, color);\n"
"foreground(box, color)            = __foreground(box, color);\n"
"fill() = __fill();\n"
"rule() = __rule();\n"
"diag() = __diag();\n"
"fail() = __fail();\n"
"fail(message) = __fail(message);\n"
"undef() = __undef();\n"
"#line 29 \"../vsllib/std.vsl\"\n"
"\n"
"\n"
"\n"
"std_version() = \"$Id: std.vsl,v 1.7 1999/08/19 11:30:21 andreas Exp $\";\n"
"\n"
"\n"
"rulethickness() = 1;\n"
"whitethickness() = 2;\n"
"indentamount() = hspace(\"  \");\n"
"true = 1;\n"
"false = 0;\n"
"\n"
"\n"
"\n"
"\n"
"max(a) = a;\n"
"max(a, b, ...) = if a > b then max(a, ...) else max(b, ...) fi;\n"
"min(a) = a;\n"
"min(a, b, ...) = if a < b then min(a, ...) else min(b, ...) fi;\n"
"\n"
"\n"
"hfill() = vfix(fill());\n"
"vfill() = hfix(fill());\n"
"\n"
"\n"
"hnull() = vfill();\n"
"vnull() = hfill();\n"
"\n"
"\n"
"hrule(thickness) = rule() & vspace(thickness);\n"
"vrule(thickness) = rule() | hspace(thickness);\n"
"hwhite(thickness) = fill() & vspace(thickness);\n"
"vwhite(thickness) = fill() | hspace(thickness);\n"
"\n"
"hrule() = hrule(rulethickness());\n"
"vrule() = vrule(rulethickness());\n"
"hwhite() = hwhite(whitethickness());\n"
"vwhite() = vwhite(whitethickness());\n"
"\n"
"\n"
"fix(a) = hfix(vfix(a));\n"
"space(a) = hspace(a) + vspace(a);\n"
"\n"
"\n"
"box(x) = x;\n"
"box(x,y) = hspace(x) + vspace(y);\n"
"\n"
"\n"
"halign(...) = (&)(...);\n"
"valign(...) = (|)(...);\n"
"talign(...) = (~)(...);\n"
"\n"
"\n"
"hralign() = hnull();\n"
"hralign(head) = head;\n"
"hralign(head, ...) = hralign(...) & head;\n"
"tralign() = hnull();\n"
"tralign(head) = head;\n"
"tralign(head, ...) = tralign(...) ~ head;\n"
"vralign() = vnull();\n"
"vralign(head) = head;\n"
"vralign(head, ...) = vralign(...) | head;\n"
"\n"
"\n"
"hlist(_) = hnull();\n"
"hlist(_, head) = head;\n"
"hlist(sep, head, ...) = head & sep & hlist(sep, ...);\n"
"\n"
"tlist(_) = hnull();\n"
"tlist(_, head) = head;\n"
"tlist(sep, head, ...) = head ~ sep ~ tlist(sep, ...);\n"
"\n"
"vlist(_) = vnull();\n"
"vlist(_, head) = head;\n"
"vlist(sep, head, ...) = head | sep | vlist(sep, ...);\n"
"\n"
"hvlist(_) = vnull();\n"
"hvlist(sep, head) = head & sep;\n"
"hvlist(sep, head, ...) = head & sep | hvlist(sep, ...);\n"
"\n"
"tvlist(_) = vnull();\n"
"tvlist(sep, head) = head ~ sep;\n"
"tvlist(sep, head, ...) = head ~ sep | tvlist(sep, ...);\n"
"\n"
"vhlist(_) = vnull();\n"
"vhlist(sep, head) = head | sep;\n"
"vhlist(sep, head, ...) = (head | sep) & vhlist(sep, ...);\n"
"\n"
"vtlist(_) = vnull();\n"
"vtlist(sep, head) = head | sep;\n"
"vtlist(sep, head, ...) = (head | sep) ~ vtlist(sep, ...);\n"
"\n"
"commalist(...) = tlist(\", \", ...);\n"
"semicolonlist(...) = tlist(\"; \", ...);\n"
"\n"
"\n"
"heven(box, align) = box ^ hspace(box + box % align);\n"
"veven(box, align) = box ^ vspace(box + box % align);\n"
"even(box, align) = heven(veven(box, align), align);\n"
"heven(box) = heven(box, 2);\n"
"veven(box) = veven(box, 2);\n"
"even(box) = heven(veven(box));\n"
"\n"
"\n"
"\n"
"num(a);\n"
"digit(0) = \"0\";\n"
"digit(1) = \"1\";\n"
"digit(2) = \"2\";\n"
"digit(3) = \"3\";\n"
"digit(4) = \"4\";\n"
"digit(5) = \"5\";\n"
"digit(6) = \"6\";\n"
"digit(7) = \"7\";\n"
"digit(8) = \"8\";\n"
"digit(9) = \"9\";\n"
"digit(10) = \"a\";\n"
"digit(11) = \"b\";\n"
"digit(12) = \"c\";\n"
"digit(13) = \"d\";\n"
"digit(14) = \"e\";\n"
"digit(15) = \"f\";\n"
"digit(_) = fail(\"invalid digit() argument\");\n"
"\n"
"\n"
"\n"
"pnum(a, base) =\n"
"if a < base then\n"
"digit(a)\n"
"else\n"
"pnum(a / base, base) & pnum(a % base, base)\n"
"fi;\n"
"\n"
"\n"
"num(a, base) =\n"
"if a < 0 then \"-\" & pnum(0 - a, base) else pnum(a, base) fi;\n"
"num(a) = num(a, 10);\n"
"\n"
"\n"
"dec(a) = num(a, 10);\n"
"oct(a) = num(a, 8);\n"
"bin(a) = num(a, 2);\n"
"hex(a) = num(a, 16);\n"
"\n"
"\n"
"n_rule() = hrule() | hwhite();\n"
"w_rule() = vrule() & vwhite();\n"
"s_rule() = hwhite() | hrule();\n"
"e_rule() = vwhite() & vrule();\n"
"\n"
"\n"
"whiteframe(box, thickness) =\n"
"hwhite(thickness)\n"
"| vwhite(thickness) & box & vwhite(thickness)\n"
"| hwhite(thickness);\n"
"whiteframe(box) = whiteframe(box, whitethickness());\n"
"\n"
"ruleframe(box, thickness) =\n"
"hrule(thickness)\n"
"| vrule(thickness) & box & vrule(thickness)\n"
"| hrule(thickness);\n"
"ruleframe(box) = ruleframe(box, rulethickness());\n"
"\n"
"frame(box) = ruleframe(whiteframe(box));\n"
"doubleframe(box) = frame(frame(box));\n"
"thickframe(box) = ruleframe(frame(box));\n"
"\n"
"\n"
"hcenter(box) = fill() & box & fill();\n"
"vcenter(box) = fill() | box | fill();\n"
"center(box) = hcenter(vcenter(box));\n"
"\n"
"\n"
"n_flush(box) = hcenter(box) | fill();\n"
"s_flush(box) = fill() | hcenter(box);\n"
"w_flush(box) = vcenter(box) & fill();\n"
"e_flush(box) = fill() & vcenter(box);\n"
"sw_flush(box) = fill() | (box & fill());\n"
"nw_flush(box) = (box & fill()) | fill();\n"
"se_flush(box) = fill() | (fill() & box);\n"
"ne_flush(box) = (fill() & box) | fill();\n"
"\n"
"\n"
"indent(box) = indentamount() & box;\n"
"\n"
"\n"
"underline(box) = box | hrule();\n"
"overline(box) = hrule() | box;\n"
"crossline(box) = hfix(box ^ vcenter(hrule()));\n"
"\n"
"\n"
"doublestrike(box) = box ^ (hspace(1) & box);\n"
"\n"
"\n"
"dquote() = \"\\\"\";\n"
"squote() = \"'\";\n"
"copyright() = \"(c)\";\n"
"#line 29 \"../vsllib/tab.vsl\"\n"
"\n"
"\n"
"\n"
"tab_version() = \"$Id: tab.vsl,v 1.9 1999/08/19 11:30:21 andreas Exp $\";\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"tab_elem([]) = tab_elem(0);\n"
"tab_elem(x) = whiteframe(x);\n"
"\n"
"\n"
"\n"
"\n"
"_tab_maxhspace([...]) = hspace(valign(...));\n"
"_tab_maxvspace([...]) = vspace(halign(...));\n"
"\n"
"\n"
"_tab_allempty([[]]) = true;\n"
"_tab_allempty([[] : more]) = _tab_allempty(more);\n"
"_tab_allempty([_...]) = false;\n"
"\n"
"\n"
"_tab_heads([]) = [];\n"
"_tab_heads([[head : _] : more]) =\n"
"[tab_elem(head) : _tab_heads(more)];\n"
"_tab_heads([x]) = [tab_elem(x)];\n"
"\n"
"\n"
"_tab_tails([]) = [];\n"
"_tab_tails([[_ : tail] : more]) =\n"
"[tail : _tab_tails(more)];\n"
"_tab_tails(_) = [];\n"
"\n"
"\n"
"_tab_width(...) =\n"
"if _tab_allempty(...)\n"
"then []\n"
"else [ _tab_maxhspace(_tab_heads(...)) : _tab_width(_tab_tails(...)) ]\n"
"fi;\n"
"\n"
"\n"
"_tab_line([width], [head]) =\n"
"width | tab_elem(head);\n"
"_tab_line([width : twidth], [head : tail]) =\n"
"_tab_line([width], [head]) & _tab_line(twidth, tail);\n"
"_tab_line([width], x) =\n"
"_tab_line([width], [x]);\n"
"_tab_line([width : twidth], x) =\n"
"_tab_line([width], [x]) & _tab_line(twidth, 0);\n"
"\n"
"\n"
"_dtab_line([width], [head]) =\n"
"width | tab_elem(head);\n"
"_dtab_line([width : twidth], [head : tail]) =\n"
"_dtab_line([width], [head]) & vrule() & _dtab_line(twidth, tail);\n"
"_dtab_line([width], x) =\n"
"_tab_line([width], [x]);\n"
"_dtab_line([width : twidth], x) =\n"
"_tab_line([width], [x]) & vwhite(rulethickness()) & _dtab_line(twidth, 0);\n"
"\n"
"\n"
"_tab(width, [head]) =\n"
"_tab_line(width, head);\n"
"_tab(width, [head : tail]) =\n"
"_tab_line(width, head)\n"
"| _tab(width, tail);\n"
"\n"
"\n"
"_dtab(width, [head]) =\n"
"vrule() & _dtab_line(width, head) & vrule();\n"
"_dtab(width, [head : tail]) =\n"
"vrule() & _dtab_line(width, head) & vrule()\n"
"| hrule()\n"
"| _dtab(width, tail);\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"tab(...) =\n"
"_tab(_tab_width(...), ...);\n"
"\n"
"\n"
"dtab(...) =\n"
"hrule()\n"
"| _dtab(_tab_width(...), ...)\n"
"| hrule();\n"
"#line 32 \"ddd.vsl\"\n"
"\n"
"#line 1 \"../vsllib/fonts.vsl\"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"fonts_version() = \"$Id: fonts.vsl,v 1.11 1999/08/19 11:30:20 andreas Exp $\";\n"
"\n"
"\n"
"_font(box, font) = font(box, font);\n"
"_fontfix(box) = fontfix(box);\n"
"\n"
"\n"
"#pragma override font\n"
"font(box, font) = _fontfix(_font(box, string(font)));\n"
"\n"
"\n"
"slant_unslanted() = \"r\";\n"
"slant_italic() = \"*\";\n"
"weight_medium() = \"medium\";\n"
"weight_bold() = \"bold\";\n"
"family_times() = \"times\";\n"
"family_courier() = \"courier\";\n"
"family_helvetica() = \"helvetica\";\n"
"family_new_century() = \"new century schoolbook\";\n"
"family_typewriter() = \"lucidatypewriter\";\n"
"\n"
"\n"
"stdfontfamily() = family_times();\n"
"stdfontsize() = 0;\n"
"stdfontpoints() = 90;\n"
"stdfontslant() = slant_unslanted();\n"
"stdfontweight() = weight_medium();\n"
"\n"
"\n"
"fontnum(n) = if n > 0 then num(n) else \"*\" fi;\n"
"\n"
"\n"
"\n"
"sysfontname(fndry, family, weight, slant, sWdth, adstyl, pxlsz, ptSz,\n"
"resx, resy, spc, avgWdth, rgstry, encdng) = string(\n"
"\"-\" & fndry &\n"
"\"-\" & family &\n"
"\"-\" & weight &\n"
"\"-\" & slant &\n"
"\"-\" & sWdth &\n"
"\"-\" & adstyl &\n"
"\"-\" & pxlsz &\n"
"\"-\" & ptSz &\n"
"\"-\" & resx &\n"
"\"-\" & resy &\n"
"\"-\" & spc &\n"
"\"-\" & avgWdth &\n"
"\"-\" & rgstry &\n"
"\"-\" & encdng);\n"
"\n"
"\n"
"fontname(weight, slant, family, pixels, points) = string(\n"
"\"-\" & \"*\" &\n"
"\"-\" & family &\n"
"\"-\" & weight &\n"
"\"-\" & slant &\n"
"\"-\" & \"*\" &\n"
"\"-\" & \"*\" &\n"
"\"-\" & fontnum(pixels) &\n"
"\"-\" & fontnum(points) &\n"
"\"-\" & \"*\" &\n"
"\"-\" & \"*\" &\n"
"\"-\" & \"*\" &\n"
"\"-\" & \"*\" &\n"
"\"-\" & \"*\" &\n"
"\"-\" & \"*\");\n"
"\n"
"\n"
"fontname(weight, slant, family, size) =\n"
"fontname(weight, slant, family, size, stdfontpoints());\n"
"fontname(weight, slant, family) =\n"
"fontname(weight, slant, family, stdfontsize());\n"
"fontname(weight, slant) =\n"
"fontname(weight, slant, stdfontfamily());\n"
"fontname(weight) =\n"
"fontname(weight, stdfontslant());\n"
"fontname() =\n"
"fontname(stdfontweight());\n"
"\n"
"\n"
"\n"
"fontname_rm() =\n"
"fontname(weight_medium(), slant_unslanted());\n"
"fontname_bf() =\n"
"fontname(weight_bold(), slant_unslanted());\n"
"fontname_it() =\n"
"fontname(weight_medium(), slant_italic());\n"
"fontname_bi() =\n"
"fontname(weight_bold(), slant_italic());\n"
"\n"
"fontname_rm(family) =\n"
"fontname(weight_medium(), slant_unslanted(), family);\n"
"fontname_bf(family) =\n"
"fontname(weight_bold(), slant_unslanted(), family);\n"
"fontname_it(family) =\n"
"fontname(weight_medium(), slant_italic(), family);\n"
"fontname_bi(family) =\n"
"fontname(weight_bold(), slant_italic(), family);\n"
"\n"
"fontname_rm(family, size) =\n"
"fontname(weight_medium(), slant_unslanted(), family, size);\n"
"fontname_bf(family, size) =\n"
"fontname(weight_bold(), slant_unslanted(), family, size);\n"
"fontname_it(family, size) =\n"
"fontname(weight_medium(), slant_italic(), family, size);\n"
"fontname_bi(family, size) =\n"
"fontname(weight_bold(), slant_italic(), family, size);\n"
"\n"
"\n"
"\n"
"rm(box) = font(box, fontname_rm());\n"
"bf(box) = font(box, fontname_bf());\n"
"it(box) = font(box, fontname_it());\n"
"bi(box) = font(box, fontname_bi());\n"
"\n"
"rm(box, family) = font(box, fontname_rm(family));\n"
"bf(box, family) = font(box, fontname_bf(family));\n"
"it(box, family) = font(box, fontname_it(family));\n"
"bi(box, family) = font(box, fontname_bi(family));\n"
"\n"
"rm(box, family, size) = font(box, fontname_rm(family, size));\n"
"bf(box, family, size) = font(box, fontname_bf(family, size));\n"
"it(box, family, size) = font(box, fontname_it(family, size));\n"
"bi(box, family, size) = font(box, fontname_bi(family, size));\n"
"\n"
"\n"
"\n"
"sl(...) = it(...);\n"
"bs(...) = bi(...);\n"
"#line 33 \"ddd.vsl\"\n"
"\n"
"#line 1 \"../vsllib/colors.vsl\"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"colors_version() = \"$Id: colors.vsl,v 1.5 1999/08/19 11:30:19 andreas Exp $\";\n"
"\n"
"\n"
"color(box, fg, bg)   = foreground(background(box, bg), fg);\n"
"color(box, fg)       = foreground(box, fg);\n"
"#line 34 \"ddd.vsl\"\n"
"\n"
"\n"
"\n"
"#pragma replace stdfontfamily\n"
"stdfontfamily() = family_typewriter();\n"
"small(...) = rm(...);\n"
"\n"
"\n"
"display_color(box) = color(box, \"black\", \"white\");\n"
"title_color(box) = color(box, \"black\");\n"
"disabled_color(box) = color(box, \"white\", \"grey50\");\n"
"simple_color(box) = color(box, \"black\");\n"
"text_color(box) = color(box, \"black\");\n"
"pointer_color(box) = color(box, \"blue4\");\n"
"struct_color(box) = color(box, \"black\");\n"
"list_color(box) = color(box, \"black\");\n"
"array_color(box) = color(box, \"blue4\");\n"
"reference_color(box) = color(box, \"blue4\");\n"
"changed_color(box) = color(box, \"black\", \"#ffffcc\");\n"
"shadow_color(box) = color(box, \"grey\");\n"
"\n"
"\n"
"shadow(box, thickness) =\n"
"box & (square(thickness) | shadow_color(vrule(thickness)))\n"
"| square(thickness) & shadow_color(hrule(thickness));\n"
"shadow(box) = shadow(box, 1);\n"
"\n"
"\n"
"fixed_hlist(_) = hnull();\n"
"fixed_hlist(_, head) = hfix(head);\n"
"fixed_hlist(sep, head, ...) = hfix(head) & sep & fixed_hlist(sep, ...);\n"
"\n"
"fixed_vlist(_) = vnull();\n"
"fixed_vlist(_, head) = vfix(head);\n"
"fixed_vlist(sep, head, ...) = vfix(head) | sep | fixed_vlist(sep, ...);\n"
"\n"
"\n"
"title (disp_nr, name) ->\n"
"title_color(rm(disp_nr & \": \") & bf(name) & hfill());\n"
"title (name) ->\n"
"title_color(bf(name) & hfill());\n"
"\n"
"\n"
"annotation (name) ->\n"
"small(name);\n"
"\n"
"\n"
"disabled () ->\n"
"disabled_color(vcenter(it(\"(Disabled)\") & hfill()));\n"
"\n"
"\n"
"none () -> \"\";\n"
"\n"
"\n"
"simple_value (value) ->\n"
"simple_color(vcenter(value & hfill()));\n"
"numeric_value (value) ->\n"
"simple_color(vcenter(hfill() & value));\n"
"\n"
"\n"
"collapsed_simple_value () ->\n"
"simple_color(vcenter(rm(\"...\") & hfill()));\n"
"\n"
"\n"
"text_line (line) ->\n"
"text_color(rm(line) & hfill());\n"
"\n"
"\n"
"text_value (...) -> valign(...);\n"
"\n"
"\n"
"collapsed_text_value () ->\n"
"text_color(rm(\"...\") & hfill());\n"
"\n"
"\n"
"pointer_value (value) ->\n"
"pointer_color(vcenter(value & hfill()));\n"
"\n"
"\n"
"collapsed_pointer_value () ->\n"
"pointer_color(vcenter(rm(\"...\") & hfill()));\n"
"\n"
"\n"
"dereferenced_pointer_value (value) ->\n"
"pointer_color(vcenter(bf(value)) & hfill());\n"
"\n"
"\n"
"collapsed_array () ->\n"
"array_color(vcenter(rm(\"\\133...\\135\") & hfill()));\n"
"\n"
"\n"
"empty_array () ->\n"
"array_color(vcenter(rm(\"\\133\\135\") & hfill()));\n"
"\n"
"\n"
"vertical_array (...) ->\n"
"array_color(frame(indent(vlist(hwhite() | hrule() | hwhite(), ...))));\n"
"\n"
"\n"
"horizontal_array (...) ->\n"
"array_color(frame(indent(fixed_hlist(vwhite() & vrule() & vwhite(), ...)))\n"
"& hfill());\n"
"\n"
"\n"
"twodim_array (...) ->\n"
"array_color(dtab(...));\n"
"twodim_array_elem (...) ->\n"
"rm(...);\n"
"\n"
"\n"
"struct_value (...) ->\n"
"struct_color(frame(indent(valign(...))));\n"
"\n"
"\n"
"collapsed_struct_value () ->\n"
"struct_color(vcenter(rm(\"{...}\") & hfill()));\n"
"\n"
"\n"
"empty_struct_value () ->\n"
"struct_color(vcenter(rm(\"{}\") & hfill()));\n"
"\n"
"\n"
"horizontal_unnamed_struct (...) -> horizontal_array(...);\n"
"vertical_unnamed_struct (...) -> horizontal_array(...);\n"
"\n"
"\n"
"struct_member_name (name) ->\n"
"struct_color(rm(name));\n"
"\n"
"\n"
"struct_member (name, sep, value, name_width) ->\n"
"vcenter(rm(name) | hspace(name_width))\n"
"& vcenter(rm(sep)) & rm(value);\n"
"\n"
"\n"
"struct_member (value) ->\n"
"rm(value);\n"
"\n"
"\n"
"list_value (...) ->\n"
"list_color(valign(...));\n"
"\n"
"\n"
"collapsed_list_value () ->\n"
"list_color(vcenter(rm(\"...\") & hfill()));\n"
"\n"
"\n"
"empty_list_value () ->\n"
"list_color(vcenter(rm(\"\") & hfill()));\n"
"\n"
"\n"
"horizontal_unnamed_list (...) -> horizontal_array(...);\n"
"vertical_unnamed_list (...)  -> horizontal_array(...);\n"
"\n"
"\n"
"list_member_name (name) ->\n"
"list_color(rm(name));\n"
"\n"
"\n"
"list_member (name, sep, value, name_width) ->\n"
"vcenter(rm(name) | hspace(name_width))\n"
"& vcenter(rm(sep)) & rm(value) & hfill();\n"
"\n"
"\n"
"list_member (value) ->\n"
"rm(value);\n"
"\n"
"\n"
"sequence_value (...) ->\n"
"simple_color(fixed_hlist(vwhite(), ...) & hfill());\n"
"\n"
"\n"
"collapsed_sequence_value () ->\n"
"collapsed_simple_value();\n"
"\n"
"\n"
"reference_value (ref, value) ->\n"
"reference_color(vcenter(rm(ref & \": \")) & value & hfill());\n"
"\n"
"\n"
"collapsed_reference_value () ->\n"
"reference_color(vcenter(rm(\"...\") & hfill()));\n"
"\n"
"\n"
"changed_value (value) ->\n"
"changed_color(it(value));\n"
"\n"
"\n"
"repeated_value (value, n) ->\n"
"value & vcenter(rm(\" <\" & dec(n) & \"\\327>\"));\n"
"\n"
"\n"
"display_box (title, value) ->\n"
"shadow(display_color(frame(title | hrule() | hwhite () | rm(value))));\n"
"\n"
"\n"
"display_box (value) ->\n"
"shadow(display_color(frame(rm(value))));\n"
