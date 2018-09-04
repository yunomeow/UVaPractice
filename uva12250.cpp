#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main (){
    int ca=0;
    char in[10000];
    while(1){
        scanf("%s",in);
        if(strcmp(in,"#") == 0)break;
        ca++;
        printf("Case %d: ",ca);
        if(strcmp(in,"HELLO") == 0)printf("ENGLISH\n");
        else if(strcmp(in,"HOLA") == 0)printf("SPANISH\n");
        else if(strcmp(in,"HALLO") == 0)printf("GERMAN\n");
        else if(strcmp(in,"BONJOUR") == 0)printf("FRENCH\n");
        else if(strcmp(in,"CIAO") == 0)printf("ITALIAN\n");
        else if(strcmp(in,"ZDRAVSTVUJTE") == 0)printf("RUSSIAN\n");
        else printf("UNKNOWN\n");
    }
    return 0;
}
