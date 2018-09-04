#include<stdio.h>
#include<stdlib.h>
#include<queue>
#include<string.h>
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
    while(1){
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
                    while(!q.empty()){
                    }
                }
            }
        }
        printf("%d\n",cnt);
    }
    return 0;
}
