#include <stdio.h>

int f91(int N){
    int M=0;
    int R=0;
    if(N>=101){
        N= N-10;
    }else{
        while(N != 91){
                if(N!=91){
                    M = N+11-10;
                    N = M;
                }else{
                    M=91;
                }
            }
        
    }
    return N;
}

int main(){
    int n=1;
    while(n!=0){
        scanf("%d", &n);
        if(n==0){
            break;
        }
        printf("f91(%d) = %d\n", n, f91(n));
    }

    return 0;

}