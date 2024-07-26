#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<semaphore.h>

int NUM_TH = 8;
int count = 0;
sem_t sem_full;
sem_t sem_empty;
pthread_mutex_t mutex_buffer;
int buffer[10];

void* producer(void* arg){
    while(1){
        int x = rand() % 100;
        sleep(1);
        sem_wait(&sem_empty);
        pthread_mutex_lock(&mutex_buffer);
        buffer[count] = x;
        count++;
        pthread_mutex_unlock(&mutex_buffer);
        sem_post(&sem_full);
    }
}
int y = -1;
void* consumer(void* arg){
    while(1){
        sem_wait(&sem_full);
        pthread_mutex_lock(&mutex_buffer);
        y = buffer[count];
        count--;
        pthread_mutex_unlock(&mutex_buffer);
        sem_post(&sem_empty);
        printf("GOT NUMBER %d\n", y);
    }
}


int main(){
    pthread_t th[NUM_TH];
    pthread_mutex_init(&mutex_buffer, NULL);
    sem_init(&sem_full,0,0);
    sem_init(&sem_empty,0,10);
    srand(time(NULL));
    for(int i = 0; i < NUM_TH; i++){
        if (i < 7){
            pthread_create(&th[i], NULL, &producer, NULL);
        }
        else{
            pthread_create(&th[i], NULL, &consumer, NULL);
        }
        
    }

    for (int i = 0; i < NUM_TH; i++)
    {
        pthread_join(th[i], NULL);
    }
    pthread_mutex_destroy(&mutex_buffer);
    sem_destroy(&sem_empty);
    sem_destroy(&sem_full);
    return 0;
    
    
}