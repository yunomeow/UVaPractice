#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>
using namespace std;
const int kInf = 2100000000;
int ci[1005],N,M;
struct Edge{
    int p,d;
    Edge(int _p,int _d):p(_p),d(_d){};
};
vector< Edge >v[1005];
struct XD{
    int a,b,c;
    XD(int _a,int _b,int _c):a(_a),b(_b),c(_c){};
    bool operator < (const XD b)const{
        return c > b.c;
    }
};
priority_queue<XD> pq;
int dis[1005][105],use[1005][105];
void solve(){
    int st,ed,C,val;
    int nowV,nowC,nowD,nxtV,d;
    cin >> C >> st >> ed;
    fill(&dis[0][0],&dis[N+1][0],kInf);
    fill(&use[0][0],&use[N+1][0],0);
    dis[st][0] = 0;
    while(!pq.empty())pq.pop();
    use[st][0] = 1;
    pq.push(XD(st,0,0));
    while(!pq.empty()){
        nowV = pq.top().a;
        nowC = pq.top().b;
        nowD = pq.top().c;
        use[nowV][nowC] = 1;
        if(nowV == ed && nowC == 0)break;
        pq.pop();
        if(nowD > dis[nowV][nowC])continue;
        nxtV = nowV;
        if(nowC+1 <= C && dis[nxtV][nowC+1] > nowD + ci[nowV]){
            dis[nxtV][nowC+1] = nowD + ci[nowV];
            pq.push(XD(nxtV,nowC+1,dis[nxtV][nowC+1]));
        }
        for(int i=0;i<v[nowV].size();i++){
            nxtV = v[nowV][i].p;
            d = v[nowV][i].d;
            if(nowC - d >= 0 && dis[nxtV][nowC - d] > nowD){
                dis[nxtV][nowC-d] = nowD;
                pq.push(XD(nxtV,nowC-d,dis[nxtV][nowC-d]));
            }
        }
    }
    if(dis[ed][0] == kInf)cout <<"impossible\n";
    else cout << dis[ed][0] << "\n";
}
int main(){
    int a,b,c;
    while(cin >> N >> M){
        for(int i=0;i<N;i++)cin >> ci[i];
        for(int i=0;i<N;i++){
            v[i].clear();
        }
        for(int i=0;i<M;i++){
            scanf("%d%d%d",&a,&b,&c);
            v[a].push_back(Edge(b,c));
            v[b].push_back(Edge(a,c));
        }
        int q;
        cin >> q;
        while(q--){
            solve();
        }
    }
    return 0;
}
/*
5 5
10 10 20 12 13
0 1 9
0 2 8
1 2 1
1 3 11
2 3 7
2
10 0 3
20 1 4
*/
