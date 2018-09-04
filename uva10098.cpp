#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<set>
#include<iostream>
using namespace std;
int use[14],n;
char s[14],tmp[14];
void dfs(int pos){
    int i,val;
    string old;
    char pre = 0;
    if(pos == n){
        tmp[pos] = '\0';
        printf("%s\n",tmp);
        return ;
    }
    for(i=0;i<n;i++)
        
        if(use[i] == 0){
            if(pre == s[i])continue;
            pre = s[i];
            tmp[pos] = s[i];
            use[i] = 1;
            dfs(pos+1);
            use[i] = 0; 
        }
}
int main (){
    int T,flag = 0,t,i,j;
    scanf("%d%*c",&T);
    while(T--){
       // if(flag == 1)printf("\n");
        flag = 1;
        scanf("%s",s);
        n = strlen(s);
        for(i=0;i<n;i++)
            for(j=i+1;j<n;j++)
                if(s[i] > s[j]){
                    t = s[i] ;
                    s[i] = s[j];
                    s[j] = t;
                }
        memset(use,0,sizeof(use));
        dfs(0);
        printf("\n");
    }
    return 0;
}
