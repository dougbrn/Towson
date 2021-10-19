//COSC 519 HW 3
//Doug Branton

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    pid_t pid;
    int count = 0;
    int n_children = 4;
    int i;


    for(i=0; i < n_children; i=i+1){
        /* fork a child process */
        pid = fork();

        if (pid < 0)
        { /* error occured */
            fprintf(stderr, "Fork Failed");
            return 1;
        }

        else if (pid == 0)
        { /* child process */

            //sleep i seconds so that each process returns full output separately
            //Otherwise all 4 children will print to terminal whenever they execute, which is fine, but messy
            sleep(i); 
            
            int child_pid = getpid();
            printf("=====================\n");
            printf("Child PID: %d\n", child_pid);
            printf("=====================\n");
            execlp("./hello", "", NULL);
        } 
    }

    for(i=0;i<n_children;i=i+1) //Have a wait loop that has n_children number of waits
    { /* Parent Process */
        /* parent will wait for child to complete */
        wait(NULL);
    }
    printf("All Children Complete\n");
    

    return 0;
}
