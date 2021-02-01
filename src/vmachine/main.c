#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "machine.h"
#include "textfunc.h"

//memcell memory[MEMORY_SIZE];

int main(int argc, char** argv){
    if(argc == 1){
        textColor(tRed);
        printf("Error: No executable file (.vx) specified.\n");
        resetText();
        return -1;
    }
    FILE *file = fopen(argv[1], "r");
    if (file == NULL){
        textColor(tRed);
        printf("Error while opening file.\n");
        resetText();
        return -1;
    }

    int verbose = 0;
    if(argc > 2){
        if(strcmp(argv[2], "-v") == 0) verbose = 1;
    }
    memcell* memory;
    memory = malloc(MEMORY_SIZE * sizeof(memcell));
    
    initMachine(memory, MEMORY_SIZE, file);

    runMachine(memory, MEMORY_SIZE, verbose);
    fclose(file);
    return 1;
}
