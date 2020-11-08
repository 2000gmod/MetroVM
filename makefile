compile:
	gcc -o vmachine ./src/vmachine/*.c
	gcc -o assembler ./src/assembler/*.c

clean:
	rm -f vmachine
	rm -f assembler