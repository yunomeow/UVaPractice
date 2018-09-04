#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char s[255];
int main (){
    int cnt,i,len,flag;
    while(1){
        gets(s);
        if(strcmp(s,"e/o/i") == 0)break;
        len = strlen(s);
        cnt = 0;
        i = 0;
        flag = 0;
        while(1){
            if(s[i] == '/')break;
            if((s[i] == 'a' || s[i] == 'e' ||s[i] == 'i'||s[i] == 'o'||s[i] == 'u'||s[i] == 'y')){
                if(flag == 0)cnt++;
                flag = 1;
            }else{
                flag = 0;
            }
            i++;
        }
        if(cnt != 5){printf("1\n");continue;}
        cnt = 0;i++;flag = 0;
        while(1){
            if(s[i] == '/')break;
            if((s[i] == 'a' || s[i] == 'e' ||s[i] == 'i'||s[i] == 'o'||s[i] == 'u'||s[i] == 'y')){
                if(flag == 0)cnt++;
                flag = 1;
            }else{
                flag = 0;
            }
            i++;
        }
        if(cnt != 7){printf("2\n");continue;}
        cnt = 0;i++;flag = 0;
        while(i < len){
            if((s[i] == 'a' || s[i] == 'e' ||s[i] == 'i'||s[i] == 'o'||s[i] == 'u'||s[i] == 'y')){
                if(flag == 0)cnt++;
                flag = 1;
            }else{
                flag = 0;
            }
            i++;
        }
        if(cnt != 5){printf("3\n");continue;}  
        printf("Y\n");
    }
    return 0;
}
