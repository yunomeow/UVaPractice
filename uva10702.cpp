#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int dp[1005][105];
int matrix[105][105];
int main (){
    int C,S,E,T;
    int i,j,k;
    int MAX;
    int ans,tmp;
    while(1){
        scanf("%d%d%d%d",&C,&S,&E,&T);
        if(C == 0 && S == 0 && E == 0 && T == 0)break;
        for(i=1;i<=C;i++){
            for(j=1;j<=C;j++){
                scanf("%d",&matrix[i][j]);
            }
        }
        for(i=1;i<=C;i++){
            dp[0][i] = matrix[S][i];
        }
        for(i=1;i<=T;i++){
            for(j=1;j<=C;j++){
                MAX = 0;
                for(k=1;k<=C;k++){
                    if(MAX < dp[i-1][k] + matrix[k][j]){
                        MAX = dp[i-1][k] + matrix[k][j];
                    }
                }
                dp[i][j] = MAX;
            }
        }
        ans = 0;
        for(i=0;i<E;i++){
            scanf("%d",&tmp);
            if(ans < dp[T-1][tmp])
                ans = dp[T-1][tmp];
        }
        printf("%d\n",ans);
    }
    return 0;
}
/*
3 1 2 2
0 3 5
5 0 1
9 2 0
2 3
*/
