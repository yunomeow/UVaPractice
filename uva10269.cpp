#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int dp[105][105];
int dis[12][105];
int matrix[12][12][105][105];
int vis[12][105];
int main(){
    int A,B,T,L,K,M;
    int i,j,k;
    int a,b,c;
    int pos,MIN,level,ans;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d%d%d",&A,&B,&M,&L,&K);
        memset(matrix,-1,sizeof(matrix));
        for(i=0;i<M;i++){
            scanf("%d%d%d",&a,&b,&c);
            for(k=0;k<=K;k++){
                matrix[k][k][a][b] = c;
                matrix[k][k][b][a] = c;
            }
        }
        for(i=0;i<=A+B;i++){
            for(j=0;j<=A+B;j++){
                if(matrix[0][0][i][j] != -1)
                    dp[i][j] = matrix[0][0][i][j];
                else
                    dp[i][j] = 2100000;
            }
        }
        for(i=0;i<=A+B;i++){
            dp[i][i] = 0;
        }
        //floyd-warshell
        for(k=1;k<=A+B;k++){
            for(i=1;i<=A+B;i++){
                for(j=1;j<=A+B;j++){
                    if(k <= A || k == i){
                        if(dp[i][k] + dp[k][j] < dp[i][j]){
                            dp[i][j] = dp[i][k] + dp[k][j];
                        }
                    }
                }
            }
        }
        //find short-cut
        for(i=1;i<=A+B;i++){
            for(j=1;j<=A+B;j++){
                if(i != j && dp[i][j] <= L){
                    //printf("i %d j %d\n",i,j);
                    for(k=0;k<K;k++){
                        matrix[k][k+1][i][j] = 0;
                    }
                }
            }
        }
        //dijkstra
            for(k=0;k<=K;k++)
                for(i=0;i<=A+B;i++)
                    dis[k][i] = 2100000000;
        memset(vis,0,sizeof(vis));
        dis[0][A+B] = 0;
        while(1){
            pos = -1;
            MIN = 2100000000;
            for(k=0;k<=K;k++){
                for(j=1;j<=A+B;j++){
                    if(MIN > dis[k][j] && vis[k][j] == 0){
                        MIN = dis[k][j];
                        pos = j;
                        level = k;
                    }
                }
            }
            if(pos == -1)break;
            vis[level][pos] = 1;
            for(j=1;j<=A+B;j++){
                if(matrix[level][level][pos][j] != -1 &&
                matrix[level][level][pos][j] + dis[level][pos] < dis[level][j]){
                    dis[level][j] = matrix[level][level][pos][j] + dis[level][pos];
                }
                if(matrix[level][level+1][pos][j] != -1 &&
                matrix[level][level+1][pos][j] + dis[level][pos] < dis[level+1][j]){
                    dis[level+1][j] = matrix[level][level+1][pos][j] + dis[level][pos];
                }
            }
        }
        ans = 2100000000;
        
        for(k=0;k<=K;k++){
            if(dis[k][1] < ans)ans = dis[k][1];
        //    printf("%d: %d\n",k,dis[k][1]);
        }
        /*
        for(k=0;k<=K;k++){
            for(i=1;i<=A+B;i++){
                printf("%7d ",dis[k][i]);
            }
            printf("\n");
        }*/
        printf("%d\n",ans);
    }
    return 0;
}
/*
1
4 2 6 9 1
4 6 1
5 6 10
4 5 5
3 5 4
2 3 4
1 2 3
*/
