#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
struct XD{
    int t,d;
}data[100005];
int dp[105][105];
int main (){
    int i,n,ans,a,b,j;
    int cnt;
    while(1){
        scanf("%d",&n);
        if(n == 0)break;
        ans = 0;
        for(i=1;i<=n;i++){
            scanf("%d%d",&a,&b);
            data[i].t = a;
            data[i].d = b;
        }
        cnt = 0;
        for(i=0;i<=n;i++){
            for(j=0;j<=n;j++)
                dp[i][j] = 100000;
        }
        dp[0][0] = 0;
        for(i=1;i<=n;i++){
            for(j=0;j<=cnt;j++){
                if(j == 0)
                    dp[i][j] = dp[i-1][j] + data[i].t;
                else{
                    dp[i][j] =
                    min(dp[i-1][j-1] + data[i].t/2,dp[i-1][j] + data[i].t);
                }
            }
            cnt += data[i].d;
            if(cnt > n)cnt = n;
        }
        ans = 1000000;
        for(i=0;i<=cnt;i++)
            if(dp[n][i] < ans)
                ans = dp[n][i];
        printf("%d\n",ans);
    }
    return 0;
}
