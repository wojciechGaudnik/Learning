# $Id: umlaut8.sed,v 1.3 1997/09/19 15:33:20 zeller Exp $
# Convert overstrike umlauts ("\"\ba" etc.) to 8-bit umlauts

# Plain
s/'e/�/g
s/"a/�/g
s/"o/�/g
s/"u/�/g
s/"A/�/g
s/"O/�/g
s/"U/�/g
s/sss\([^]\)/�\1/g
s/sss$/�/g

# Underline
s/'_e/_�/g
s/"_a/_�/g
s/"_o/_�/g
s/"_u/_�/g
s/"_A/_�/g
s/"_O/_�/g
s/"_U/_�/g
s/_s_ss\([^]\)/_�\1/g
s/_s_ss$/_�/g

# Bold
s/''e/��/g
s/""a/��/g
s/""o/��/g
s/""u/��/g
s/""A/��/g
s/""O/��/g
s/""U/��/g
s/ssssss\([^]\)/��\1/g
s/ssssss$/��/g

