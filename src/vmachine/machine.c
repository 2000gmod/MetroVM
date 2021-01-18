#include "machine.h"
#include "memfunc.h"

void initMachine(memcell* memory, unsigned int memSize, FILE* file){
    //memory = (memcell*) malloc(memSize * sizeof(memcell));
    if(memory == NULL){
        printf("Error while allocating, exiting...\n");
        exit(0);
    }
    //clean memory
    for (int k = 0; k < memSize; k++){
        memory[k] = 0;
    }
    memcell cell;
    for (int k = 0; k < memSize; k++){
        cell = (memcell) fgetc(file);
        if(feof(file)){
            break;
        }
        memory[k] = cell;
    }
    return;
}

void runMachine(memcell* memory, unsigned int memSize, int verbose){
    if (verbose){
        int used = getUsedMemory(memory, memSize);
        printf("VERBOSE MODE   | |  ");
        printf("LOADED MEMORY: %d bytes  | |  TOTAL MEMORY: %d bytes\n\n", used, memSize);
        printf("INSTRUCTION  ADDRESS   OPCODE      DESCRIPTION \n");
    }
    int execRegister = 0;
    int instructionCount = 1;

    while(execRegister < memSize){
        if (verbose) printf("INS:%05d    0x%04X    >:OP %02X     ", instructionCount, execRegister, memory[execRegister]);
        exeInstruction(memory, &execRegister, verbose);
        instructionCount++;
        /*
        if (instructionCount >= 100000){
            printf("Possible infinite loop, machine aborted.\n");
            return;
        }*/
    }
    printf("Execution address exceeded max value.\n");
    return;
}

void exeInstruction(memcell* memory, int* currentAddress, int verbose){
    unsigned short addressRefA = getShortFromCell(memory, *currentAddress + 1);
    unsigned short addressRefB = getShortFromCell(memory, *currentAddress + 3);
    unsigned short addressRefC = getShortFromCell(memory, *currentAddress + 5);

    switch(memory[*currentAddress]){

        case 255: //NOP
            if (verbose) printf("NOP \n");
            *currentAddress += 1;
            break;

        case 0: //HALT
            if (verbose) {
                printf("STOP\n\n");
                printf("STOPPED AT ADDRESS 0x%04X    ||    ", *currentAddress);
                printf("MEMORY USE AT STOP: %d bytes\n", getUsedMemory(memory, MEMORY_SIZE));
            }
            exit(0);

        case 1: //SET
            if (verbose) printf("SET 0x%04X TO 0x%02X\n", addressRefA, memory[*currentAddress + 3]);
            memory[addressRefA] = memory[*currentAddress + 3];
            *currentAddress += 4;
            break;

        case 2: //MOV
            if (verbose) printf("MOV 0x%04X TO 0x%04X\n", addressRefB, addressRefA);
            memory[addressRefA] = memory[addressRefB];
            *currentAddress += 5;
            break;

        case 3: //JMP
            if (verbose) printf("JMP TO 0x%04X\n", addressRefA);
            *currentAddress = addressRefA;
            break;

        case 4: //JNT
            if (memory[addressRefB] != 0) {
                if (verbose) printf("JNT TO 0x%04X (EVAL AT 0x%04X)\n", addressRefA, addressRefB);
                *currentAddress = addressRefA;
                break;
            }
            else {
                if (verbose) printf("JNT NO JUMP (EVAL AT 0x%04X)\n", addressRefB);
                *currentAddress += 5;
                break;
            }

        case 5: //ADD
            if (verbose) printf("ADD 0x%04X TO 0x%04X\n", addressRefB, addressRefA);
            memory[addressRefA] += memory[addressRefB];
            *currentAddress += 5;
            break;

        case 6: //SUB
            if (verbose) printf("SUB 0x%04X TO 0x%04X\n", addressRefB, addressRefA);
            memory[addressRefA] -= memory[addressRefB];
            *currentAddress += 5;
            break;

        case 7: //NOT
            memory[addressRefA] = ~(memory[addressRefA]);
            if (verbose) printf("NOT 0x%04X\n", addressRefA);
            *currentAddress += 3;
            break;

        case 8: //AND
            if (verbose) printf("AND 0x%04X && 0x%04X\n", addressRefA, addressRefB);
            memory[addressRefA] = memory[addressRefA] & memory[addressRefB];
            *currentAddress += 5;
            break;

        case 9: //OR
            if (verbose) printf("OR 0x%04X || 0x%04X\n", addressRefA, addressRefB);
            memory[addressRefA] = memory[addressRefA] | memory[addressRefB];
            *currentAddress += 5;
            break;

        case 10: //XOR
            if (verbose) printf("XOR 0x%04X ^ 0x%04X\n", addressRefA, addressRefB);
            memory[addressRefA] = memory[addressRefA] ^ memory[addressRefB];
            *currentAddress += 5;
            break;

        case 11: //PRINT
            if (verbose){
                printf("PRINT 0x%04X   : ", addressRefA);
                if (memory[addressRefA] >= 32) printf("%c", memory[addressRefA]);
		else printf(" ");
                printf("   (0x%02X)\n", memory[addressRefA]);
            }
            else printf("%c", memory[addressRefA]);
            *currentAddress += 3;
            break;

        case 12: //SCAN
            if (verbose) printf("SCAN TO 0x%04X   : ", addressRefA);
            scanf("%s", &memory[addressRefA]);
            *currentAddress += 3;
            break;

        //EXTENDED INSTRUCTION SET

        case 13: //JMZ
            if(memory[addressRefB] == 0){
                if (verbose) printf("JMZ TO 0x%04X (EVAL AT 0x%04X)\n", addressRefA, addressRefB);
                *currentAddress = addressRefA;
                break;
            }
            else {
                if (verbose) printf("JMZ NO JUMP (EVAL AT 0x%04X)\n", addressRefB);
                *currentAddress += 5;
                break;
            }

        case 14: //JEQ
            if(memory[addressRefB] == memory[addressRefC]){
                if (verbose) printf("JEQ TO 0x%04X (EVAL AT 0x%04X == 0x%04X)\n", addressRefA, addressRefB, addressRefC);
                *currentAddress = addressRefA;
                break;
            }
            else {
                if (verbose) printf("JEQ NO JUMP (EVAL AT 0x%04X == 0x%04X)\n", addressRefB, addressRefC);
                *currentAddress += 7;
                break;
            }

        case 15: //JLT
            if(memory[addressRefB] < memory[addressRefC]){
                if (verbose) printf("JLT TO 0x%04X (EVAL AT 0x%04X < 0x%04X)\n", addressRefA, addressRefB, addressRefC);
                *currentAddress = addressRefA;
                break;
            }
            else {
                if (verbose) printf("JLT NO JUMP (EVAL AT 0x%04X < 0x%04X)\n", addressRefB, addressRefC);
                *currentAddress += 7;
                break;
            }
        
        case 16: //JGT
            if(memory[addressRefB] > memory[addressRefC]){
                if (verbose) printf("JGT TO 0x%04X (EVAL AT 0x%04X > 0x%04X)\n", addressRefA, addressRefB, addressRefC);
                *currentAddress = addressRefA;
                break;
            }
            else {
                if (verbose) printf("JGT NO JUMP (EVAL AT 0x%04X > 0x%04X)\n", addressRefB, addressRefC);
                *currentAddress += 7;
                break;
            }

        case 17: //JLE
            if(memory[addressRefB] <= memory[addressRefC]){
                if (verbose) printf("JLE TO 0x%04X (EVAL AT 0x%04X <= 0x%04X)\n", addressRefA, addressRefB, addressRefC);
                *currentAddress = addressRefA;
                break;
            }
            else {
                if (verbose) printf("JLE NO JUMP (EVAL AT 0x%04X <= 0x%04X)\n", addressRefB, addressRefC);
                *currentAddress += 7;
                break;
            }

        case 18: //JGE
            if(memory[addressRefB] >= memory[addressRefC]){
                if (verbose) printf("JGE TO 0x%04X (EVAL AT 0x%04X >= 0x%04X)\n", addressRefA, addressRefB, addressRefC);
                *currentAddress = addressRefA;
                break;
            }
            else {
                if (verbose) printf("JGE NO JUMP (EVAL AT 0x%04X >= 0x%04X)\n", addressRefB, addressRefC);
                *currentAddress += 7;
                break;
            }

        //DEFAULT CASE
        default:
            printf("Error: Invalid opcode.\n");
            printf("Crash ocurred at address 0x%04X\n", *currentAddress);
            exit(-1);
    }
    return;
}
