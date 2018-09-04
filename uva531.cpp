#include <iostream>
#include <vector>
using namespace std;
int par[105][105][2],dp[105][105];
vector<string> t1,t2,ans;
int main (){
    string s;
    while(cin >> s){
        t1.clear();
        t2.clear();
        t1.push_back("");
        t1.push_back(s);
        t2.push_back("");
        if(s != "#")
            while(cin >> s, s != "#")t1.push_back(s);
        while(cin >> s, s != "#")t2.push_back(s);

        fill(&dp[0][0],&dp[101][0],0);
        int x,y,nx,ny,MAX=0;
        for(int i=1;i<t1.size();i++){
            for(int j=1;j<t2.size();j++){
                if(t1[i] == t2[j]){
                    par[i][j][0] = i-1;
                    par[i][j][1] = j-1;
                    dp[i][j] = dp[i-1][j-1] + 1;
                }else{
                    if(dp[i-1][j] > dp[i][j-1]){
                        par[i][j][0] = i-1;
                        par[i][j][1] = j;
                        dp[i][j] = dp[i-1][j];
                    }else{
                        par[i][j][0] = i;
                        par[i][j][1] = j-1;
                        dp[i][j] = dp[i][j-1];
                    }
                }
                if(dp[i][j] > MAX){
                    MAX = dp[i][j];
                    x = i;
                    y = j;
                }
            }
        }
        ans.clear();

        while(x != 0 || y != 0){
            if(t1[x] == t2[y]){
                ans.push_back(t1[x]);
            }
            nx = par[x][y][0];
            ny = par[x][y][1];
            x = nx;
            y = ny;
        }
        for(int i=(int)ans.size()-1;i>=0;i--){
            cout << ans[i];
            if(i != 0)cout << " ";
        }
        cout <<"\n";
    }
    return 0;
}
