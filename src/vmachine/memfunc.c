#include "memfunc.h"

unsigned short getShortFromCell(memcell* memory, int address){
    unsigned short out;
    memcell a = memory[address];
    memcell b = memory[address + 1];

    out = (((unsigned short) a ) << 8) | b;
    
    return out;
}