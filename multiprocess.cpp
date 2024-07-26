#include<stdlib.h>
#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>

int main(){
    int x = 1;
    printf("HEllo I Am parent %d\n", getpid());
    int pid = fork();
    fork();
    if(pid == -1){
        return 1;
    }

    printf("PROCESS %d TAKING PLACE and parent id %d\n", getpid(), getppid());
    if(pid != 0){
        wait(NULL);
    }
    else{
        printf("INITIALLY X %d\n", x);
        x++;
    }
    printf("x is %d\n",x);
    // printf("HELLO\n");
    return 0;
}