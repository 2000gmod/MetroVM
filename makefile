CC = gcc

CFLAGS = -Wall

TARGET = metrovm

compile:
	$(CC) $(CFLAGS) -o $(TARGET) src/vmachine/*.c

install:
	sudo cp ./$(TARGET) /usr/local/bin

update:
	sudo rm /usr/local/bin/$(TARGET)
	sudo cp ./$(TARGET) /usr/local/bin

cleaninstall:
	sudo rm /usr/local/bin/$(TARGET)

clean:
	$(RM) $(TARGET)