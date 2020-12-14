CC = gcc

CFLAGS = -Wall

TARGET = vmachine

compile:
	$(CC) $(CFLAGS) -o $(TARGET) src/vmachine/*.c

clean:
	$(RM) $(TARGET)