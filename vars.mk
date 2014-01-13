#
# 该文件是具有调试功能的Makefile,它能够打印出Makefile中的变量值.
# 该文件的内容完全是 陈皓(<<跟我一起写Makefile>>的作者) 所做.
# 非常感谢!
#
# 用法:
# make -f DEBUG_MAKEFILE -f vars.mk VAR
#
# 如果你向获得变量更多的信息:
# make -f DEBUG_MAKEFILE -f vars.mk d-VAR
#

%:
	@echo '$*=$($*)'

d-%:
	@echo '$*=$($*)'
	@echo '  origin = $(origin $*)'
	@echo '   value = $(value  $*)'
	@echo '  flavor = $(flavor $*)'
