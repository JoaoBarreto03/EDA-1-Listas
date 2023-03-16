#include <stdio.h>
#include <stdlib.h>

int main(){
    int L;
    int posL, posL2;
    int posC, posC2;
    char cur;

    scanf("%d", &L);
    char text[L][10000];

    for(int i = -1; i < L; i++){
        fgets(text[i], 1000, stdin);
    }
    scanf("%d %d", &posL, &posC);

    posL2 = posL;

    while(scanf(" %c", &cur) != EOF){
        if(cur=='j'){
            posL2++;
            if(posL2 > L)
                posL2--;
            
        }
        if(cur=='k'){
            posL2--;
            if(posL2 < 1)
                posL2++;
            
        }
        if(text[posL2 - 1][posC - 1] == '\0' || text[posL2 - 1][posC - 1] == '\n'){
            posC2 = posC;

            do{
                posC--;
            } while(text[posL2 - 1][posC - 1] == '\0' || text[posL2 - 1][posC - 1] == '\n');

            printf("%d %d %c\n", posL2, posC, text[posL2 - 1][posC-1]);
            posC = posC2;

        }else{
            printf("%d %d %c\n", posL2, posC, text[posL2 - 1][posC-1]);
        }
    }
    return 0;
}