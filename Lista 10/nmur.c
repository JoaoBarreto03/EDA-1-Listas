#include <stdio.h>
#include <stdlib.h>

#define less(A,B) (A<B)

int *intercala(int *v1, int *v2, int l1, int r1, int l2, int r2){
    int *v_ret = malloc(sizeof(int)*((r1-l1+1)+(r2-l2+1)));
    int i1 = l1, i2 = l2, i_ret = 0;

    while(i1<=r1 && i2<=r2){
        if(v1[i1] <= v2[i2]){
            v_ret[i_ret++] = v1[i1++];
        }else{
            v_ret[i_ret++] = v2[i2++];
        }
    }

    while(i1 <= r1){
        v_ret[i_ret++]=v1[i1++];
    } 
    while(i2<=r2){
        v_ret[i_ret++] = v2[i2++];
    }
    return v_ret;
}


int busca(int *vetor, int l, int r, int b){
    if(r<l){
        return -1;
    }
    int meio = (l + r) / 2;
    if (less(vetor[meio],b)){
        return busca(vetor, meio + 1, r, b);
    }else{
        if(less(b, vetor[meio])){
            return busca(vetor, l, meio - 1, b);
        }else{
            return meio;
        }
    }
}

void merge(int *v, int l, int r1, int r2){
    int *v2 = malloc(sizeof(int)*(r2-l+1));
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

void mergesort(int *v, int l, int r){
    int meio = (r+l)/2;
    if(l == r)return;
    mergesort(v, l, meio);
    mergesort(v, meio+1, r);
    merge(v, l, meio, r);
}

int main(){
    int v[200000];
    int N;
    scanf("%d", &N);
    for(int i = 0; i<N; i++){
        scanf("%d", &v[i]);
    }

    mergesort(v, 0, N-1);

    
    int novoi = 0;
   

    for(int i = 1; i<N; i++){
        if(v[i] != v[novoi]){
            v[++novoi] = v[i];
        }
    }
    
    int novor = novoi; 

    if(novor%2 == 0){
        v[++novor] = 1000000000;
    }
    int nmu[66000];
    int nmui = -1;

    for(int i = 0; i< novor; i+=2){
        nmu[++nmui] = v[i]+v[i+1];
        if(busca(v,0,novor,nmu[nmui])!=-1){
            nmui--;
        }
    }
    
    int *c = intercala(v, nmu,0, novor, 0, nmui);

    for(int i = 0; i< (novor+nmui+2); i+=4){
        printf("%d\n", c[i]);
    }
    printf("Elementos: %d\n", (novor+nmui+2));

}