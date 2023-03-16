#include <stdio.h>
#include <stdlib.h>

typedef int Item;

#define less(A,B) (A<B)
#define exch(A,B) {Item tt = A;\
                             A=B;\
                             B=tt;\
                            }
 #define cmpexch(A,B) {if(less(B,A)) exch(A,B)}

void insertionsort(Item *v, int l , int r){
    for(int i=r; i>l; i--){ 
        cmpexch(v[i-1],v[i]);
    }
    for(int i= l+2; i<=r;i++){
        Item m= v[i]; 
        int j= i;
        while(less(m,v[j-1])){
            v[j]=v[j-1]; 
            j--;
        }
        v[j]=m;
    }
}

int main(){
    int *vetor;
    vetor = malloc(50000 * sizeof(int));
    int j=0;

    while(scanf("%d", &vetor[j]) != EOF){
        j++;        
    }
    insertionsort(vetor, 0, j);
    printf("%d",vetor[1]);
    for(int i=2;i<=j;i++)
    {
        printf(" %d",vetor[i]);
    }
    printf("\n");
}