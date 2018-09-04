#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int matrix[505][505];
int dis[505],vis[505];
int ABS(int a){
    if(a < 0)return -a;
    else return a;
}
int main (){
    int n,m,a,b,c,pos,MIN,x,y,type,ca=0;
    int i,j;
    double tmp,ans;
    while(1){
        scanf("%d%d",&n,&m);
        if(n == 0 && m == 0)break;
        memset(matrix,0,sizeof(matrix));
        memset(vis,0,sizeof(vis));
        for(i=0;i<m;i++){
            scanf("%d%d%d",&a,&b,&c);
            matrix[a][b] = c;
            matrix[b][a] = c;
        }
        for(i=0;i<=n;i++)dis[i] = 10000000;
        dis[1] = 0;
        for(i=0;i<n;i++){
            MIN = 10000000;
            pos = -1;
            for(j=1;j<=n;j++){
                if(dis[j] < MIN && vis[j] == 0){
                    pos = j;
                    MIN = dis[j];
                }
            }
            if(pos == -1)break;
            vis[pos] = 1;
            for(j=1;j<=n;j++){
                if(matrix[pos][j] > 0 && dis[j] > matrix[pos][j] + dis[pos]){
                    dis[j] = matrix[pos][j] + dis[pos];
                }
            }
        }
        ans = -1;
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                if(matrix[i][j] > 0){
                    if(ABS(dis[i] - dis[j]) < matrix[i][j]){
                        if(dis[i] > dis[j]){
                            tmp = dis[i]+(matrix[i][j] - ABS(dis[i] - dis[j]))/2.0;
                        }else{
                            tmp = dis[j]+(matrix[i][j] - ABS(dis[i] - dis[j]))/2.0;
                        }
                        if(tmp > ans){
                            ans = tmp;
                            type = 1;
                            x = i;
                            y = j;
                        }                        
                    }
                }
            }
            if(dis[i] > ans){
                type = 0;
                x = i;
                ans = dis[i];
            }
          //  printf("%d\n",dis[i]);
        }
        ca++;
        printf("System #%d\n",ca);
        if(type == 0)
            printf("The last domino falls after %.1lf seconds, at key domino %d.\n",ans,x);
        else
            printf("The last domino falls after %.1lf seconds, between key dominoes %d and %d.\n",ans,x,y);
        printf("\n");
    }
    return 0;
}
/*
2 1
1 2 27
3 3
1 2 5
1 3 5
2 3 5
0 0
*/
