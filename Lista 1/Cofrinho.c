#include <stdio.h>
#include <stdlib.h>

int main(){
    int N=0;
    int cont=0;
    int J[100], Z[100];
    int result[100];

        scanf("%d", &N);
        //printf("Teste %d\n", cont);
    while(N!=0){

            cont=0;
        for(int i=0; i<10001; i++){
            for(int j=0; j<N; j++){  
                scanf("%d", &J[i]);
                scanf("%d", &Z[i]);
                result[i] = J[i]-Z[i];
                
            }
            cont ++;
            printf("teste %d\n", cont);
            for(int i=0; i<N; i++){
                printf("%d\n", result[i]);
            }
            scanf("%d", &N);
            if(N==0){
                return 0;
            }
            if((N<0) || (N>10000)){
                printf("erro\n");
                return 0;
            }
            if((J[i]<0) || (J[i]>10000)){
                printf("erro\n");
                return 0;
            }
            if((Z[i]<0) || (Z[i]>10000)){
                printf("erro\n");
                return 0;
            }
            
        }

    }
        return 0;
}