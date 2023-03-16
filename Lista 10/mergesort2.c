#include <stdio.h>
#include <stdlib.h>

#define less(A,B) (A.num<B.num)

typedef struct{
    long int num;
}Item;

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
    Item v[100001];
    int quant = 0;
    Item itens[100001];

    while(scanf("%ld", &v[quant].num)!=EOF){
        itens[quant]=v[quant]; 
        quant++;
    }

    mergesort(itens, 0, quant-1);

    for(int i = 0; i<quant; i++){
        printf("%ld ", itens[i].num); 
    }

    printf("\n");

    return 0;
}