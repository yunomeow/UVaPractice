#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<vector>
#include<iostream>
using namespace std;
vector<int> v[30005];
int cnt;
int vis[30005];
void dfs(int pos){
    int i;
    vis[pos] = 1;
  //  printf("%d ",pos);
    for(i=0;i<v[pos].size();i++){
     //  printf("pos %d pos[i] %d\n",pos,v[pos][i]);
        if(vis[v[pos][i]] == 0){
            cnt++;
//            printf("%d ",v[pos][i]);
            vis[v[pos][i]] = 1;
            dfs(v[pos][i]);
        }
    }
}
int main (){
    int n,m,T,a,b,ans,i;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        for(i=0;i<=n;i++){
            v[i].clear();
        }
        for(i=0;i<m;i++){
            scanf("%d%d",&a,&b);
            v[a].push_back(b);
            v[b].push_back(a);
        }
        /*
        for(i=0;i<15;i++){
            printf("%d : ",i);
            for(int j = 0;j<v[i].size();j++)
                printf("%d ",v[i][j]);
            printf("\n");
        }
        */
        for(i=0;i<=n;i++){
            vis[i] = 0;
        }
        ans = 0;
        for(i=1;i<=n;i++){
            cnt = 0;
            if(vis[i] == 0)
                dfs(i);
            if(cnt > ans)ans = cnt;
           // printf("\n");
        }
        printf("%d\n",ans+1);
    }
    return 0;
}
