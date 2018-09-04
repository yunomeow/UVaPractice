#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
struct shik{
    int num;
    char s[100];
}data[1000005];
bool cmp(shik a,shik b){
    return a.num < b.num;
}
char s[1000005];
int main (){
    int i,T,flag=0,now,tmp,n,len;
    char ch;
    scanf("%d%*c",&T);
    while(T--){
        scanf("%c",&ch);
        if(flag == 1)printf("\n");
        flag = 1;
        gets(s);
        len = strlen(s);
        now = 0;
        i = 0;
        while(now < len){
            sscanf(s+now,"%d%n",&data[i].num,&tmp);
            now+=tmp;
            i++;
        }
        n = i;
        i = 0;
        now = 0;
        gets(s);
        len = strlen(s);
        while(now < len){
            sscanf(s+now,"%s%n",data[i].s,&tmp);
       //     printf("--%s--\n",data[i].s);
            now+=tmp;
            i++;
        }
        sort(data,data+n,cmp);
        for(i=0;i<n;i++){
            printf("%s\n",data[i].s);
        }
    }
    return 0;
}
