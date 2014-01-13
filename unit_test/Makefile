CC	:= gcc
INC	:= -I.
INC	+= -I./cunit_include
INC	+= -I../cunit_include
LIB	:= -L../cunit_lib
CFLAGS	+= -g

export
MAKE	:= make
OBJDIR	:= obj

include ../common.mk
exclude_dir := result cunit_include cunit_lib
SUBDIRS := $(call subdir, $(exclude_dir))

.PHONY: all compile clean exe

all : compile
	$(CC) $(INC) $(CFLAGS) -c register_test_project.c -o obj/register_test_project.o
	$(MAKE) -C $(OBJDIR)

compile : $(SUBDIRS)
	$(MAKE) -C $<

clean:
	for dir in $(SUBDIRS);do $(MAKE) -C $$dir clean;done
	$(RM) result/data_struct_impl* result/run_test_project

exe:
	cd result && ./run_test_project
