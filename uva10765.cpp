#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
int vis[10005];
vector<int>v[10005];
struct shik{
    int num,val;
}data[10005];
bool cmp(shik a,shik b){
    if(a.val == b.val)return a.num < b.num;
    return a.val > b.val;
}
int n;
void dfs(int pos){
    int i;
    vis[pos] = 1;
    for(i=0;i<v[pos].size();i++){
        if(vis[v[pos][i]] == 0){
            dfs(v[pos][i]);
        }
    }
}
int main (){
    int i,m;
    int a,b,cnt,j;
    while(1){
        scanf("%d%d",&n,&m);
        if(n == 0 && m == 0)break;
        while(1){
            scanf("%d%d",&a,&b);
            if(a == -1 && b == -1)break;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        for(i=0;i<n;i++){
            cnt = 0;
            memset(vis,0,sizeof(vis));
            vis[i] = 1;
            for(j=0;j<n;j++){
                if(vis[j] == 0){
                    dfs(j);
                    cnt++;
                }
            }
            data[i].num = i;
            data[i].val = cnt;
        }
        sort(data,data+n,cmp);
        for(i=0;i<m;i++)
            printf("%d %d\n",data[i].num,data[i].val);
        printf("\n");
    }
    return 0;
}
/*
8 4
0 4
1 2
2 3
2 4
3 5
3 6
3 7
6 7
-1 -1
0 0
*/
