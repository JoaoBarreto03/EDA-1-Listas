#include <stdio.h>

int main(){

    int n;
    int golA=0;
    int golB=0;
    int rod=0;

    scanf("%d", &n);

    char quantA[n+1];
    char quantB[n+1];

    int totalpA=n;
    int totalpB=n;

    scanf("%s %s", quantA, quantB);

    for(int i=0; i<n; i++){
        if (quantA[i] == 'o'){
            golA++;
        }

        totalpA--;
        rod++;

        if (golA > golB + totalpB || golB > golA + totalpA){
            break;
        } 

        if (quantB[i] == 'o'){
            golB++;
        }

        totalpB--;
        rod++;
        
        if (golA > golB + totalpB || golB > golA + totalpA){
            break;
        }
    }

    if (golA == golB){
        printf("Empate\n");
    } else{
        printf("%d\n", rod);
    }
}