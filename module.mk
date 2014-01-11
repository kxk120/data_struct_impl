#
# This file will be included by all subdirectory Makefile as rule.
# @EXCEPT : unit_test and obj directory
#

.PHONY:all move clean

SOURCE	:= $(wildcard *.c)
OBJS	:= $(patsubst %.c,%.o,$(SOURCE))

all:$(OBJS) move

$(OBJS):%.o:%.c
	$(CC) $(INC) $(CFLAGS) -c $< -o $@ $(LFLAGS)

move:
	cp $(OBJS) ../$(OBJDIR)

clean:
	$(RM) *.o
