#include <stdio.h>
#include <stdlib.h>


void swap(int &a, int &b){
    int temp;
    temp = b;
    b = a;
    a = temp;
    return a, b
}


// *a = 5
// value at a = 5
// a = address of *a i.e. 5

// &a = 5
// address of a = 5 ?

int main(){
    int a = 5;
    int b = 6;
    swap(a, b);
    printf("after swapping %d and %d",a,b);
}

