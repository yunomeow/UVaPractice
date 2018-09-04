#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
typedef long long int64;
const int64 kInf = 210000000000ll;
struct Edge{
    int p;
    int64 c;
    Edge(){
    }
    Edge(int _p,int64 _c){
        p = _p;
        c = _c;
    }
};
vector<Edge> G[10005],rG[10005];
int inq[10005];
int64 dis[10005],rdis[10005];
int main (){
    int Z,N,M,st,ed;
    int a,b,now,nxt;
    int64 c,p;
    cin >> Z;
    while(Z--){
        scanf("%d%d%d%d%lld",&N,&M,&st,&ed,&p);
        for(int i=0;i<=N;i++){
            G[i].clear();
            rG[i].clear();
        }
        for(int i=0;i<M;i++){
            scanf("%d%d%lld",&a,&b,&c);
            G[a].push_back(Edge(b,c));
            rG[b].push_back(Edge(a,c));
        }
        queue<int> q;
        fill(&dis[0],&dis[N+1],kInf);
        fill(&rdis[0],&rdis[N+1],kInf);
        dis[st] = 0;
        rdis[ed] = 0;
        q.push(st);
        while(!q.empty()){
            now = q.front();
            inq[now] = 0;
            q.pop();
            for(int i=0;i<G[now].size();i++){
                nxt = G[now][i].p;
                if(dis[nxt] > dis[now] + G[now][i].c){
                    dis[nxt] = dis[now] + G[now][i].c;
                    if(inq[nxt] == 0){
                        inq[nxt] = 1;
                        q.push(nxt);
                    }
                }
            }
        }

        q.push(ed);
        while(!q.empty()){
            now = q.front();
            inq[now] = 0;
            q.pop();
            for(int i=0;i<rG[now].size();i++){
                nxt = rG[now][i].p;
                if(rdis[nxt] > rdis[now] + rG[now][i].c){
                   rdis[nxt] = rdis[now] + rG[now][i].c;
                    if(inq[nxt] == 0){
                        inq[nxt] = 1;
                        q.push(nxt);
                    }
                }
            }
        }
        int64 ans = -1;
        //for(int i=1;i<=N;i++)cout << dis[i] << "\n";
        for(int i=0;i<=N;i++){
            for(int j=0;j<G[i].size();j++){
                if(dis[i] + rdis[G[i][j].p] + G[i][j].c <= p){
                    ans = max(ans,G[i][j].c);
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
