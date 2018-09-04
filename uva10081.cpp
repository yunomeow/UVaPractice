#include<stdio.h>
#include<stdlib.h>
#include<string.h>
double dp[105][10];
int main (){
    int n,k,i,j;
    double ans;
    while(scanf("%d%d",&k,&n) != EOF){
        memset(dp,0,sizeof(dp));
        for(i=0;i<=k;i++){
            dp[1][i] = 1;
        }
        for(i=2;i<=n;i++){
            for(j=0;j<=k;j++){
                if(j == 0)
                    dp[i][0] = dp[i-1][1] + dp[i-1][0];
                else if(j == k){
                    dp[i][j] = dp[i-1][j];
                    if(k > 0)
                        dp[i][j] += dp[i-1][j-1];
                }else{
                    dp[i][j] = dp[i-1][j] + dp[i-1][j-1] + dp[i-1][j+1];
                }
            }
        }
        ans = 0;
        for(i=0;i<=k;i++){
            ans += dp[n][i];
        }
        for(i=1;i<=n;i++){
            ans /= (k+1);
        }
        printf("%.5lf\n",ans*100);
    }
    return 0;    
}
/*
4 1
2 5
3 5
8 7
*/
