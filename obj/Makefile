.PHONY: clean
OBJS 	:= $(wildcard *.o)
TARGET 	:= libdsi.so

$(TARGET):$(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

clean :
	rm -f *.o $(TARGET)
