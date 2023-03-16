#include <stdio.h>
#include <stdlib.h>

int main(){

    int n;
    int nota;
    int rest;
    int dia;
    int maiorNota, maiorCod;

    dia = 1;
    while(scanf("%d", &n)!= EOF){
        maiorCod = maiorNota = -1; 
        for(int i=0; i < n; i++){
            scanf("%d %d", &rest, &nota);
        
            if(nota > maiorNota || nota == maiorNota && rest < maiorCod){
                maiorNota = nota;
                maiorCod = rest;
            }
        }
        printf("Dia %d\n", dia);
        printf("%d\n\n", maiorCod);
        dia ++;
    }
    return 0;
}