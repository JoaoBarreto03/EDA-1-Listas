#include <stdio.h>
#include <stdlib.h>

typedef int Item;
#define less(A,B) (A<B)
#define exch(A,B) { Item tt=A;\
                    A=B;\
                    B=tt;}
#define cmpexch(A,B){if(less(B, A)){exch(A,B)}}

int separa(Item *v, int l, int r){
    Item p = v[r];
    int i = l-1, j = r;
    for( ; ; ){
        while(less(v[++i], p));
        while(less(p, v[--j]))
        if(j == l) break;
        if(i>=j) break;
        exch(v[i], v[j]);
    }
    exch(v[i], v[r]);
    return i;
}

void quicksort(Item *v, int l, int r){
    if(l>=r) return;
    exch(v[(l+r)/2], v[r-1]);
    cmpexch(v[l], v[r]);
    cmpexch(v[l], v[r-1]);
    cmpexch(v[r-1], v[r]);
    int j = separa(v, l, r);
    quicksort(v, l, j-1);
    quicksort(v, j+1, r);
}

int main(){
    int n;
    scanf("%d", &n);

    int *v = (int *)malloc(sizeof(int) * (2 * n));

    for (int i = 0; i < n; i++){
        scanf(" %d", v + i);
    }

    quicksort(v,0, n-1);

    printf("%d", v[0]);
    for (int i = 1; i < n; i++){
        printf(" %d", v[i]);
    }
    
    printf("\n");

    return 0;
}