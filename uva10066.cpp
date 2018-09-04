#include <iostream>
using namespace std;
int dp[105][105];
int num1[105],num2[105];
int main (){
    int N,M,zi=1;
    while(cin >> N >> M,N+M){
        for(int i=1;i<=N;i++)cin >> num1[i];
        for(int i=1;i<=M;i++)cin >> num2[i];
        dp[0][0] = 0;
        for(int i=1;i<=N;i++){
            for(int j=1;j<=M;j++){
                if(num1[i] == num2[j])
                    dp[i][j] = dp[i-1][j-1] + 1;
                else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        int ans = 0;
        cout <<"Twin Towers #" << zi++ << "\n";
        for(int i=1;i<=N;i++)
            for(int j=1;j<=M;j++)
                ans = max(ans,dp[i][j]);
        cout << "Number of Tiles : " << ans << "\n\n";
    }
    return 0;
}
