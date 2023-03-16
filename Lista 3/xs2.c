#include <stdio.h>


void xs(char *st){
    
    if(st[0] == '\0')return;

    if(st[0] != 'x'){
        printf("%c", st[0]);
    }
    xs(&st[1]);
    if(st[0] == 'x'){
        printf("%c", st[0]);
    }
    
}

int main(){
    char *st[100];
    scanf("%s", &st); 
    xs(&st);
    printf("\n");
}