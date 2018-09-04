#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

struct XD{
    int x,y,dis;
    XD(int _x,int _y,int _d):x(_x),y(_y),dis(_d){};
    bool operator < (const XD &b)const{
        return dis > b.dis;
    }
};
priority_queue<XD> pq;
const int kInf = 2100000000;
int N,K;
vector <int> ticket[25];
map<int,int> m;
map<int,int>::iterator it;
int ci[25],dp[25][200],par[25][200][3];
int num[25];
void read(){
    int k,tmp,id = 1;
    m.clear();
    for(int i=0;i<N;i++){
        cin >> ci[i] >> k;
        ticket[i].clear();
        for(int j=0;j<k;j++){
            cin >> tmp;
            if(m.find(tmp) == m.end()){
                m[tmp] = id;
                id++;
            }
            ticket[i].push_back(m[tmp]);
        }
    }
}
void solve(int zi){
    int Q;
    cin >> Q;
    for(int ti=1;ti<=Q;ti++){
        cin >> K;
        for(int i=0;i<K;i++){
            cin >> num[i];
            num[i] = m[num[i]];
        }
        //fill(&dp[0][0],&dp[K+1][0],kInf);
        for(int i=0;i<K;i++)
            for(int j=0;j<=(int)m.size();j++)
                dp[i][j] = kInf;
        dp[0][num[0]] = 0;
        pq.push(XD(0,num[0],0));
        while(!pq.empty()){
            int i,j;
            i = pq.top().x;
            j = pq.top().y;
            pq.pop();
            for(int k=0;k<N;k++){   //choose ticket type
                if(j == ticket[k][0]){  //can go
                    for(int l=1,x=i;l<(int)ticket[k].size()&&x<K;l++){
                        if(num[x+1] == ticket[k][l]){ //go on trip
                            x++;
                        }
                        if(dp[x][ticket[k][l]] > dp[i][j] + ci[k]){
                            dp[x][ticket[k][l]] = dp[i][j] + ci[k];
                            pq.push(XD(x,ticket[k][l],dp[x][ticket[k][l]]));
                            par[x][ticket[k][l]][0] = i;
                            par[x][ticket[k][l]][1] = j;
                            par[x][ticket[k][l]][2] = k;
                        }
                    }
                }
            }
        }
        int ans = dp[K-1][num[K-1]],nowx,nowy,nxtx,nxty;
        vector <int> path;
        nowx = K-1;
        nowy = num[K-1];
        cout << "Case " << zi << ", Trip " << ti << ": Cost = " << ans << "\n";
        while(nowx != 0 || nowy != num[0]){
            nxtx = par[nowx][nowy][0];
            nxty = par[nowx][nowy][1];
            path.push_back(par[nowx][nowy][2]+1);
            nowx = nxtx;
            nowy = nxty;
        }
        cout << "  Tickets used:"  ;
        for(int i=path.size()-1;i>=0;i--)cout << " " << path[i];
        cout << "\n";
    }
}
int main (){
    int zi = 1;
    while(cin >> N, N){
        read(),solve(zi++);
    }
    return 0;
}
/*
3
225 3 1 3 4
200 2 1 2
50 2 2 3
1
2 1 3
*/
