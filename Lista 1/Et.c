#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char name[30];
    int i=0;
    
    while(scanf("%s", &name) != EOF){
        if(strcmp(name, "marte") == 0){
            i++;
        }
    }
    if(i>0){
        printf("Leonardo Cicero Marciano\n");
    }else{
        printf("none\n");
    }

    return 0;
}