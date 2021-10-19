#!/bin/bash

#compile and link

echo "Script File hw3.sh"

#yasm -g dwarf2 -iformat=yasm -f elf64 -o asmfiles.o asmfiles.asm -l asmfiles.lst

gcc -c -S -masm=intel -g main.c

gcc -c -Wa,-adhln -masm=intel -g main.c > main.lst

gcc -Xlinker -Map=main.map -o main main.o 

echo "Done"