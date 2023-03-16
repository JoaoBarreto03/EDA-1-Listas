#include <stdio.h>
#include <string.h>

int main(){
    int T=0, N=0;
    char time[200];
    int p=0;
    int empate=0;
    int aux=0;
    scanf("%d %d", &T, &N);

    while(T != 0){
        for(int i = 0; i < T; i++){
            scanf("%s", time);
            scanf("%d", &p);
            aux += p;
            
        }
        empate = 3*N - aux;
        printf("%d\n", empate);
        scanf("%d %d", &T, &N);
        empate = 0;
        aux = 0;
    }
}