# README IS NOT COMPLETE!


### INSTRUCTIONS

Instructions use a 1 byte instruction code, followed by 2 arguments, each 2 bytes in size.  The memory can be up to 65 KiB in size (because of the 16-bit memory address), however, this can be customized.

The machine supports up to a maximum of 256 instructions (0x00 to 0xFF).

| INSTRUCTION | OPCODE |HEX OPCODE| DESCRIPTION | ASSEMBLER FORMAT 
| ------: | :------: | :-----: |:-------|:-------|
| **NOP** | 255 | 0xFF | No operation, skips | nop
| **STOP** | 0 | 0x00 | Stops the execution of the machine | stop
| **SET** | 1 | 0x01 | Sets content of A to a 1-byte integer | set A NUM
| **MOV** | 2 | 0x02 | Copies (moves) content of A into B | mov A B
| **JMP** | 3 | 0x03 | Sets the instruction register to location A | jmp A
| **JNT** | 4 | 0x04 | Same as JMP but only if content of B is not 0 | jnt A B
| **ADD** | 5 | 0x05 | Adds content of B to content of A | add A B
| **SUB** | 6 | 0x06 | Subtracts the content of B to the content of A | sub A B
| **NOT** | 7 | 0x07 | Inverts all bits in memory cell A | not A
| **AND** | 8 | 0x08 | Performs bitwise AND between A and B, stores the result in A | and A B
| **OR** | 9 | 0x09 | Performs bitwise OR between A and B, stores the result in A | or A B
| **XOR** | 10 | 0x0A | Performs bitwise XOR between A and B, stores the result in A | xor A B
| **PRT** | 11 | 0x0B | Prints content of A | prt A

### MEMORY

