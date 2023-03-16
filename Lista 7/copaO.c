#include <stdio.h>

int main(){
    int result[9];
    int result2[9];
    char win8[9];
    int i;
    int Ltime=65;

    for(i=0;i<8;i++){
        scanf("%d%d",&result[i], &result2[i]);
        if(result[i]>result2[i]){
            win8[i]=Ltime+i;
        }else{
            win8[i]=Ltime+i+1;
        }
        Ltime++;
    }
    
    char win4[5];
    int time1=0, time2=1;
    int win=1;

    for(i=0; i<4;i++){
        scanf("%d%d", &result[i],&result2[i]);
        if(result[i]>result2[i]){
            win4[i]=win8[time1];
        }else{
            win4[i]=win8[time2];
        }
        time1=win+i+1;
        time2=time1+1;
        win++;
    }

    char Rfinal[3];
    time1=0, time2=1;
    win=1;

    for(i=0;i<2;i++){
        scanf("%d%d", &result[i], &result2[i]);
        if(result[i]>result2[i]){
            Rfinal[i]=win4[time1];
        }else{

         Rfinal[i]=win4[time2];
        }
        time1=win+1+i;
        time2=time1+1;
        win++;
    }

    scanf("%d%d", &result[0], &result2[0]);
    
    if(result[0]>result2[0]){
        printf("%c\n", Rfinal[0]);

    }else{
        printf("%c\n", Rfinal[1]);
    }
}