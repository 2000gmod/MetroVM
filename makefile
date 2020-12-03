CC = gcc
CFLAGS = -I

compile:
	gcc -o vmachine ./src/vmachine/*.c

clean:
	rm -f vmachine