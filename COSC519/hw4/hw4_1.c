// COSC 519 Homework 4 Problem 1
// Create a Thread that waits for keyboard input or escape character and then returns
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *runner(void *param); //threads call this function

int main()
{
    pthread_t tid; //thread identifier
    pthread_attr_t attr; //thread attributes

    pthread_attr_init(&attr); //get default attributes
    pthread_create(&tid, &attr, runner, 0); //create the thread

    //Wait forthread to exit
    pthread_join(tid, NULL);
    printf("Waited for Thread and it returned.\n");
}

void *runner(void *param)
{
    int c;
    do{
        printf("Type a Character, or press ESC to exit: ");
        c = getchar();
        printf("\n");
    }while((c != 27) && (c != 120));
    return(0);
}