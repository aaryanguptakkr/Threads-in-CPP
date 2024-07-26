#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>

int primes[10] = {2,3,5,7,11,13,17,19,23,29};

void* printPrime(void* arg){
    int index = *arg;
    printf("Value of %d th prime is %d", index, primes[index]);
}


int main(){
    pthread_t th[10];
    for(int i = 0; i<10; i++){
        pthread_create(&th[i], NULL, &printPrime, &i );
    }
    for(int i = 0; i<10; i++){
        pthread_join(th[i], NULL );
    }
    return 0;
}