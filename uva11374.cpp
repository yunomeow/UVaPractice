#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int dis[2][505];
int matrix[2][505][2][505];
struct State{
    int x,y;
}par[2][505],pos;
int vis[2][505];
int order[50005];
int main (){
    int n,st,ed;
    int m,k;
    int i,j;
    int a,b,c;
    int MIN;
    int nowx,nowy,use,cnt,nextx,nexty,ans;
    int flag=0;
    while(scanf("%d%d%d",&n,&st,&ed) != EOF){
        if(flag == 1)printf("\n");
        flag = 1;
        scanf("%d",&m);
        memset(matrix,0,sizeof(matrix));
        for(i=0;i<m;i++){
            scanf("%d%d%d",&a,&b,&c);
            if(matrix[0][a][0][b] == 0){
                matrix[0][a][0][b] = c;
                matrix[1][a][1][b] = c;
                matrix[0][b][0][a] = c;
                matrix[1][b][1][a] = c;
            }else if(matrix[0][a][0][b] > c){
                matrix[0][a][0][b] = c;
                matrix[1][a][1][b] = c;
                matrix[0][b][0][a] = c;
                matrix[1][b][1][a] = c;
            }
        }
        scanf("%d",&k);
        for(i=0;i<k;i++){
            scanf("%d%d%d",&a,&b,&c);
            if(matrix[0][a][1][b] == 0){
                matrix[0][a][1][b] = c;
                matrix[0][b][1][a] = c;
            }else if(matrix[0][a][1][b] > c){
                matrix[0][a][1][b] = c;
                matrix[0][b][1][a] = c;
            }
        }
        for(i=0;i<=n;i++){
            dis[0][i] = 100000000;
            dis[1][i] = 100000000;
        }
        //printf("end\n");
        memset(vis,0,sizeof(vis));
        dis[0][st] = 0;
        for(i=0;i<=2*n;i++){
            pos.x = -1;
            MIN = 100000000;
            for(j=0;j<=n;j++){
                if(vis[0][j] == 0 && dis[0][j] < MIN){
                    pos.x = 0;
                    pos.y = j;
                    MIN = dis[0][j];
                }
                if(vis[1][j] == 0 && dis[1][j] < MIN){
                    pos.x = 1;
                    pos.y = j;
                    MIN = dis[1][j];
                }
            }
            if(pos.x == -1)break;
            vis[pos.x][pos.y] = 1;
            //printf("pos.x %d pox.y %d %d\n",pos.x,pos.y,dis[pos.x][pos.y]);
            for(j=1;j<=n;j++){
                if(pos.x == 0){
                    if(matrix[0][pos.y][0][j] > 0 &&
                       matrix[0][pos.y][0][j] + dis[pos.x][pos.y]
                       < dis[0][j]){
                        dis[0][j] = matrix[0][pos.y][0][j] + dis[pos.x][pos.y];
                        par[0][j].x = pos.x;
                        par[0][j].y = pos.y;
                    }
                    if(matrix[0][pos.y][1][j] > 0 &&
                       matrix[0][pos.y][1][j] + dis[pos.x][pos.y]
                       < dis[1][j]){
                        dis[1][j] = matrix[0][pos.y][1][j] + dis[pos.x][pos.y];
                        par[1][j].x = pos.x;
                        par[1][j].y = pos.y;
                    }
                }else{
                    if(matrix[1][pos.y][1][j] > 0 &&
                       matrix[1][pos.y][1][j] + dis[pos.x][pos.y]
                       < dis[1][j]){
                        dis[1][j] = matrix[1][pos.y][1][j] + dis[pos.x][pos.y];
                        par[1][j].x = pos.x;
                        par[1][j].y = pos.y;
                    }
                }
            }
        }
        //printf("end d\n");
        if(dis[0][ed] < dis[1][ed]){
            nowx = 0;
            nowy = ed;
            ans = dis[0][ed];
        }else{
            nowx = 1;
            nowy = ed;
            ans = dis[1][ed];
        }
        //printf("%d %d %d\n",nowx,nowy,ans);
        cnt = 0;
        use = -1;
        while(nowx != 0 || nowy != st){
            order[cnt] = nowy;
            cnt++;
            nextx = par[nowx][nowy].x;
            nexty = par[nowx][nowy].y;
            if(nowx != nextx){
                use = nexty;
            }
            nowx = nextx;
            nowy = nexty;
        }
        printf("%d",st);
        for(i=cnt-1;i>=0;i--){
            printf(" %d",order[i]);
        }
        printf("\n");
        if(use != -1)printf("%d\n",use);
        else printf("Ticket Not Used\n");
        printf("%d\n",ans);
    }
    return 0;
}
