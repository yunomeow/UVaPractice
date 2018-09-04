#include <iostream>
using namespace std;
int dp[1005],num[1005];
int main (){
    int Z,N;
    cin >> Z;
    while(Z--){
        cin >> N;
        for(int i=0;i<N;i++)cin >> num[i];
        num[N] = 2100000000;
       /* fill(&dp[0],&dp[N],0);
        dp[0] = 1;
        for(int i=1;i<N;i++){
            dp[i] = 1;
            for(int j=i-1;j>=0;j--){
                if(num[j+1] - num[j] - 1 <= num[i+1] - num[i] - 1){
                    dp[i] = max(dp[i],dp[j]+1);
                }
            }
        }
        int ans = 0;
        for(int i=0;i<N;i++)ans = max(ans,dp[i]);*/
        int sum = 0,ans = 0;
        for(int i=0;i<N;i++){
            if(sum + num[i] < num[i+1]){
                sum += num[i];
                ans++;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
