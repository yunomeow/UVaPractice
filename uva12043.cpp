#include<stdio.h>
#include<stdlib.h>
int dp[1005][1005];
int ans[1005];
int main (){
    int i,j,T,n;
    dp[1][1] = 1;
//    dp[i][j] = dp[i-1][j-1] * (j+1) + dp[i-1][j] * j;
    for(i=2;i<1001;i++){
        for(j=1;j<=i;j++){
            dp[i][j] = (dp[i-1][j-1] * (j))%10056 + (dp[i-1][j] * j) % 10056;
            dp[i][j] %= 10056;
        }
    }
    for(i=1;i<1001;i++){
        for(j=1;j<=i;j++){
            ans[i] += dp[i][j];
            ans[i] %= 10056;
        }
    }
    int ca = 0;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        ca++;
        printf("Case %d: %d\n",ca,ans[n]);
    }
    return 0;
}
