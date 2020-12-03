import os
import sys


command = 'python3 ./src/assembler/assembler.py ' + sys.argv[1] + " " + sys.argv[2]

print(command)
os.system(command)