#include <stdio.h>
#include <stdlib.h>

typedef int Item;

#define less(A,B) (A<B)
#define exch(A,B) {Item tt = A;\
                           A=B;\
                         B=tt;\
                      }
#define cmpexch(A,B){ if(less(B, A)) exch(A,B)}

void bubblesort(Item *v, int l, int r){
    for(int i=l; i<r; i++){
        for(int j=l; j<r;j++){
            //if(less(v[j+1],v[j])){
              //  exch(v[j+1],v[j]);
            //}
            cmpexch(v[j], v[j+1]);
        }
    }
}

int main(){
    int *vetor;
    vetor = malloc(1000 * sizeof(int));
    int j=0;

    while(scanf("%d", &vetor[j]) != EOF){
        j++;        
    }
    bubblesort(vetor, 0, j);
    printf("%d",vetor[1]);
    for(int i=2;i<=j;i++)
    {
        printf(" %d",vetor[i]);
    }
    printf("\n");
}