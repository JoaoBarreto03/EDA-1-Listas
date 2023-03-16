#include <stdio.h>

void isc(char *st){
    
    if(st[0] == '\0')return;

    isc(&st[1]);
    printf("%c", st[0]);
   
    
    
}

int main(){
    char *st[500];
    scanf("%s", &st); 
    isc(&st);
    printf("\n");
}