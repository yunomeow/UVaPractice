#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int dp1[2005],dp2[2005],num[2005];
int main (){
    //freopen("7124.out","w",stdout);
    //freopen("7124.in","r",stdin);
    int i,j,T,n;
    int ans,tmp;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(i=0;i<n;i++){
            scanf("%d",&num[i]);
        }
        memset(dp1,0,sizeof(dp1));
        memset(dp2,0,sizeof(dp2));
        for(i=n-1;i>=0;i--){
            tmp = 0;
            for(j=i;j<n;j++){
                if(num[i] < num[j]){
                    if(tmp < dp1[j])tmp = dp1[j];
                }
            }
            dp1[i] = tmp + 1;
        }
        for(i=n-1;i>=0;i--){
            tmp = 0;
            for(j=i;j<n;j++){
                if(num[i] > num[j]){
                    if(tmp < dp2[j])tmp = dp2[j];
                }
            }
            dp2[i] = tmp + 1;
        }
        ans = 0;
        for(i=0;i<n;i++){
            if(dp1[i] + dp2[i] - 1 > ans)ans = dp1[i] + dp2[i] - 1;
        }
        printf("%d\n",ans);
    }
    return 0;
}
