#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

int primes[10] = {2,3,5,7,11,13,17,19,23,29};

void* routine(void *arg){
    // sleep(1);
    int index = *(int*)arg;
    printf("%d\t", index);
    // printf("%d\t", primes[index]);
    // free(arg);
}

int main(){
    pthread_t pt[10];
    int i;
    
    for(i = 0; i< 10; i++){
        // int* a = malloc(sizeof(int));
        // *a = i;
        // if(pthread_create(&pt[i], NULL, &routine, a)!=0){
        //     perror("Failed to create thread");
        // };
       if(pthread_create(&pt[i], NULL, &routine, &primes[i])!=0){
            perror("Failed to create thread");
        };
    }
    for(i = 0; i< 10; i++){
        if(pthread_join(pt[i], NULL) != 0){
            perror("Failed to join thread");
        };
    }
    return 0;
}