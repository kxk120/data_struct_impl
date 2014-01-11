#################################################
# This file include some common var.
#################################################

# 
# VAR	: subdir
# ACTION: get all subdirctory name except all specified by user.
# USAGE :
# 	include common.mk
# 	VAR_NAME = $(call subdir, exclude dir)
#
subdir = $(filter-out $(1),$(basename $(patsubst ./%,%,$(shell find . -maxdepth 1 -type d))))
