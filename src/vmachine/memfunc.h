#ifndef MEMFUNC_H
#define MEMFUNC_H
#include "machine.h"

unsigned short getShortFromCell(memcell* memory, int address);
int getUsedMemory(memcell* memory, int memSize);
void addSizeBytes(memcell* memory, int addressA, int addressB, int byteCount);
void subSizeBytes(memcell* memory, int addressA, int addressB, int byteCount);

#endif