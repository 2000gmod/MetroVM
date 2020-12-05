#ifndef MEMFUNC_H
#define MEMFUNC_H
#include "machine.h"

unsigned short getShortFromCell(memcell* memory, int address);
int getUsedMemory(memcell* memory, int memSize);

#endif