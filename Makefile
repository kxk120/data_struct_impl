.PHONY: all compile clean

OBJDIR	:= obj
CC 	:= gcc
MAKE	:= make
CFLAGS	:= -fPIC -Wall
CFLAGS	+= -g

# export above var.
export

# Get all subdir name that depth is 1, except $(exclude_dirs)
include common.mk

exclude_dirs 	 := unit_test obj
ALL_COMPILE_DIRS := $(call subdir,$(exclude_dirs))


all : compile
	$(MAKE) -C $(OBJDIR)

compile : $(ALL_COMPILE_DIRS)
	@echo $(ALL_COMPILE_DIRS)
	$(MAKE) -C $<
	
exclude_dirs	:= unit_test
CLEAN_DIRS	:= $(call subdir,$(exclude_dirs))

clean:
	for dir in $(CLEAN_DIRS);do $(MAKE) -C $$dir clean;done
