#include <stdio.h>


int soma = 0;
void UltraMin(int *v, int limit, int i) {
 
    if(v[i] == 0) {
        return;
    }

    if(v[i] + soma > limit) {
        soma = 0;
        
        UltraMin(v, limit, i + 1);
        printf("%d\n", v[i]);
        return;
    }
    soma += v[i];
    UltraMin(v, limit, i + 1);
}
int main() {

    int v[100] = {0};
    int cont = 0;
    int n, limit;
    do
    {
        scanf("%d", &n);

        if(n != 0)
            v[cont++] =  n;

    } while (n != 0);
    
    scanf("%d", &limit);

    UltraMin(v, limit, 0);
    return 0;
}
