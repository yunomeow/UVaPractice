#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct Edge{
    int p,c;
    Edge(int _p,int _c){
        p = _p;
        c = _c;
    }
};
vector<Edge> v[105];
queue<int> q;
int dis[105],inq[105];
int main (){
    int N,M,st,ed,n,zi=1,a,b,c,now;
    while(cin >> N >> M , N+M){
        for(int i=0;i<=N;i++){
            v[i].clear();
        }
        for(int i=0;i<M;i++){
            cin >> a >> b >> c;
            c--;
            v[a].push_back(Edge(b,c));
            v[b].push_back(Edge(a,c));
        }
        cin >> st >> ed >> n;
        fill(&dis[0],&dis[N+1],0);
        dis[st] = 2100000000;
        q.push(st);
        while(!q.empty()){
            now = q.front();
            q.pop();
            inq[now] = 0;
            for(int i=0;i<(int)v[now].size();i++){
                if(dis[v[now][i].p] < min(dis[now],v[now][i].c)){
                    dis[v[now][i].p] = min(dis[now],v[now][i].c);
                    if(inq[v[now][i].p] == 0){
                        q.push(v[now][i].p);
                        inq[v[now][i].p] = 1;
                    }
                }
            }
        }
        cout << "Scenario #" << zi++ << "\n";
        cout << "Minimum Number of Trips = " << ((n+dis[ed]-1) / dis[ed]) << "\n\n";
    }
    return 0;
}
