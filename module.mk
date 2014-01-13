######################################################
# 几乎所有子目录的模块都以该文件为基础.
# 例外 : unit_test(实际上unit_test的子目录也有包含该文
# 件的Makefile)和obj目录.
######################################################

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
