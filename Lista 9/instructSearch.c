#include <stdio.h>
#include <stdlib.h>

#define less(A,B) (A.num<B.num)

typedef struct{
    int num;
    char instruct[15];
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

int bb(Item *vetor, int l, int r, int b){
    int meio = (l+r)/2;
    if(l>r){
        printf("undefined\n");
        return -1; 
    }
    if(vetor[meio].num == b){
        printf("%s\n", vetor[meio].instruct);
        return meio;
    }else{
        if(vetor[meio].num < b){
            return bb(vetor, meio + 1, r, b);
        }else{
            if(vetor[meio].num > b){
                return bb(vetor, l, meio - 1, b);
            }
        }
    }

}


int main(){
    int n;
    int quant = 0;
    int cod_instruct[1000000];
    Item itens;
    scanf("%d", &n);
    Item inst[n];

    for(int i = 0; i < n; i++){
        scanf("%d %s", &itens.num, itens.instruct);
        inst[i] = itens;
    }
    mergesort(inst, 0, n-1);      
    for (int i = 0; i < 1000000; i++){
        if (scanf("%d", &cod_instruct[i]) == EOF){
            break;
        }          
        quant++;
    }
    for (int i = 0; i < quant; i++) {
        bb(inst, 0, n, cod_instruct[i]);
    }
    return 0;
}  


