#include<stdio.h>
#include<stdlib.h>
#include<string.h>
long long dp[105][105][2];
int main (){
    int n,s;
    int i,j;
    dp[1][0][0] = 1;
    dp[1][1][1] = 1;
    for(i=1;i<=65;i++){
        for(j=0;j<=65;j++){
            dp[i][j][0] += dp[i-1][j][0];
            dp[i][j][0] += dp[i-1][j+1][1];
            if(j-1 >= 0){
                dp[i][j][1] += dp[i-1][j-1][1];
                dp[i][j][1] += dp[i-1][j-1][0];
            }
        }
    }
    while(1){
        scanf("%d%d",&n,&s);
        if(n < 0 && s < 0)break;
        printf("%lld\n",dp[n][s][0]+dp[n][s][1]);
    }
    return 0;
}
