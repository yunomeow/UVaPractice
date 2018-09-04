#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int dp[100][100][10];
int num[100][100];
int fromleft[100][10],fromright[100][10];
inline int  MAXval(int a,int b){
    if(a > b)return a;
    else return b;
}
int main (){
    int n,K;
    int i,j,k;
    int ca = 0;
    int ans;
    while(1){
        scanf("%d%d",&n,&K);
        if(n == 0 && K == 0)break;
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                scanf("%lld",&num[i][j]);
            }
        }
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                for(k=0;k<=K;k++)
                    dp[i][j][k] = -1e8;
            }
        }
        if(num[0][0] < 0){
            dp[0][0][1] = num[0][0];
        }else{
            dp[0][0][0] = num[0][0];
        }
        //initial
        for(i=1;i<n;i++){
            if(num[0][i] < 0){
                for(k=1;k<=K;k++){
                    dp[0][i][k] = dp[0][i-1][k-1] + num[0][i];
                }
            }else{
                for(k=0;k<=K;k++){
                    dp[0][i][k] = dp[0][i-1][k] + num[0][i];
                }
            }
        }
        //go
        for(i=1;i<n;i++){
            for(j=0;j<n;j++){
                for(k=0;k<=K;k++){
                    fromleft[j][k] = -1e8;
                    fromright[j][k] = -1e8;
                }
            }
            for(j=0;j<n;j++){
                if(j == 0){
                    if(num[i][j] < 0){
                        for(k=1;k<=K;k++)
                            fromleft[j][k] = dp[i-1][j][k-1] + num[i][j];
                    }else{
                        for(k=0;k<=K;k++)
                            fromleft[j][k] = dp[i-1][j][k] + num[i][j] ;
                    }
                }else{
                    if(num[i][j] < 0){
                        for(k=1;k<=K;k++)
                            fromleft[j][k] = MAXval(dp[i-1][j][k-1],fromleft[j-1][k-1]) + num[i][j];
                    }else{
                        for(k=0;k<=K;k++)
                            fromleft[j][k] = MAXval(dp[i-1][j][k],fromleft[j-1][k]) + num[i][j];
                    }
                }
            }
            for(j=n-1;j>=0;j--){
                if(j == n-1){
                    if(num[i][j] < 0){
                        for(k=1;k<=K;k++)
                            fromright[j][k] = dp[i-1][j][k-1] + num[i][j];
                    }else{
                        for(k=0;k<=K;k++)
                            fromright[j][k] = dp[i-1][j][k] + num[i][j] ;
                    }
                }else{
                    if(num[i][j] < 0){
                        for(k=1;k<=K;k++)
                            fromright[j][k] = MAXval(dp[i-1][j][k-1],fromright[j+1][k-1]) + num[i][j];
                    }else{
                        for(k=0;k<=K;k++)
                            fromright[j][k] = MAXval(dp[i-1][j][k],fromright[j+1][k]) + num[i][j];
                    }
                }
            }
            /*
            printf("i %d\n",i);
            for(j=0;j<n;j++){
                for(k=0;k<=K;k++) 
                    printf("%12d",fromleft[j][k]);
                printf("\n");
            }
            printf("\n");
            for(j=0;j<n;j++){
                for(k=0;k<=K;k++) 
                    printf("%12d",fromright[j][k]);
                printf("\n");
            }
            printf("\n");*/
            for(j=0;j<n;j++){
                if(j == 0){
                    if(num[i][j] < 0){
                        for(k=1;k<=K;k++){
                            dp[i][j][k] = MAXval(fromright[j+1][k-1],dp[i-1][j][k-1]) + num[i][j];
                        }
                    }else{
                        for(k=0;k<=K;k++){
                           // printf("==%I64d==\n",MAXval(fromright[j+1][k],dp[i-1][j][k]));
                            dp[i][j][k] = MAXval(fromright[j+1][k],dp[i-1][j][k]) + num[i][j];
                        }
                    }                    
                }else if(j == n-1){
                    if(num[i][j] < 0){
                        for(k=1;k<=K;k++){
                            dp[i][j][k] = MAXval(fromleft[j-1][k-1],dp[i-1][j][k-1]) + num[i][j];
                        }
                    }else{
                        for(k=0;k<=K;k++){
                            dp[i][j][k] = MAXval(fromleft[j-1][k],dp[i-1][j][k]) + num[i][j];
                        }
                    }
                }else{
                    if(num[i][j] < 0){
                        for(k=1;k<=K;k++){
                            dp[i][j][k] = MAXval(MAXval(fromleft[j-1][k-1],fromright[j+1][k-1]),dp[i-1][j][k-1]) + num[i][j];
                        }
                    }else{
                        for(k=0;k<=K;k++){
                            dp[i][j][k] = MAXval(MAXval(fromleft[j-1][k],fromright[j+1][k]),dp[i-1][j][k]) + num[i][j];
                        }
                    }                    
                }
            }
        }
        ans = -1e8;
        for(k=0;k<=K;k++){
            if(dp[n-1][n-1][k] > ans)
                ans = dp[n-1][n-1][k];
        }
        /*
        for(k=0;k<=K;k++){
        for(i=0;i<n;i++){
            for(j=0;j<n;j++)
                printf("%12lld",dp[i][j][k]);
            printf("\n");
        }
        printf("\n\n");
        }*/
        ca++;
        printf("Case %d: ",ca);
        if(ans < -1e7)
            printf("impossible\n");
        else
            printf("%d\n",ans);
    }
    return 0;
}
/*
4 1
1 2 3 -5
-10 6 0 -1
-10 -10 -10 2
0 0 0 1
*/
