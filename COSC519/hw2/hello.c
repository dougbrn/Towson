//This is first program 
//Dr. Karne 
//hello.c 
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char **argv) 
{
   char c1; 
   unsigned char c2; 
   int i1=0; 
   long l2=0;
   char *cptr; 
   int *iptr; 
   long *lptr; 
   char array1[40] = "This is a string";

   cptr = (char *)malloc(200); 
   iptr = (int *)malloc(200); 
   lptr = (long *)malloc(200); 

   c1 = 'X'; 
   c2 = 0x44; 
   i1 = 0x100; 
   l2 = 0x0123456789abcdef; 

   *iptr = 0x2000; 
   *lptr = 0x88889999aaaabbbb; 

   printf("Hello World\n"); 
   printf("\n\n"); 
   printf("l2: %lx \n", l2); 
   printf("i1: %x \n", i1); 
   printf("i1: %10x \n", i1); 
   printf("i1: %4x \n", i1); 
   printf("c1: %c \n", c1); 
   printf("string: %s \n", array1); 

   /*Copy from input.txt to output.txt */
   FILE *input = fopen("input.txt","r");
   FILE *output = fopen("output.txt", "w");

   char ch;

   while((ch = fgetc(input)) != EOF)
      fputc(ch, output);

   fclose(input);
   fclose(output);


   return 0; 
}
