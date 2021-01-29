#include "memfunc.h"

unsigned short getShortFromCell(memcell* memory, int address){
    unsigned short out;
    memcell a = memory[address];
    memcell b = memory[address + 1];

    out = (((unsigned short) a ) << 8) | b;
    
    return out;
}

int getUsedMemory(memcell* memory, int memSize){
    int counter = 0;
    for (int k = 0; k < memSize; k++){
        if (memory[k] != 0) {
            counter++;
        }
    }
    return counter;
}

void addSizeBytes(memcell* memory, int addressA, int addressB, int byteCount){
	int overflow = 0;
	
	for (int offset = byteCount - 1; offset >= 0; offset -= 1){
		memcell byteA = memory[addressA + offset];
		memcell byteB = memory[addressB + offset];

		memcell byteOut = 0;
		byteOut = byteA + byteB + overflow;

		if ((int) byteA + (int) byteB > byteOut){
			overflow = 1;
		}
		else overflow = 0;

		memory[addressA + offset] = byteOut;
	}
}

void subSizeBytes(memcell* memory, int addressA, int addressB, int byteCount){
	int underflow = 0;
	
	for(int offset = byteCount - 1; offset >= 0; offset -= 1){
		memcell byteA = memory[addressA + offset];
		memcell byteB = memory[addressB + offset];

		memcell byteOut = 0;
		byteOut = byteA - byteB - underflow;

		if((int) byteA - (int) byteB < byteOut){
			underflow = 1;
		}
		else underflow = 0;

		memory[addressA + offset] = byteOut;
	}
}