
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
int main()
{
    system ("clear");
    int i ;
    pid_t childa,childb,childa1,childa2,childb1,childb2;
    printf("\n \t \t I am the parent process with ID %d \n",getpid());
    childa=fork();
    if (childa == 0 )
    {
        printf("\nI am a child A with PID %d and my parent ID is %d\n",getpid(),getppid());
    }
    else
    {
        childb = fork();
        if (childb == 0)
        {
            printf("\nI am Child B with ID %d and my parent ID is %d\n",getpid(),getppid());
        }
        else
        {
            sleep(1);
        }
    }
}