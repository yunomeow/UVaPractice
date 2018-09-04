#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int dp[22][51][51][101];
struct dish{
    int cost;
    int val;
}data[105];
struct state{
    char i,j,k,l;
}par[22][51][51][101];
char dd[105];
int main (){
    int n,m,K;
    int i,j,k,l,z;
    int val,ans;
    int nowj,nowk,nowl,nj,nk,nl;
    while(1){
        scanf("%d%d%d",&K,&n,&m);
        if(K == 0 && n == 0 && m == 0)break;
        for(i=0;i<=K;i++){
            for(j=0;j<n;j++){
                for(k=0;k<n;k++){
                    for(l=0;l<=m;l++)
                        dp[i][j][k][l] = -1;
                }
            }
        }
        memset(par,0,sizeof(par));
        for(i=0;i<n;i++){
            scanf("%d%d",&data[i].cost,&data[i].val);
            data[i].val *= 2;
        }
        if(K >= 2){
            //initial
            for(i=0;i<n;i++){
                for(j=0;j<n;j++){
                    if(i == j)dp[2][i][j][data[i].cost + data[j].cost] = data[i].val + data[i].val / 2;
                    else dp[2][i][j][data[i].cost + data[j].cost] = data[i].val + data[j].val;
                }
            }
            //go
            for(i=3;i<=K;i++){  //第幾天 
                for(j=0;j<n;j++){   //今天要煮啥 
                    for(k=0;k<n;k++){   //昨天煮啥
                        for(l=0;l<n;l++){   //前天煮啥 
                            if(j == k && k == l)val = 0;
                            else if(j == k && k != l)val = data[j].val/2;
                            else val = data[j].val;
                            for(z=0;z<=m;z++){
                                if(data[j].cost + z <= m){
                                    if(dp[i-1][k][l][z] != -1 && ( (dp[i][j][k][z+data[j].cost] == -1 )||
                                    (dp[i][j][k][z+data[j].cost] < dp[i-1][k][l][z] + val)
                                    )){
                                      //  if(i == 18)printf("val %lf\n",dp[i-1][k][l][z] + val);
                                        dp[i][j][k][z+data[j].cost] = dp[i-1][k][l][z] + val;
                                        par[i][j][k][z+data[j].cost].j = k;
                                        par[i][j][k][z+data[j].cost].k = l;
                                        par[i][j][k][z+data[j].cost].l = z;
                                    }
                                }else break;
                            }
                        }
                    }
                }
            }
            ans = 0;
            for(i=0;i<n;i++){
                for(j=0;j<n;j++){
                    for(k=0;k<=m;k++){
                        if(ans < dp[K][i][j][k] || (ans == dp[K][i][j][k] && nowl > k)){
                            ans = dp[K][i][j][k];
                            nowj = i;
                            nowk = j;
                            nowl = k;
                        }
                    }
                } 
            }
            if(ans != 0){
                printf("%.1lf\n",ans/2.0);
                for(i=K;i>2;i--){
                    dd[i] = nowj+1;
                    //printf("%d %d %d\n",nowj,nowk,nowl);
                    nj = par[i][nowj][nowk][nowl].j;
                    nk = par[i][nowj][nowk][nowl].k;
                    nl = par[i][nowj][nowk][nowl].l;
                    nowj = nj;
                    nowk = nk;
                    nowl = nl;
                }
                dd[2] = nowj+1;
                dd[1] = nowk+1;
                for(i=1;i<=K;i++){
                    if(i!= 1)printf(" ");
                    printf("%d",dd[i]) ;
                }
                printf("\n");
            }else printf("0.0\n");
        }else{
            ans = 0;
            nowl = m;
            for(i=0;i<n;i++){
                if(data[i].cost <= m){
                    if(data[i].val > ans){
                        dd[1] = i+1;
                        ans = data[i].val;
                        nowl = data[i].cost;
                    }else if(data[i].val == ans && data[i].cost < nowl){
                        ans = data[i].val;
                        dd[1] = i+1;
                        nowl = data[i].cost;
                    }
                }
            }
            if(ans == 0)printf("0.0\n");
            else printf("%.1lf\n%d\n",ans/2.0,dd[1]);
        }
    }
    return 0;
}
/*
2 1 5
3 5
3 5 20
2 5
18 6
1 1
3 3
2 3
0 0 0



*/
