#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char word[10005][105];
int main (){
    char ch,s[105],stmp[105];
    int flag =0,tmp = 0,x = 0,len = 0,i,app;
    while(1){
        ch = getchar();
        if(ch == EOF)break;
        if(ch >= '0' && ch <= '9'){
            flag = 1;
            tmp = tmp * 10 + ch - 48;
        }else{
            if(flag == 1){
                if(tmp == 0)break;
                printf("%s",word[x-tmp]);
                for(i=x-tmp;i<x-1;i++){
                    strcpy(stmp,word[i]);
                    strcpy(word[i],word[i+1]);
                    strcpy(word[i+1],stmp);                
                }
                tmp = 0;
                flag = 0;
            }
            if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')){
                s[len] = ch;
                len ++;
                flag = 2;
            }else{
                if(flag == 2){
                    s[len] = '\0';
                    len = 0;
                    strcpy(word[x],s);
                    x++;
                }
                flag = 0;
            }
            putchar(ch);
        }

    }        
    return 0;
}
