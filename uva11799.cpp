#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int num[100000];
char input[100000];
int main (){
    int ca=0,T,n;
    int MAX,tmp;
    int x;

    int now,len,num;
    scanf("%d%*c",&T);
    while(T--){
        gets(input);
        len = strlen(input);
       // printf("%d\n",len);
        now = 0;
        MAX = 0;
        while(now < len){
            sscanf(input+now,"%d%n",&num,&tmp);
            //printf("num %d\n",num);
            if(MAX < num)MAX = num;
            now += tmp;
        }
        ca++;
        printf("Case %d: %d\n",ca,MAX);
    }
    return 0;
}
