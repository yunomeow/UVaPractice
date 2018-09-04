#include <iostream>
using namespace std;
int dis[105][105];
int main (){
    int N,zi=1,st,a,b;
    while(cin >> N, N){
        cin >> st;
        fill(&dis[0][0],&dis[104][0],10000);
        while(cin >> a >> b , a+b){
            dis[a][b] = -1;
        }
        for(int i=0;i<=N;i++)dis[i][i] = 0;
        for(int k=1;k<=N;k++){
            for(int i=1;i<=N;i++){
                for(int j=1;j<=N;j++){
                    dis[i][j] = min(dis[i][j],dis[i][k] + dis[k][j]);
                }
            }
        }
        int ans=0,pos;
        for(int i=0;i<=N;i++){
            if(dis[st][i] < ans){
                ans = dis[st][i];
                pos = i;
            }
        }
        cout << "Case " << zi++ << ": The longest path from " << st <<" has length " << (-ans) << ", finishing at " << pos << ".\n\n" ;
    }
    return 0;
}
