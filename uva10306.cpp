#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int dp[305][305];
int main (){
    int n,m,T;
    int i,j,k,a,b ;
    int ans;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        for(i=0;i<304;i++){
            for(j=0;j<304;j++)
                dp[i][j] = 10000000;
        }
        dp[0][0] = 0;
        for(i=0;i<n;i++){
            scanf("%d%d",&a,&b);
            for(j=0;j<304;j++){
                for(k=0;k<305;k++){
                    if(j-a>=0 && k-b >= 0){
                        if(dp[j-a][k-b] + 1 < dp[j][k])
                            dp[j][k] = dp[j-a][k-b] + 1;
                    }
                }
            }
        }
        ans = 10000000;
        for(i=0;i<305;i++){
            for(j=0;j<305;j++){
                if(i*i + j*j == m*m){
                    if(dp[i][j] < ans)
                        ans = dp[i][j];
                }
            }
        }
        if(ans < 10000000)
            printf("%d\n",ans);
        else
            printf("not possible\n");
    }
    return 0;
}
