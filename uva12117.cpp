#include<stdio.h>
#include<stdlib.h>
long long dp[2005][8];
int main(){
    dp[0][7] = 1;
    int i,j;
    for(i=1;i<2002;i++){
        if(i-1 >= 0){
            dp[i][7] += dp[i-1][7];
            dp[i][7] += dp[i-1][2];
            dp[i][7] += dp[i-1][1];
            dp[i][7] += dp[i-1][5];
            dp[i][4] += dp[i-1][1];
            dp[i][6] += dp[i-1][3];
            dp[i][7] += dp[i-1][3];
            dp[i][7] += dp[i-1][6];
            dp[i][7] += dp[i-1][4];
        }
        if(i-2 >= 0){
            dp[i][2] += dp[i-2][7];
            dp[i][2] += dp[i-2][5];
            dp[i][5] += dp[i-2][7];
            dp[i][4] += dp[i-2][7];
            dp[i][1] += dp[i-2][7];
            dp[i][3] += dp[i-2][7];
            dp[i][1] += dp[i-2][6];
            dp[i][3] += dp[i-2][4];
            dp[i][6] += dp[i-2][7];
        }
        if(i-3 >= 0){
            dp[i][4] += dp[i-3][1];
            dp[i][6] += dp[i-3][3];
        }
        for(j=0;j<8;j++){
            dp[i][j] %= 1000000000000ll;
        }
    }
    int n,ca=0;
    while(1){
        scanf("%d",&n);
        if(n == 0)break;
        ca++;
        printf("Case %d: %lld\n",ca,dp[n][7]);
    }
    return 0;
}
