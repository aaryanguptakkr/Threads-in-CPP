#include<stdlib.h>
#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

// using namespace std;
int x = 0;
pthread_mutex_t mutex;
// void* tempfunc1(void* ptr) {
//     printf("testing threads\n");
//     x++;
//     sleep(3);
//     printf("x is %d\n",x);
//     printf("ENDING THREAD\n");
//     return NULL;
// }
int lock = 0;
void* tempfunc(void* ptr) {
    // printf("testing threads\n");
    // sleep(3);
    // printf("x is %d\n",x);
    // printf("ENDING THREAD\n");
    for(int i = 0; i<100000; i++){
        pthread_mutex_lock(&mutex);
        x++;
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

int main(){
    pthread_t t1, t2;
    pthread_mutex_init(&mutex, NULL);
    if(pthread_create( &t1, NULL, &tempfunc, NULL)){
        return 1;
    }
    if(pthread_create( &t2, NULL, &tempfunc, NULL)){
        return 2;
    }
    if(pthread_join(t1, NULL)){
        return 3;
    }
    if(pthread_join(t2, NULL)){
        return 4;
    }
    pthread_mutex_destroy(&mutex);
    printf("%d is x\n", x);
    return 0;
}