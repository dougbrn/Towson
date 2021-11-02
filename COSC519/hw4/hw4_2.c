// COSC 519 Homework 4 Problem 2
// Create 10 Threads that print hello and return
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *runner(void *param); //threads call this function
int NUM_THREADS = 10;

int main()
{

    int i,j;
    pthread_t tid;

    // Create NUM_THREADS Threads
    for (i = 0; i < NUM_THREADS; i++)
        pthread_create(&tid, NULL, runner, (void *)&tid);

    //Wait for all threads to exit
    for (j=0;j<NUM_THREADS;j++){
        pthread_join(tid, NULL);
    }
    
    printf("Waited for all threads.\n");
}

void *runner(void *param)
{
    printf("Hello from Thread: %ld\n", pthread_self());
    return(0);
}