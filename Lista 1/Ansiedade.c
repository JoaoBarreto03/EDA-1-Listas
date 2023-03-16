#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    char res[4];
    int qtd=0;
    int cont=0;
    int cont2=0;
    int i=0;

    while(scanf("%s", res) != EOF){
        qtd++;
        if(strcmp(res, "sim") == 0){
            cont++;   
        }
        if(cont == 2 && i == 0){
            cont2++;
            i++;
        }
        if(qtd == 10){
            cont = 0;
            qtd = 0;
            i = 0;
        }
    }
    printf("%d\n", cont2);
}
