#include <stdio.h>
#include <stdlib.h>

typedef int Item;

    #define less(A,B) (A<B) //macro para compara se o número A é menor que o número B
    #define exch(A,B) {Item tt = A;\
                             A=B;\
                             B=tt;\
                            } //macro que troca o valor de A por B
    #define cmpexch(A,B) {if(less(B,A)) exch(A,B)} //macro que troca os valores se B for maior que A
    #define eq(A,B) (A==B) //macro que ve se A e B são iguais

void merge(Item *v, int l ,int m ,int r){
    int ia= l, ib= m+1;
    Item *aux = (Item*)malloc(sizeof(Item)*(r-l+1));
    int iaux= 0;
    while(ia<=m && ib <= r){
        if(less(v[ib],v[ia])){
            aux[iaux++]=v[ib++];
        }else{
            aux[iaux++] =v[ia++];
        }
    }while(ia<=m){
        aux[iaux++]=v[ia++];
    }while(ib<=r){
        aux[iaux++]=v[ib++];
    }
    for(int i= 0; i< r-l+1;i++){
        v[l++] =aux[i];
    }
}

void mergesort(Item *v,int l, int r){
    if(r-l==0){
        return ;
    }
    int m =(r+l)/2;
    mergesort(v,l,m);
    mergesort(v,m+1,r);
    merge(v,l,m,r);
    
}

int main(){
    int n;//tamanho do vetor
    scanf("%d",&n);//escolhe o tamnho do vetor
    int vetor[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&vetor[i] );//preenche o valor da posição i
    }

    mergesort(vetor, 0, n-1);
    
    for(int i=0;i<n;i++)
    {
        printf("%d\n", vetor[i]);//preenche o valor da posição i
    }

}