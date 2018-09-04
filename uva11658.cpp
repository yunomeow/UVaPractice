#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int valid[10005];
int num[105];
int main (){
    int n,m;
    double in,ans;
    int i,j;
    while(1){
        scanf("%d%d",&n,&m);
        if(n == 0 && m == 0)break;
        memset(valid,0,sizeof(valid));
        for(i=0;i<n;i++){
            scanf("%lf",&in);
            num[i] = in * 100 + 1e-7;
        }
        valid[num[m-1]] = 1;
        for(j=0;j<n;j++){
            if(j == m-1)continue;
            for(i=10000;i>=0;i--){
                if(i - num[j] >= 0){
                    if(valid[i-num[j]] == 1){
                        valid[i] = 1;
                    }
                }
            }
        }
        for(i=5001;i<=10000;i++){
            if(valid[i] == 1){
                ans = 100*num[m-1] / (double)i;
                printf("%.2lf\n",ans);
                break;
            }
        }
    }
    return 0;
}
