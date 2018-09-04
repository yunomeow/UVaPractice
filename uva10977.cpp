#include<stdio.h>
#include<stdlib.h>
#include<queue>
#include<iostream>
#include<string.h>
using namespace std;
struct state{
    int x,y,step;
}tmp;
queue<state> q;
int MAP[205][205],vis[205][205];
int dir[4][2] = {0,1,1,0,-1,0,0,-1};
int main (){
    int R,C,m,n;
    int a,b,L;
    int nowx,nowy,nowstep,nx,ny;
    int k,ans,flag,i;
    while(1){
        scanf("%d%d",&R,&C);
        if(R == 0 && C == 0)break;
        scanf("%d",&n);
        memset(MAP,0,sizeof(MAP));
        for(i=0;i<n;i++){
            scanf("%d%d",&a,&b);
            MAP[a][b] = 1;
        }
        scanf("%d",&m);
        for(i=0;i<m;i++){
            scanf("%d%d%d",&a,&b,&L);
            while(!q.empty())q.pop();
            memset(vis,0,sizeof(vis));
            tmp.x = a;
            tmp.y = b;
            tmp.step = 0;
            vis[a][b] = 1;
            MAP[a][b] = 1;
            q.push(tmp);
            while(!q.empty()){
                nowstep = q.front().step;
                nowx = q.front().x;
                nowy = q.front().y;
                q.pop();
                for(k=0;k<4;k++){
                    nx = nowx + dir[k][0];
                    ny = nowy + dir[k][1];
                    if(nx > 0 && ny > 0 && nx <= R && ny <= C){
                        if(vis[nx][ny] == 0 && (a - nx)*(a - nx) + (b - ny) * (b - ny) <= L*L){
                            tmp.x = nx;
                            tmp.y = ny;
                            tmp.step = nowstep + 1 ;
                            MAP[nx][ny] = 1;
                            vis[nx][ny] = 1;
                            q.push(tmp);
                        }
                    }
                }
            }
        }
        while(!q.empty())q.pop();
        memset(vis,0,sizeof(vis));
        tmp.x = 1;
        tmp.y = 1;
        tmp.step = 0;
        vis[1][1] = 1;
        MAP[1][1] = 1;
        q.push(tmp);
        flag = 0;
        while(!q.empty()){
            nowstep = q.front().step;
            nowx = q.front().x;
            nowy = q.front().y;
            q.pop();
            for(k=0;k<4;k++){
                nx = nowx + dir[k][0];
                ny = nowy + dir[k][1];
                if(nx > 0 && ny > 0 && nx <= R && ny <= C){
                    if(vis[nx][ny] == 0 && MAP[nx][ny] == 0){
                        tmp.x = nx;
                        tmp.y = ny;
                        tmp.step = nowstep + 1;
                        MAP[nx][ny] = 1;
                        vis[nx][ny] = 1;
                        q.push(tmp);
                        if(nx == R && ny == C){
                            flag = 1;
                            ans = nowstep + 1;
                            break;
                        }
                    }
                }
            }
            if(flag == 1)break;
        }        
        if(flag == 1)
            printf("%d\n",ans);
        else
            printf("Impossible.\n");
        
    }
    return 0;
}
/*
5 5
5
1 2
1 3
1 4
1 5
2 5
1
4 3 1
0 0
*/
