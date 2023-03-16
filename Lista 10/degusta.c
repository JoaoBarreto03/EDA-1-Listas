#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define less(A,B) (A.quant<B.quant)

typedef struct Item{
    int quant;
    char nota;
    int pos;
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
    int aux = 0, cont = 0;
    char st[100001];

    scanf("%s", st);

    Item sb[strlen(st)];
    sb[cont].quant = 0;

    for(int i=0; i<strlen(st); i++){
        if(st[aux] != st[i]){
            aux = i;
            cont++;
            sb[cont].quant = 0;
        }
        sb[cont].quant++;
        sb[cont].nota = st[aux];
        sb[cont].pos = aux;
    }

    mergesort(sb, 0, cont);

    for(int i=cont; i>=0; i--){
        printf("%d %c %d\n", sb[i].quant, sb[i].nota, sb[i].pos);
    }

    return 0;
}