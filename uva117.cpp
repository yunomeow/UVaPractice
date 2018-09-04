#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<vector>
#include<queue>
using namespace std;
struct Edge{
    int p,c;
}tmp;
vector<Edge> v[100];
queue<int> q;
int inq[100];
int dis[100];
char in[10000];
int main (){
    int len,i,j;
    int st,ed,now;
    int ans;
    while(scanf("%s",in) != EOF){
        ans = 0;
        for(i=0;i<26;i++){
            v[i].clear();
        }
        while(1){
            if(strcmp(in,"deadend") == 0)break;
            len = strlen(in);
            ans += len;
            tmp.c = len;
            tmp.p = in[len-1]-'a';
            v[in[0]-'a'].push_back(tmp);
            tmp.p = in[0]-'a';
            v[in[len-1]-'a'].push_back(tmp);
            scanf("%s",in);
        }
        while(!q.empty())q.pop();
        memset(inq,0,sizeof(inq));
        st = -1;ed = -1;
        for(i=0;i<26;i++){
            if(v[i].size() % 2 == 1){
                if(st == -1)
                    st = i;
                else
                    ed = i;
            }
        }
        if(ed != -1){
            for(i=0;i<26;i++)dis[i] = 100000000;
            dis[st] = 0;
            q.push(st);
            inq[st] = 1;
            while(!q.empty()){
                now = q.front();
                q.pop();
                inq[now] = 0;
                for(i=0;i<v[now].size();i++){
                    if(dis[v[now][i].p] > dis[now] + v[now][i].c){
                        dis[v[now][i].p] = dis[now] + v[now][i].c;
                        if(inq[v[now][i].p] == 0){
                            inq[v[now][i].p] = 1;
                            q.push(v[now][i].p);
                        }
                    }
                }
            }
            ans += dis[ed];
        }
        printf("%d\n",ans);
    }
    return 0;
}
/*
one
two
three
deadend
*/

