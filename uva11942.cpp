#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int num[100];
int main (){
    int T,i;
    int now,len,x,tmp;
    char input[1000];
    int flag1,flag2;
    scanf("%d%*c",&T);
    printf("Lumberjacks:\n");
    while(T--){
        now = 0;
        x = 0;
        gets(input);
        len = strlen(input);
        while(now < len){
            sscanf(input+now,"%d%n",&num[x],&tmp);
            now += tmp;
            x++;
        }
        flag1 = 1;
        for(i=0;i<x-1;i++){
            if(num[i] > num[i+1])flag1 = 0;
        }
        flag2 = 1;
        for(i=0;i<x-1;i++){
            if(num[i] < num[i+1])flag2 = 0;
        }
        if(flag1 == 1 || flag2 == 1){
            printf("Ordered\n");
        }else
            printf("Unordered\n");
    }
    return 0;
}
/*
3
13 25 39 40 55 62 68 77 88 95
88 62 77 20 40 10 99 56 45 36
91 78 61 59 54 49 43 33 26 18



Ordered
*/
