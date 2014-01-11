.PHONY: clean 
OBJS 	:= $(wildcard *.o)
TARGET 	:= run_test_project
LPATH	:= ../../obj

LFLAGS	:= $(LIB) -lcunit -static -L../../obj -ldsi

$(TARGET):$(OBJS)
	$(CC) $(INC) -o $@ $^ $(LFLAGS)
	-mv $(TARGET) ../result

clean :
	rm -f *.o $(TARGET)
