#include <iostream>
using namespace std;
int num[10][1005];
int dp[10][1005];
const int kInf = 2100000000;
int main (){
    int Z,X;
    cin >> Z;
    while(Z--){
        cin >> X;
        X /= 100;
        for(int i=9;i>=0;i--){
            for(int j=1;j<=X;j++){
                cin >> num[i][j];
            }
        }
        fill(&dp[0][0],&dp[10][0],kInf);
        dp[0][0] = 0;
        for(int j=1;j<=X;j++){
            for(int i=0;i<10;i++){
                dp[i][j] = min(dp[i][j],dp[i][j-1]+30-num[i][j]);
                if(i != 0)
                dp[i][j] = min(dp[i][j],dp[i-1][j-1]+60-num[i-1][j]);
                if(i != 9)
                dp[i][j] = min(dp[i][j],dp[i+1][j-1]+20-num[i+1][j]);
            }
        }
        /*for(int i=9;i>=0;i--){
            for(int j=0;j<=X;j++)
                cout << dp[i][j] << " ";
            cout << "\n";
        }*/
        cout << dp[0][X]  << "\n\n";
    }
    return 0;
}
