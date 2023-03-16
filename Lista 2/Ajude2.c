#include <stdio.h>
#include <stdlib.h>


int main(){
    int N;
    int C;
    int T;
    int soma=0;

    scanf("%d", &N);

    for(int i = 0; i < N; i++){
        scanf("%d", &C);
        soma += C;

    }
    scanf("%d", &T);

    if(T == soma){
        printf("Acertou\n");
    }else{
        printf("Errou\n");
    }
}