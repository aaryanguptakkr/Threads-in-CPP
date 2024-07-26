#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>



int fuel = 0;
pthread_mutex_t mutexFuel;
pthread_cond_t condVal;

void* fuelFilling(void* arg){
    for(int j = 0; j<5; j++){
        pthread_mutex_lock(&mutexFuel);
        fuel += 60;
        printf("Fuel Filled %d\n", fuel);
        pthread_mutex_unlock(&mutexFuel);
        pthread_cond_broadcast(&condVal);
        sleep(1);
    }
}

void* car(void* arg){
    pthread_mutex_lock(&mutexFuel);
    while(fuel < 40){
        printf("NO FUEL WAITING..... \n");
        pthread_cond_wait(&condVal,&mutexFuel);
        // printf("CHEKCING\n");
    }
    fuel -= 40;
    printf("Fuel consumed by car %d\n", fuel);
    pthread_mutex_unlock(&mutexFuel);
}

int main(int argc, char* argv[] ){
    pthread_t th[5];
    pthread_mutex_init(&mutexFuel, NULL);
    pthread_cond_init(&condVal, NULL);
    for (int i = 0; i<5; i++){
        if (i == 4){
            if(pthread_create(&th[i], NULL, &fuelFilling, NULL) != 0){
                perror("Thread not created");
            };
        }
        else{
            if(pthread_create(&th[i], NULL, &car, NULL) != 0){
                perror("Thread not created");
            };
        }
    }

    for (int i = 0; i<5 ; i++){
        pthread_join(th[i], NULL);
    }
    pthread_mutex_destroy(&mutexFuel);
    pthread_cond_destroy(&condVal);
    return 0;

}