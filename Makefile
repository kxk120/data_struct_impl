OBJDIR 	:= obj
CC 		:= gcc
MAKE 	:= make
CFLAGS 	:= -fPIC -shared -Wall

# export above var.
export

# Get all subdir name that depth is 1, except $(exclude_dirs)
subdir  = $(filter-out $(1),$(basename $(patsubst ./%,%,$(shell find . -maxdepth 1 -type d))))
#subdir  = $(1)

exclude_dirs 	 := unit_test obj
ALL_COMPILE_DIRS := $(call subdir,$(exclude_dirs))

.PHONY: all compile clean clean_dirs debug

all : compile
	$(MAKE) -C $(OBJDIR)

compile : $(ALL_COMPILE_DIRS)
	@echo $(ALL_COMPILE_DIRS)
	$(MAKE) -C $<
	
exclude_dirs := unit_test obj
CLEAN_DIRS 	 := $(call subdir,$(exclude_dirs))

clean: $(CLEAN_DIRS)
	$(MAKE) -C $< clean

debug:
	@echo $(shell find . -maxdepth 1 -type d)
	@echo $(basename $(patsubst ./%,%,$(shell find . -maxdepth 1 -type d)))
	@echo $(patsubst /%,%,$(basename $(patsubst .%,%,$(shell find . -maxdepth 1 -type d))))
	@echo $(filter-out $(exclude_dirs),$(basename $(patsubst ./%,%,$(shell find . -maxdepth 1 -type d))))
	@echo $(call subdir,unit_test)
