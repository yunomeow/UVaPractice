#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<queue>
using namespace std;
char MAP[105][105];
int vis[105][105];
struct XD{
    int x,y;
}tmp;
queue<XD> q;
int dir[4][2] = {1,0,0,1,-1,0,0,-1};
int main (){
    int i,flag,cnt,ans,k;
    int j,nx,ny,x,y,nex,ney,n,m;
    char g;
    while(scanf("%d%d",&n,&m) != EOF){
        for(i=0;i<n;i++)scanf("%s",MAP[i]);
        scanf("%d%d",&x,&y);
        g = MAP[x][y];
        memset(vis,0,sizeof(vis));
        ans = 0;
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                if(vis[i][j] == 0 && MAP[i][j] == g){
                    while(!q.empty())q.pop();
                    tmp.x = i;
                    tmp.y = j;
                    vis[i][j] = 1;
                    q.push(tmp);
                    flag = 0;
                    if(i == x && j == y)flag = 1;
                    cnt = 1;
                    while(!q.empty()){
                        nx = q.front().x;
                        ny = q.front().y;
                        q.pop();
                        for(k=0;k<4;k++){
                            nex = nx + dir[k][0];
                            ney = ny + dir[k][1];
                            if(ney == m)ney = 0;
                            if(ney < 0)ney = m-1;
                            if(nex >= 0 && nex < n && ney >= 0 && ney < m){
                                if(vis[nex][ney] == 0 && MAP[nex][ney] == g){
                                    cnt++;
                                    if(nex == x && ney == y)flag = 1;
                                    tmp.x = nex;
                                    tmp.y = ney;
                                    q.push(tmp);
                                    vis[nex][ney] = 1;
                                }
                            }
                        }
                    }
                    if(flag == 0 && cnt > ans)
                        ans = cnt;
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
/*
5 5
wwwww
wwllw
wwwww
wllww
wwwww
1 3
*/
