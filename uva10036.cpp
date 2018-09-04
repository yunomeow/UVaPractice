#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int dp[10005][105];
int num[10005];
int ABS(int a){
    if(a > 0)return a;
    else return -a;
}
int main (){
    int i,n,k,T,tmp,j;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&k);
        for(i=0;i<n;i++){
            scanf("%d",&tmp);
            num[i] = ABS(tmp) % k;
        }
        memset(dp,0,sizeof(dp));
        dp[0][num[0]] = 1;
        dp[0][((-1 * num[0])+k)%k] = 1;        
        for(i=1;i<n;i++){
            for(j=0;j<k;j++){
                if(dp[i-1][j] == 1){
                    dp[i][(j + num[i]) % k] = 1;
                    dp[i][((j - num[i])+k)%k] = 1;
                }
            }
        }
        if(dp[n-1][0] == 1)printf("Divisible\n");
        else printf("Not divisible\n");
    } 
    return 0;
}
