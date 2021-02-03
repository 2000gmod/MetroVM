#ifndef MACHINE_H
#define MACHINE_H

#include <stdlib.h>
#include <stdio.h>

#define MEMORY_SIZE 65536

typedef unsigned char memcell;

void initMachine(memcell* memory, unsigned int memSize, FILE* file);
void runMachine(memcell* memory, unsigned int memSize, int verbose);
void exeInstruction(memcell* memory, int* currentAddress, int verbose);

#endif
