#include <stdio.h>


void xy(char str[80]){
    //char c = 'y';
    if(str[0] == '\0')return;

    if(str[0] == 'x'){
        str[0] = 'y';
    }
    
    if(str[0] != 'x'){
        printf("%c", str[0]);
    }   
  
        xy(&str[1]);
    
}

int main(){
    char str[80];
    scanf("%s", &str);
    xy(&str);
    printf("\n");
}