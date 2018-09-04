#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
int MAP[30][30];
int MAP2[30][30];
char s1[30],s2[30];
char word[30][30];
int vis[30];
int now,n,m;
int t[30];
void dfs(int pos){
    int i;
    vis[pos] = 1; 
    for(i=0;i<n;i++){
        if(vis[i] == 0 && MAP[pos][i] == 1){
            dfs(i);
        }
    }
    t[now] = pos;
    now++;
}
int flag;
void dfs2(int pos){
    int i;
    vis[pos] = 1; 
    if(flag == 1)printf(", ");
    printf("%s",word[pos]);
    flag = 1;
    for(i=0;i<n;i++){
        if(vis[i] == 0 && MAP2[pos][i] == 1){
            dfs2(i);
        }
    }
}
int main(){
    int i,j,x,a,b,ca =0,sp=0;
    while(1){
        scanf("%d%d",&n,&m);
        if(n == 0 && m == 0)break;
        if(sp == 1)printf("\n");
        sp = 1;
        memset(MAP,0,sizeof(MAP));
        memset(MAP2,0,sizeof(MAP2));
        x = 0;
        for(i=0;i<m;i++){
            scanf("%s%s",s1,s2);
            a = -1;
            for(j=0;j<x;j++){
                if(strcmp(s1,word[j]) == 0){
                    a = j;
                    break;
                }
            }
            if(a == -1){
                strcpy(word[x],s1);
                a = x;
                x++;
            }
            b = -1;
            for(j=0;j<x;j++){
                if(strcmp(s2,word[j]) == 0){
                    b = j;
                    break;
                }
            }
            if(b == -1){
                strcpy(word[x],s2);
                b = x;
                x++;
            }
            MAP[a][b] = 1;
            MAP2[b][a] = 1;
        }
        //end input
        now = 0;
        memset(vis,0,sizeof(vis));
        for(i=0;i<n;i++){
            if(vis[i] == 0){
                dfs(i);
            }
        }
        ca++;
        printf("Calling circles for data set %d:\n",ca);
        memset(vis,0,sizeof(vis));
        for(i=n-1;i>=0;i--){
            if(vis[t[i]] == 0){
                flag = 0;
                dfs2(t[i]);
                printf("\n");
            }
        }

    }
    return 0;
}
/*
5 6
Ben Alexander
Alexander Dolly
Dolly Ben
Dolly Benedict
Benedict Dolly
Alexander Aaron
*/
