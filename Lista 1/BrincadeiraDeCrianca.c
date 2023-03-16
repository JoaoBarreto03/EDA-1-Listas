#include <stdio.h>

int main(){
    int n, A = 0, B = 0;

    scanf("%d", &n);
    int pi[10001];
    while (n > 0){
        A = 0;
        B = 0;
        if (n < 1 || n > 10000){
            printf("error\n");
            return 0;
        }

        for (int i=0; i<n; i++){
            scanf("%d", &pi[i]);
            if (pi[i] != 0 && pi[i] != 1){
                printf("error\n");
                return 0;
            }

            if (pi[i] == 0){
                A ++;
            }

            if (pi[i] == 1){
                B ++;
            }
        }
        printf("Alice ganhou %d e Beto ganhou %d\n", A, B);
        scanf("%d", &n);
    }
    return 0;
}