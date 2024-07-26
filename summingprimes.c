#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

int primes[10] = {2,3,5,7,11,13,17,19,23,29};

void* routine(void *arg){
    // sleep(1);
    int index = *(int*)arg;
    int sum = 0;
    for (int j = 0; j<5; j++){
        sum += primes[j+index];
    }
    *(int*)arg = sum;
    return arg;
    // printf("%d\t", primes[index]);
    // free(arg);
}

int main(){
    pthread_t pt[2];
    int i;
    
    for(i = 0; i< 2; i++){
        int* a = malloc(sizeof(int));
        *a = i * 5;

        if(pthread_create(&pt[i], NULL, &routine, a)!=0){
            perror("Failed to create thread");
        };
        
    //    if(pthread_create(&pt[i], NULL, &routine, &primes[i])!=0){
    //         perror("Failed to create thread");
    //     };
    }
    int Gsum = 0;
    for(i = 0; i< 2; i++){
        int* r;
        if(pthread_join(pt[i], &r) != 0){
            perror("Failed to join thread");
        };
        Gsum += *r ;
        free(r);
    }
    printf("Some of the prime numbers is %d", Gsum);
    return 0;
}