#include <stdio.h>

int somaD(long int n)
{
    long int soma;
    if (n == 0){
       return 0;
    }
    soma = n%10 + somaD(n/10);
    return soma;

    
}

int main() 
{
    long int n1;
    scanf("%ld", &n1);
    printf("%ld\n", somaD(n1));
    return 0;
}
