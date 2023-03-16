#include <stdlib.h>
#include <stdio.h>


int main(){
    int c1, c2, c3, T;
    int result;


    scanf("%d %d %d", &c1, &c2, &c3);
    scanf("%d", &T);
    result = c1 + c2 + c3;
    
    if(T == result){
        printf("Acertou\n");
    }else{
        printf("Errou\n");
    }

    
}