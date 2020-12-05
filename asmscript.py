import os
import sys

if len(sys.argv) == 3:
    command = 'python3 ./src/assembler/assembler.py ' + sys.argv[1] + " " + sys.argv[2]
elif len(sys.argv) == 2:
    command = 'python3 ./src/assembler/assembler.py ' + sys.argv[1] + " " + sys.argv[1].rstrip(".vas") + ".vx" 
else:
    printf("Error, not enough arguments.")

os.system(command)