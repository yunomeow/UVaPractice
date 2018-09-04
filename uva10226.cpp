#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<iostream>
#include<string.h>
using namespace std;
struct skyly{
    char name[40];
}data[1000005];
bool cmp(skyly a,skyly b){
    int len1,len2,i=0;
    len1 = strlen(a.name);
    len2 = strlen(b.name);
    while(i < len1 && i < len2){
        if(a.name[i] != b.name[i])
            return a.name[i] < b.name[i];
        i++;
    }
    return len1 < len2;
}
int main (){
    int T,i,len,cnt,tmp,flag = 0;
    char s[40];
    scanf("%d%*c%*c",&T);
    while(T--){
        if(flag == 1)printf("\n");
        flag = 1;
        cnt = 0;
        while(gets(s)){
            if(strcmp(s,"") == 0)break;
            len = strlen(s);
            for(i=0;i<=len;i++)
                data[cnt].name[i] = s[i];
            cnt++;
        }
        sort(data,data+cnt,cmp);
        data[cnt].name[0] = 0;
        tmp = 1;
        for(i=1;i<=cnt;i++){
            if(strcmp(data[i].name,data[i-1].name) == 0)tmp++;
            else{
                printf("%s %.4lf\n",data[i-1].name,100*(double)tmp/(double)cnt);
                tmp = 1;
            }
        }
    }
    return 0;
}

