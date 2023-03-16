#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define less(A, B) (A.quantV == B.quantV ? A.numCandidato > B.numCandidato : A.quantV > B.quantV)

#define exch(A, B)  \
    {               \
        Item t = A; \
        A = B;      \
        B = t;      \
    }

#define cmpexch(A, B) \
    if (less(B, A))   \
    exch(A, B)

typedef struct{
    int numCandidato, quantV;
} Item;

int separa(Item *v, int l, int r)
{
    Item p = v[r];
    int j = l;
    for (int k = l; k < r; k++)
        if (less(v[k], p)){
            exch(v[k], v[j]);
            j++;
        }
    exch(v[j], v[r]);
    return j;
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



Item pres[91], sen[901], depF[9001], depE[90001];

int presN = 0, senN = 0, depFN = 0, depEN = 0;

int main(){

    long long s, f, e;
    
    scanf(" %lld %lld %lld", &s, &f, &e);

    long long numValido = 0, numInvalido = 0, totalp = 0;

    for (int x, l; scanf("%d%n", &x, &l) == 1;){
        if (x < 0){
            numInvalido++;
            continue;
        }
    

        switch(l){
            case 3:
                pres[x - 10].numCandidato = x;
                pres[x - 10].quantV++;
                totalp++;
                break;
            case 4:
                sen[x - 100].numCandidato = x;
                sen[x - 100].quantV++;
                break;
            case 5:
                depF[x - 1000].numCandidato = x;
                depF[x - 1000].quantV++;
                break;
            default:
                depE[x - 10000].numCandidato = x;
                depE[x - 10000].quantV++;
        }
        numValido++;
    }
    
    
    for (int i = 0; i < 91; i++){
        if (pres[i].quantV){
            pres[presN++] = pres[i];
        }
    }
    for (int i = 0; i < 901; i++){
        if (sen[i].quantV){
            sen[senN++] = sen[i];
        }
    }
    for (int i = 0; i < 9001; i++){
        if (depF[i].quantV){
            depF[depFN++] = depF[i];
        }
    }
    for (int i = 0; i < 90001; i++){
        if (depE[i].quantV){
            depE[depEN++] = depE[i];
        }
    }

    printf("%lld %lld\n", numValido, numInvalido);

    quicksort(pres, 0, presN - 1);
    quicksort(sen, 0, senN - 1);
    quicksort(depF, 0, depFN - 1);
    quicksort(depE, 0, depEN - 1);

    if((double)pres[0].quantV / totalp >= .51){
        printf("%d\n", pres[0].numCandidato);
    }else{
        printf("Segundo turno\n");
    }
    for (int i = 0; i < s; i++){
        printf("%d%c", sen[i].numCandidato, " \n"[i == s - 1]);
    }
    for (int i = 0; i < f; i++){
        printf("%d%c", depF[i].numCandidato, " \n"[i == f - 1]);
    }
    for (int i = 0; i < e; i++){
        printf("%d%c", depE[i].numCandidato, " \n"[i == e - 1]);
    }

    return 0;
}