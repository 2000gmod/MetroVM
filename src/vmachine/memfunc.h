#ifndef MEMFUNC_H
#define MEMFUNC_H
#include "machine.h"

unsigned short getShortFromCell(memcell* memory, int address);
int getUsedMemory(memcell* memory, int memSize);
void addSizeBytes(memcell* memory, unsigned short addressA, unsigned short addressB, memcell byteCount);
void subSizeBytes(memcell* memory, unsigned short addressA, unsigned short addressB, memcell byteCount);

#endif