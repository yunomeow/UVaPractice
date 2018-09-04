#include <iostream>
#include <map>
#include <queue>
using namespace std;
const int kInf = 2100000000;
struct Edge{
    int p,c;
    Edge(int _p,int _c){
        p = _p;
        c = _c;
    }
};
int inq[400],dis[400];
vector<Edge> v[400];
int main (){
    int N,M,a,b,c,zi=1,now,nxt,st,ed;
    string s1,s2;
    map<string,int> m;
    map<string,int>::iterator it;
    queue<int> q;
    while(cin >> N >> M ,N+M){
        for(int i=0;i<N;i++)v[i].clear();
        int idx = 0;
        m.clear();
        for(int i=0;i<M;i++){
            cin >> s1 >> s2 >> c;
            it = m.find(s1);
            if(it == m.end())m[s1] = idx++;
            it = m.find(s2);
            if(it == m.end())m[s2] = idx++;
            a = m[s1];
            b = m[s2];
            v[a].push_back(Edge(b,c));
            v[b].push_back(Edge(a,c));
        }
        cin >> s1 >> s2;
        it = m.find(s1);
        if(it == m.end())m[s1] = idx++;
        st = m[s1];
        it = m.find(s2);
        if(it == m.end())m[s2] = idx++;
        ed = m[s2];
        fill(&dis[0],&dis[N],0);
        fill(&inq[0],&inq[N],0);
        dis[st] = kInf;
        q.push(st);
        while(!q.empty()){
            now = q.front();
            inq[now] = 0;
            q.pop();
            for(int i=0;i<(int)v[now].size();i++){
                if(dis[v[now][i].p] < min(dis[now],v[now][i].c)){
                    dis[v[now][i].p] = min(dis[now],v[now][i].c);
                    if(inq[v[now][i].p] == 0){
                        inq[v[now][i].p] = 1;
                        q.push(v[now][i].p);
                    }
                }
            }
        }
        cout << "Scenario #" << zi++ << "\n";
        cout << dis[ed] << " tons\n\n";
    }
    return 0;
}
