#include<stdio.h>
#include<string.h>
long long dp[51][51][51];
int MAX(int a,int b){
    if(a > b)return a;
    return b;
}
int main (){
    int i,j,k,n,m,l;
    memset(dp,0,sizeof(dp));
    for(i=0;i<51;i++)
        dp[0][0][i] = 1;
    //dp[0][0][1] = 1;
    for(i=1;i<51;i++){
        for(j=1;j<51;j++){
            for(k=1;k<51;k++){
                for(l=1;l<51;l++){
                    if(i-l < 0)break;
                    if(l > k)break;
                    dp[i][j][k] += dp[i-l][j-1][MAX(k,l)];
                }
            }
        }
    }
    while(scanf("%d%d%d",&n,&m,&k) != EOF){
        printf("%lld\n",dp[n][m][k]);
    }
    return 0;
}

