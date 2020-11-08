#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "machine.h"

memcell memory[MEMORY_SIZE];

int main(int argc, char** argv){
    if(argc == 1){
        printf("Error: No executable file (.vmx) specified.\n");
        return -1;
    }
    FILE *file = fopen(argv[1], "r");
    if (file == NULL){
        printf("Error while opening file.\n");
        return -1;
    }

    int verbose;
    if(strcmp(argv[2], "-v") == 0 || argc >= 3) verbose = 1;
    else verbose = 0;
    
    initMachine(memory, MEMORY_SIZE, file);
    fclose(file);

    runMachine(memory, MEMORY_SIZE, verbose);
    return 1;
}
