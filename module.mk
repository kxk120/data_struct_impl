#
# This file will be included by all subdirectory Makefile as rule.
# @EXCEPT : unit_test and obj directory
#

.PHONY:all move clean

SOURCE 	:= $(wildcard *.c)
OBJS 	:= $(patsubst %.c,%.o,$(SOURCE))

all:$(OBJS) move

$(OBJS):%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

move:
	cp $(OBJS) ../$(OBJDIR)

clean:
	$(RM) *.o
