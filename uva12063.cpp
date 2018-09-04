#include <iostream>
using namespace std;
typedef long long int64;
int64 dp[36][36][2][105];
int main (){

    int Z,ans,N,K;
    cin >> Z;
    for(int zi=1;zi<=Z;zi++){
        cout << "Case " << zi << ": ";
        cin >> N >> K;
        if(N % 2 == 1){
            cout << "0\n";
            continue;
        }
        fill(&dp[0][0][0][0],&dp[34][0][0][0],0);
        dp[0][0][0][0] = 1;
        for(int i=0;i<=N/2;i++){
            for(int j=0;j<=N/2;j++){
                for(int k=0;k<2;k++){
                    for(int l=0;l<K;l++){ //put 0
                        dp[i+1][j][0][l] += dp[i][j][k][l];
                    }
                    for(int l=0;l<K;l++){ //put 1
                        dp[i][j+1][1][(l+((1ll << (i+j))%K))%K] += dp[i][j][k][l];
                    }
                }
            }
        }
        cout << dp[N/2][N/2][1][0] << "\n";
    }
    return 0;
}
