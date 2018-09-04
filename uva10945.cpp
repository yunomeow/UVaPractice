#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
char s[100000];
char p[100000];
int main (){
    int i,len,k=0;
    int flag;
    while(gets(s)){
        if(strcmp(s,"DONE") == 0)break;
        len = strlen(s);
        k = 0;
        for(i=0;i<len;i++){
            if(isalpha(s[i]) != 0){
                p[k] = tolower(s[i]);
                k++;
            }
        }
        p[k] = '\0';
        //puts(p);
        flag = 1;
        for(i=0;i<k;i++){
            if(p[i] != p[k-i-1])flag = 0;
        }
        if(flag == 1)printf("You won't be eaten!\n");
        else printf("Uh oh..\n");
    }
    return 0;
}
