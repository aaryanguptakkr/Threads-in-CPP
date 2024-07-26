#include<stdlib.h>
#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<semaphore.h>

sem_t semaphore;
int count = 0;
void* routine(void* arg){
    sem_wait(&semaphore);
    count++;
    printf("Hellow %d World\n", count);
    sem_post(&semaphore);
    // sleep(1);
    
}

int main(int argc, char* argv[]){
    pthread_t th[5];
    sem_init(&semaphore, 0, 2);
    for(int i = 0; i<5; i++){
        pthread_create(&th[i], NULL, &routine, NULL);
    }
    for(int i = 0; i<5; i++){
        pthread_join(th[i], NULL);
    }
    sem_destroy(&semaphore);
    return 0;
}