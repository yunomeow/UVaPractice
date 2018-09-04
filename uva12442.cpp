#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
int nxt[500005];
int dis[500005];
int dfn[500005];
int main (){
    int Z,N,a,b,ans,len,cnt,now,id;
    vector<int> v;
    cin >> Z;
    for(int zi=1;zi<=Z;zi++){
        cin >> N;
        fill(&dfn[0],&dfn[N+1],0);
        for(int i=0;i<N;i++){
            scanf("%d%d",&a,&b);
            nxt[a] = b;
        }
        ans = 0;len = 0;now = 0;
        id = 1;
        for(int i=1;i<=N;i++){
            if(dfn[i] == 0){
                now = i;
                cnt = 0;
                v.clear();
                while(dfn[now] == 0){
                    v.push_back(now);
                    dfn[now] = id++;
                    now = nxt[now];
                }
                if(dfn[now] < dfn[i]){
                    cnt = dis[now]+1;
                    for(int j=v.size()-1;j>=0;j--,cnt++){
                        dis[v[j]] = cnt;
                    }
                }else{
                    cnt = dfn[*v.rbegin()] - dfn[now];
                    int pos;
                    for(int j=v.size()-1;j>=0;j--){
                        dis[v[j]] = cnt;
                        if(v[j] == now){pos = j;break;}
                    }
                    cnt++;
                    for(int j=pos-1;j>=0;j--,cnt++){
                        dis[v[j]] = cnt;
                    }
                }
            }
        }
        len = 0;
        for(int i=1;i<=N;i++){
            //cout << "d: " <<dis[i] <<"\n";
            if(dis[i] > len){
                ans = i;
                len = dis[i];
            }
        }
        cout << "Case " << zi << ": " << ans << "\n";
    }
    return 0;
}
