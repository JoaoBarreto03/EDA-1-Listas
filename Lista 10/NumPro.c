#include <stdio.h>
#include <stdlib.h>

#define eq(A,B) (A==B)
#define less(A,B) (A.valor<B.valor)

typedef struct{
    int valor;
}Item;


int busca(Item *vetor, int l, int r, int b){
    int meio = (l + r) / 2;
    while(l<=r){
        if (vetor[meio].valor == b){
            return meio;
        }
        if (vetor[meio].valor < b){
            return busca(vetor, meio + 1, r, b);
        }else{
            return busca(vetor, l, meio - 1, b);
        }
    }
    return 0;
}

void merge(Item *v, int l, int r1, int r2){
    Item *v2 = malloc(sizeof(Item)*(r2-l+1));
    int k=0;
    int i = l;
    int j = r1+1;
    while(i<=r1 && j<=r2){
        if(less(v[i], v[j])){
            v2[k++] = v[i++]; 
        }else{
            v2[k++] = v[j++];
        }
    }
    while(i<=r1){
        v2[k++]=v[i++];
    }
    while(j<=r2){
        v2[k++] = v[j++];
    }
    k = 0;
    for(i = l; i<=r2; i++){
        v[i]=v2[k++];
    }
    free(v2);
}

void mergesort(Item *v, int l, int r){
    int meio = (r+l)/2;
    if(l == r)return;
    mergesort(v, l, meio);
    mergesort(v, meio+1, r);
    merge(v, l, meio, r);
}

int main(){
    int N;
    int Nbusca;
    scanf("%d", &N);
    Item *v = (Item *)malloc(N * sizeof(Item));

    for(int i = 0; i< N; i++){
        scanf("%d", &v[i].valor);
    }

    mergesort(v, 0, N-1);

    for (; scanf(" %d", &Nbusca) != EOF;){
        printf("%s\n", busca(v, 0, N, Nbusca) ? "sim" : "nao");
    }
   
    return 0;

}