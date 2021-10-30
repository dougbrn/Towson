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

    pthread_attr_int(&attr); //get default attributes
    pthread_create(&tid, &attr, runner, 0); //create the thread

    //Wait forthread to exit
    pthread_join(tid, NULL);
}

void *runner(void *param)
{
    
}