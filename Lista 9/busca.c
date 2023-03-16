#include <stdio.h>
#include <stdlib.h>


//typedef int Item;

typedef struct{
    int valor;
    int pos;
}Item;

#define exch(A,B) {Item tt = A;\
                            A=B;\
                            B=tt;\
                        }
#define eq(A,B) (A==B)


void selectionsort(Item *v, int l, int r){
    for(int i=l; i<r ; i++){
        int min =i;
        for(int j= i; j< r;j++){
            if(v[j].valor < v[min].valor){
                min =j;
            }
        }
        exch(v[i],v[min]);
    }
}

int bb(Item *vetor, int l, int r, int b){
    int meio = (l + r) / 2;
    if (l > r){
        return -1;
    }
    if (vetor[meio].valor == b){
        return meio;
    }
    if (vetor[meio].valor < b){
        return bb(vetor, meio + 1, r, b);
    }else{
        return bb(vetor, l, meio - 1, b);
    }
}

int main(){
    int n, m,valorM;
    int i = 0;
    scanf("%d %d",&n, &m);
    Item valorN[n];
    
    while (i < n)
    {
        scanf("%d", &valorM);
        valorN[i].valor = valorM;
        valorN[i].pos = i;
        i++;
    }

    selectionsort(valorN, 0, n);

    for(int i=0;i<m;i++)
    {
        scanf("%d", &valorM);
        int result = bb(valorN, 0, n, valorM);
        if(result == -1){
            printf("-1\n");
        }else{
            printf("%d\n", valorN[result].pos);
        }
    }

}