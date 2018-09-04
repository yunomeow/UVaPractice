#include <iostream>
using namespace std;
int dp[10005];
int num[105];
int main (){
    int Z,N,K;
    cin >> Z;
    while(Z--){
        cin >> N >> K;
        fill(&dp[0],&dp[10005],10000000);
        dp[0] = 0;
        for(int i=0;i<K;i++)cin >> num[i];
        for(int i=0;i<K;i++){
            for(int j=10000;j>=0;j--){
                if(j - num[i] >= 0){
                    dp[j] = min(dp[j - num[i]]+1,dp[j]);
                }
            }
        }
        for(int i=N;i<10001;i++){
            if(dp[i] != 10000000){
                cout << i << " " <<dp[i] << "\n";
                break;
            }
        }
    }
    return 0;
}
