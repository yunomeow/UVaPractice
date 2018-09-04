#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int dp[101][101];
int a[101];
inline int MIN(int a,int b){
    if(a > b)return b;
    else return a;
}
int main (){
    int i,n,m,T,tmp,j,k,ca = 0,x;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        x = 0;
        for(i=0;i<n;i++){
            scanf("%d",&tmp);
          //  printf("tmp: %d x %d\n",tmp,x);
            if(i == 0)a[0] = tmp;
            if(a[x] == tmp)
                continue;
            else{
                x++;
                a[x] = tmp;

            }
        }
        n = x+1;
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                dp[i][j] = 100;
        for(i=0;i<n;i++)
            dp[i][i] = 1;
        for(j=1;j<n;j++){
            for(i=0;i+j<n;i++){
                tmp = dp[i][i+j-1]+1;
                for(k = i+j-1;k >=i;k--){
                    if(a[k] == a[i+j])
                        tmp = MIN(tmp,dp[i][k]+dp[k+1][i+j-1]);
                }
                dp[i][i+j] = tmp;
            }
        }
       // for(i=0;i<n;i++){
        //    for(j=0;j<n;j++)
         //       printf("%2d ",dp[i][j]);
         //   printf("\n");
        //}
        ca++;
        printf("Case %d: %d\n",ca,dp[0][n-1]);
    }
    return 0;
}
