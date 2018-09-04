#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
struct edge{
    int num;
    int next;
}; 
vector<edge> v[50];
int vis[2000],use[1000];
bool cmp(edge a,edge b){
    return a.num < b.num;
}
int first,stack[2000],top;
void find_ans(int pos){
    int i;
    for(i=0;i<v[pos].size();i++){
        if(vis[v[pos][i].num] == 0){
            vis[v[pos][i].num] = 1;
            find_ans(v[pos][i].next);
            stack[top] = v[pos][i].num;
            top++;
        }
    }
} 
int main (){
    int i,a,b,c,st,cnt,flag;
    edge tmp;
    while(1){
        scanf("%d%d",&a,&b);
        if(a == 0 && b == 0)break;
        if(a > b)st = b;
        else st = a;
        for(i=0;i<45;i++)v[i].clear();
        memset(vis,0,sizeof(vis));
        scanf("%d",&c);
        tmp.num = c;
        tmp.next = b;
        v[a].push_back(tmp);
        tmp.next = a;
        v[b].push_back(tmp);
        while(1){
            scanf("%d%d",&a,&b);
            if(a == 0 && b == 0)break;
            scanf("%d",&c);
            tmp.num = c;
            tmp.next = b;
            v[a].push_back(tmp);
            tmp.next = a;
            v[b].push_back(tmp);
        }
        for(i=0;i<45;i++){
            sort(v[i].begin(),v[i].end(),cmp);
        }
        flag = 1;
        for(i=0;i<45;i++)
            if(v[i].size() % 2 == 1)flag = 0;
        first = 0;
        if(flag == 1){
            top = 0;
            find_ans(st);
            for(i=top-1;i>=0;i--){
                if(i != top-1)printf(" ");
                printf("%d",stack[i]);
            }
        }
        if(flag == 0)printf("Round trip does not exist.");
        printf("\n\n");
    }
    return 0;
}
/*
1 2 1
2 3 2
3 1 6
1 2 5
2 3 3
3 1 4
0 0
*/
