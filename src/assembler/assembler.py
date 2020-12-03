import sys
import math as m

def getArgSize(opcode):
    if opcode == 255 or opcode == 0:
        return 0
    elif opcode == 3 or opcode == 7 or opcode == 11 or opcode == 12:
        return 2
    elif opcode == 1:
        return 3
    else:
        return 4

def getOpcode(insName):
    if insName == 'nop': return 255
    elif insName == 'stop': return 0
    elif insName == 'set': return 1
    elif insName == 'mov': return 2
    elif insName == "jmp": return 3
    elif insName == "jnt": return 4
    elif insName == "add": return 5
    elif insName == "sub": return 6
    elif insName == "not": return 7
    elif insName == "and": return 8
    elif insName == "or": return 9
    elif insName == "xor": return 10
    elif insName == "print": return 11
    elif insName == "scan": return 12
    else:
        print("Invalid instruction:", insName)
        exit(-1)



inputFile = open(sys.argv[1], "r")
outputFile = open(sys.argv[2], "w")
lineCounter = 0
for linea in inputFile:
    linea = linea.rstrip("\n")
    lineaList = linea.split(" ")
    outputFile.write(chr(getOpcode(lineaList[0])))
    for arg in range(1, len(lineaList)):
        if len(lineaList[arg]) == 2:
            outputFile.write(chr(int(lineaList[arg], 16)))
            continue
        elif len(lineaList[arg]) == 4:
            byte1 = lineaList[arg][:2]
            byte2 = lineaList[arg][2:]
            #print(byte1, byte2)
            outputFile.write(chr(int(byte1, 16)))
            outputFile.write(chr(int(byte2, 16)))
        else:
            print("Error at arg", arg, ", at line ", lineCounter)
            exit(-1)
    lineCounter +=1



inputFile.close()
outputFile.close()