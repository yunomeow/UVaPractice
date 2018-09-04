#include<stdio.h>
#include<stdlib.h>
#include<queue>
#include<string.h>
using namespace std;
char MAP[105][105];
int vis[105][105];
int dir[4][2] = {1,0,0,1,-1,0,0,-1};
struct XD{
    int x,y;
}tmp;
queue<XD> q;
int main (){
    int n;
    int i;
    int nowx,nowy,nextx,nexty;
    int j,k,cnt,T,ca=0;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        if(n == 0)break;
        for(i=0;i<n;i++)
            scanf("%s",MAP[i]);
        memset(vis,0,sizeof(vis));

        cnt = 0;
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                if(vis[i][j] == 0 && MAP[i][j] == 'x'){
                    cnt++;
                    tmp.x = i;
                    tmp.y = j;
                    while(!q.empty())q.pop();
                    q.push(tmp);
                    while(!q.empty()){
                        nowx = q.front().x;
                        nowy = q.front().y;
                        q.pop();
                        for(k=0;k<4;k++){
                            nextx = nowx + dir[k][0];
                            nexty = nowy + dir[k][1];
                            if(vis[nextx][nexty] == 0 &&
                               (MAP[nextx][nexty] == '@'||MAP[nextx][nexty] == 'x')){
                                tmp.x = nextx;
                                tmp.y = nexty;
                                vis[nextx][nexty] = 1;
                                q.push(tmp);
                            }
                        }
                    }
                }
            }
        }
        ca++;
        printf("Case %d: %d\n",ca,cnt);
    }
    return 0;
}
