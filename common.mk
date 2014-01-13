#####################################################
# 该文件包含一些具有通用功能的变量, 可供call函数调用.
#####################################################

# 
# 变量名: subdir
# 动作  : 取得所有子目录的名字(被指定不包含的目录除外)
# 用法  :
# 	include common.mk
# 	VAR_NAME = $(call subdir, exclude dir)
#
subdir = $(filter-out $(1),$(basename $(patsubst ./%,%,$(shell find . -maxdepth 1 -type d))))
