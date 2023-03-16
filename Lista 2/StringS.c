#include <stdio.h>


int main(){
    int cod[1000];
    int i=0;
    while(scanf("%x", &cod[i++]) == 1);
    char *a = cod;
    printf("%s\n", a);    
}