#include <stdio.h>
#include <stdlib.h>

typedef int Item;

#define less(A,B) (A<B)
#define exch(A,B) {Item tt = A;\
                             A=B;\
                             B=tt;\
                            }

void selectionsort(Item *v, int l, int r){
    for(int i=l; i<r ; i++){
        int min =i;
        for(int j= i+1; j<= r;j++){
            if(less(v[j],v[min])){
                min =j;
            }
        }
        exch(v[i],v[min]);
    }
}

int main(){
    int *vetor;
    vetor = malloc(1000 * sizeof(int));
    int j=0;

    while(scanf("%d", &vetor[j]) != EOF){
        j++;        
    }
    selectionsort(vetor, 0, j);
    printf("%d",vetor[1]);
    for(int i=2;i<=j;i++)
    {
        printf(" %d",vetor[i]);
    }
    printf("\n");
}