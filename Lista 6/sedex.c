#include <stdio.h>

int main(){
    int diam;
    int a,l,p;

    scanf("%d", &diam);
    scanf("%d %d %d", &a, &l, &p);
    
    if(a>=diam && l>=diam && p>=diam){
        printf("S\n");
    }else{
        printf("N\n");
    }

}