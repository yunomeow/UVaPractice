#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
int use[100];
char s[100],str[100];
int len,x;
struct XD{
    char s[100];
}ans[10000];

void dfs(int pos){
    if(pos == len){
        s[pos] = '\0';
        //printf("%s\n",s);
        strcpy(ans[x].s,s);
        if(x > 9999)x = 0;
        x++;
        return;
    }

    int i;
    for(i=0;i<len;i++){
        if(use[i] == 0){
            s[pos] = str[i];
            use[i] = 1;
            dfs(pos+1);
            use[i] = 0;
        }
    }
}
bool cmp(XD a,XD b){
    int ta,tb,i=0;
    while(i < len){
        if(a.s[i] >= 'A' && a.s[i] <= 'Z')
            ta = a.s[i] - 'A';
        else if(a.s[i] >= 'a' && a.s[i] <= 'z')
            ta = a.s[i] - 'a';
        if(b.s[i] >= 'A' && b.s[i] <= 'Z')
            tb = b.s[i] - 'A';
        else if(b.s[i] >= 'a' && b.s[i] <= 'z')
            tb = b.s[i] - 'a';
        if(ta != tb)return ta < tb;
        else{
            if(a.s[i] != b.s[i])
                return a.s[i] < b.s[i];
        }
        i++;
    }
    return a.s[i] < b.s[i];
}
int main (){
    int T,i;
    scanf("%d",&T);
    while(T--){
        scanf("%s",str);
        len = strlen(str);
        memset(use,0,sizeof(use));
        x = 0;
        dfs(0);
        //printf("x:%d\n",x);
        //sort(ans,ans+x,cmp);
        for(i=0;i<x;i++){
            if(i == 0 || strcmp(ans[i].s,ans[i-1].s)!=0)
            printf("%s\n",ans[i].s);
        }
    }
    return 0;
}
