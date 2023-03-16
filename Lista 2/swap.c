#include <stdio.h>

void swap(int *a, int *b){
    int c = *a;
    *a = *b;
    *b = c;
}

int main(){
    int f = 50, g = 10;
    swap(&f, &g);
    printf("%x %x\n", &f, &g);
}