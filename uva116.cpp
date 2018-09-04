#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int par[105][105];
int dp[105][105];
int num[105][105];
const int kInf = 20000000;
int main (){
    int N,M;
    while(cin >> N >> M){
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                cin >> num[i][j];
            }
        }
        fill(&dp[0][0],&dp[N+1][0],kInf);
        fill(&par[0][0],&par[N+1][0],0);
        for(int i=0;i<N;i++)dp[i][M-1] = num[i][M-1];
        vector<int> up;
        for(int j=M-2;j>=0;j--){
            for(int i=0;i<N;i++){
                    up.clear();
                    up.push_back(i);
                    up.push_back((i+1)%N);
                    up.push_back((i-1+N)%N);
                    sort(up.begin(),up.end());
                    for(int k=0;k<3;k++){
                        if(dp[i][j] > dp[up[k]][j+1]+num[i][j]){
                            par[i][j] = up[k];
                            dp[i][j] = dp[up[k]][j+1]+num[i][j];
                        }
                    }
            }
        }

        //cout << "OAO";
        int now,MIN=kInf;
        for(int i=0;i<N;i++){
            //cout << dp[i][0] << "\n";
            if(dp[i][0] < MIN){
                MIN = dp[i][0];
                now = i;
            }
        }
        //cout << now << "\n";
        vector<int> v;

        v.clear();
        v.push_back(now);
        for(int j=0;j<M-1;j++){
            now = par[now][j];
            v.push_back(now);
        }

        for(int i=0;i<v.size();i++){
            if(i != 0)cout << " ";
            cout << (v[i]+1);
        }
        cout <<"\n";
        cout << MIN << "\n";
    }
    return 0;
}
