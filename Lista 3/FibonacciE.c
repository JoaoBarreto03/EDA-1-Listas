#include <stdio.h>

int fibmen[31];

int fibreal(int x){
    if(fibmen[x]!=1)
    return fibmen[x];
    fibmen[x] = fibreal(x-1)+fibreal(x-2);
    
    return fibmen[x];
} 


int fib(int x){
    fibmen[1] = 1;
    fibmen[2] = 1;

    for(int i = 3; i<31; i++)
    fibmen[i] = -1;

    return fibreal(x);
}

int main(){
    int x;
    scanf("%d", &x);
    printf("%d\n", fibreal(x));

}