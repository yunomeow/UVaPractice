#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char s[100000];
int main (){
    int i,now,len,tmp,ca=0,T,val;
    char ch;
    scanf("%d%*c",&T);
    while(T--){
        gets(s);
        len = strlen(s);
        now = 0;
        ca++;
        printf("Case %d: ",ca);
        while(now < len){
            sscanf(s+now,"%c%d%n",&ch,&val,&tmp);
            now+=tmp;
            for(i=0;i<val;i++)
                printf("%c",ch);
        }
        printf("\n");
    }
    return 0;
}
