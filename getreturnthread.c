#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

void* diceRoll(void* ptr){
    int value = ( ( rand() % 6 ) + 1 );
    int* result = malloc(sizeof(int));
    *result = value;
    return (void*) result;
}

int main(){
    int* res;
    srand(time(NULL));
    pthread_t th[4];

    for(int i = 0; i<4; i++){
        pthread_create(&th[i],  NULL, &diceRoll, NULL);
    }
    for(int i = 0; i<4; i++){
        pthread_join(th[i], (void**) &res );
        printf("Result is %d\n", *res);
    }
    
    // return *res;
    
    return 0;

}