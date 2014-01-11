.PHONY: clean

OBJS 	:= $(wildcard *.o)

TARGET 	:= libdsi
CFLAGS	+= -shared

#
# .so and .a are both generated together!
#
$(TARGET):$(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET).so $^
	ar crv $(TARGET).a $^

clean :
	rm -f *.o $(TARGET).*
