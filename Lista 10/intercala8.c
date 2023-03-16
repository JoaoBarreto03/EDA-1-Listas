#include <stdio.h>
#include <stdlib.h>

#define less(A,B) (A<B)

int intercala8(int *v1, int *v2, int n1, int n2){
    int i=0;
    int j = 0;
    int k = 0;
    int tam = n1+n2;
    int *v3 = (int*)malloc(tam*sizeof(int));

    while(i<n1 && j<n2){
        if(less(v1[i],v2[j])){
            v3[k++] = v1[i++];
        }else{
            v3[k++] = v2[j++];
        }
    }

    while (i < n1){
        v3[k++] = v1[i++];
    }
    while (j < n2){
        v3[k++] = v2[j++];
    }
    k = 0;
    for (i = 0; i < tam; i++){
        v1[i] = v3[k++];
    }
    free(v3);
}

int main(){
    int s[1000001];
    int itens[1000001];
    int n;
    int quant = 0;

    for(int i = 0; i < 8; i++){
        n = 0;
        scanf("%d", &n);
        for(int j = 0; j<n; j++){
            scanf("%d", &s[j]);
        }
        intercala8(itens, s, quant, n);
        quant+=n;
        
    }

    for(int j = 0; j < quant; j++){
        printf("%d ", itens[j]);
    }
    printf("\n");
    
    return 0;
}