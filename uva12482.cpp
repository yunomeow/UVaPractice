#include <iostream>
using namespace std;
int dp[1005];
string word[1005];
int ok[1005][1005];
int main (){
    int N,L,C;
    while(cin >> N >> L >> C){
        for(int i=1;i<=N;i++){
            cin >> word[i];
        }
        for(int i=0;i<=N;i++)
            for(int j=0;j<=N;j++)
                ok[i][j] = 0;
        int line,cnt;
        for(int i=1;i<=N;i++){
            line = 0;cnt = word[i].size();
            ok[i][i] = 1;
            for(int j=i+1;j<=N;j++){
                if(cnt + word[j].size() + 1 <= C)
                    cnt += word[j].size() + 1;
                else{
                    line++;
                    cnt = word[j].size();
                }
                if(line < L)ok[i][j] = 1;
                else break;
            }
        }
        fill(&dp[0],&dp[N+1],1005);
        dp[0] = 0;
        for(int i=1;i<=N;i++){
            for(int j=i-1;j>=0;j--){
                if(ok[j+1][i]){
                    dp[i] = min(dp[i],dp[j]+1);
                }else break;
            }
        }
        cout << dp[N] << "\n";
    }
    return 0;
}
