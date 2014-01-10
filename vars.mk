#
# This file is for debug Makefile. It can print var value in makefile.
# I must be thankful to chenhao(陈皓) who is <<跟我一起写Makefile>>'s author
# to provide the method for debug.
#
# Usage:
# make -f DEBUG_MAKEFILE -f vars.mk VAR
#
# or if you want more information:
# make -f DEBUG_MAKEFILE -f vars.mk d-VAR
#

%:
	@echo '$*=$($*)'

d-%:
	@echo '$*=$($*)'
	@echo '  origin = $(origin $*)'
	@echo '   value = $(value  $*)'
	@echo '  flavor = $(flavor $*)'
