#include <stdio.h>
#include <stdlib.h>

int main(){
    int N;
    int i=0;
    
    while(scanf("%d", &N) != EOF){
        i++;
        if(N<0 || N> 10000000){
            return 0;
        }
    }
    
    printf("%d\n", i);
}