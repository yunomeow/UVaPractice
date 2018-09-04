#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int R[105][105],flag,flow,n,minus,vis[105];
void dfs(int t,int pos,int nowMIN){
    int i;
    if(pos == t){
        flow += nowMIN;
        minus = nowMIN;
        flag = 1;
        return;
    }
    vis[pos] = 1;
    for(i=1;i<=n;i++){
        if(R[pos][i] > 0 && vis[i] == 0){
            if(nowMIN > R[pos][i])nowMIN = R[pos][i];
            dfs(t,i,nowMIN);
        }
        if(flag == 1)break;
    }
    R[pos][i] -= minus;
    R[i][pos] += minus;
}
int main(){
    int i,s,t,m,a,b,c,ca=0;
    while(1){
        scanf("%d",&n);
        if(n == 0)break;
        memset(R,0,sizeof(R));
        scanf("%d%d%d",&s,&t,&m);
        for(i=0;i<m;i++){
            scanf("%d%d%d",&a,&b,&c);
            R[a][b] += c;
            R[b][a] += c;
        }
        flag = 1;
        flow = 0;
        while(flag == 1){
            flag = 0;
            memset(vis,0,sizeof(vis));
            dfs(t,s,100000000);
        }
        ca++;
        printf("Network %d\nThe bandwidth is %d.\n\n",ca,flow);
    }
    return 0;
}
