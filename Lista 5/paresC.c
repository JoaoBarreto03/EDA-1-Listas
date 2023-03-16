#include <stdio.h>

int i=0;
void par(char st[]){
    //i = 0;
    if(st[0] == '\0')return;
    par(&st[1]);
    if(st[0] == st[2]){
        i++;

    }
}

int main(){
    char str[200];
    scanf("%s", &str);
    par(&str);
    printf("%d\n", i);
}