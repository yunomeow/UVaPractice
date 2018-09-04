#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<queue>
#include<iostream>
using namespace std;
int vis[202][202][202];
struct state{
    int a,b,c;
    int now;
}tmp;
queue<state> q;
int ABSS(int c){
    if(c < 0)return -1 * c;
    return c;
}
int main (){
    int T,a,b,c,target;
    int nowa,nowb,nowc,now,add;
    int nexta,nextb,nextc;
    int i,j,k,n,ans;
    int t;
    int value;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d%d",&a,&b,&c,&target);
        memset(vis,-1,sizeof(vis));
        tmp.a = 0;
        tmp.b = 0;
        tmp.c = c;
        tmp.now = 0;
        vis[0][0][c] = 0;
        q.push(tmp);
        while(!q.empty()){
            nowa = q.front().a;
            nowb = q.front().b;
            nowc = q.front().c;
            now = q.front().now;
           // printf("%d %d %d\n",nowa,nowb,nowc);
            q.pop();
            //b to a
            if(a-nowa > 0){
                if(a-nowa > nowb){
                    nexta = nowa+nowb;
                    nextb = 0;
                    add = nowb;
                }
                else{
                    nexta = a;
                    nextb = nowb - (a-nowa);
                    add = a - nowa;
                }
                nextc = nowc;
                if(vis[nexta][nextb][nextc] == -1){
                    vis[nexta][nextb][nextc] = now + add;
                    tmp.a = nexta;
                    tmp.b = nextb;
                    tmp.c = nextc;
                    tmp.now = now+add;
                    q.push(tmp);
                }
            }
          //  printf("%d %d %d\n",nexta,nextb,nextc);
            //c to a
            if(a-nowa > 0){
                if(a-nowa > nowc){
                    nexta = nowa+nowc;
                    nextc = 0;
                    add = nowc;
                }
                else{
                    nexta = a;
                    nextc = nowc - (a-nowa);
                    add = a - nowa;
                }
                nextb = nowb;
                if(vis[nexta][nextb][nextc] == -1){
                    vis[nexta][nextb][nextc] = now + add;
                    tmp.a = nexta;
                    tmp.b = nextb;
                    tmp.c = nextc;
                    tmp.now = now+add;
                    q.push(tmp);
                }
            }

            //a to b
            if(b-nowb > 0){
                if(b-nowb > nowa){
                    nextb = nowb+nowa;
                    add = nowa;
                    nexta = 0;
                }
                else{
                    nextb = b;
                    nexta = nowa - (b-nowb);
                    add = b - nowb;
                }
                nextc = nowc;
                if(vis[nexta][nextb][nextc] == -1){
                    vis[nexta][nextb][nextc] = now + add;
                    tmp.a = nexta;
                    tmp.b = nextb;
                    tmp.c = nextc;
                    tmp.now = now+add;
                    q.push(tmp);
                }
            }
            //a to c
            if(c-nowc > 0){
                if(c-nowc > nowa){
                    nextc = nowc+nowa;
                    add = nowa;
                    nexta = 0;
                }
                else{
                    nextc = c;
                    nexta = nowa - (c-nowc);
                    add = c - nowc;
                }
                nextb = nowb;
                if(vis[nexta][nextb][nextc] == -1){
                    vis[nexta][nextb][nextc] = now + add;
                    tmp.a = nexta;
                    tmp.b = nextb;
                    tmp.c = nextc;
                    tmp.now = now+add;
                    q.push(tmp);
                }
            }
            //b to c
            if(c-nowc > 0){
                if(c-nowc > nowb){
                    nextc = nowc+nowb;
                    add = nowb;
                    nextb = 0;
                }
                else{
                    nextc = c;
                    nextb = nowb - (c-nowc);
                    add = c - nowc;
                }
                nexta = nowa;
                if(vis[nexta][nextb][nextc] == -1){
                    vis[nexta][nextb][nextc] = now + add;
                    tmp.a = nexta;
                    tmp.b = nextb;
                    tmp.c = nextc;
                    tmp.now = now+add;
                    q.push(tmp);
                }
            }
            //c to b
            if(b-nowb > 0){
                if(b-nowb > nowc){
                    nextb = nowb+nowc;
                    add = nowc;
                    nextc = 0;
                }
                else{
                    nextb = b;
                    nextc = nowc - (b-nowb);
                    add = b - nowb;
                }
                nexta = nowa;
                if(vis[nexta][nextb][nextc] == -1){
                    vis[nexta][nextb][nextc] = now + add;
                    tmp.a = nexta;
                    tmp.b = nextb;
                    tmp.c = nextc;
                    tmp.now = now+add;
                    q.push(tmp);
                }
            }                        
        }
        ans = 10000000;
        t = 10000000;
        for(i=0;i<=a;i++){
            for(j=0;j<=b;j++){
                for(k=0;k<=c;k++){
                    if(vis[i][j][k] != -1){
                        if(i <= target && ABSS(i - target) <= t){
                            if(ABSS(i-target) == t){
                                if(vis[i][j][k] < ans)
                                    ans = vis[i][j][k];
                            }else{
                                t = ABSS(i-target);
                                value = i;
                                ans = vis[i][j][k];
                            }
                        }
                        if(j <= target && ABSS(j - target) <= t){
                            if(ABSS(j-target) == t){
                                if(vis[i][j][k] < ans)
                                    ans = vis[i][j][k];
                            }else{
                                t = ABSS(j-target);
                                value = j;
                                ans = vis[i][j][k];
                            }
                        }
                        if(k <= target && ABSS(k - target) <= t){
                            if(ABSS(k-target) == t){
                                if(vis[i][j][k] < ans)
                                    ans = vis[i][j][k];
                            }else{
                                t = ABSS(k-target);
                                value = k;
                                ans = vis[i][j][k];
                            }
                        }                        
                    }
                }
            }
        }
        printf("%d %d\n",ans,value);
    }
    return 0;    
}
/*
2
2 3 4 2
96 97 199 62
*/
