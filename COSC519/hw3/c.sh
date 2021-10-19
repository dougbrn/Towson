#!/bin/bash

#compile and link

echo "Script File c.sh"

#yasm -g dwarf2 -iformat=yasm -f elf64 -o asmfiles.o asmfiles.asm -l asmfiles.lst

gcc -c -S -masm=intel -g hello.c

gcc -c -Wa,-adhln -masm=intel -g hello.c > hello.lst

gcc -Xlinker -Map=hello.map -o hello hello.o 

echo "Done"
