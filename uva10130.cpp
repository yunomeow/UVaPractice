#include <iostream>
using namespace std;
int dp[300];
int main (){
    int Z,ans,a,b,N;
    cin >> Z;
    while(Z--){
        cin >> N;
        fill(&dp[0],&dp[35],-1);
        dp[0] = 0;
        for(int i=0;i<N;i++){
            cin >> a >> b;
            for(int j=30;j>=0;j--){
                if(j - b >= 0){
                    if(dp[j-b] == -1)continue;
                    dp[j] = max(dp[j],dp[j - b] + a);
                }
            }
        }
        int G,tmp;
        cin >> G;
        ans = 0;
        while(G--){
            cin >> a;
            tmp = 0;
            for(int i=0;i<=a;i++){
                tmp = max(tmp,dp[i]);
            }
            ans += tmp;
        }
        cout << ans << "\n";
    }
    return 0;
}
