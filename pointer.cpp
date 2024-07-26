#include<stdio.h>
#include<stdlib.h>

// using namespace std;
int main(){
    int a = 1;
    int *b = &a;
    printf("%p, %d, %d", &a, a, *b);
}
