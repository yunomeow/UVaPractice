#include<stdio.h>
#include<stdlib.h>
#include<string.h>
long long ans[205];
long long num[205];
long long tmp[205];
int main (){
    int i,flag,n,j;
    while(scanf("%d",&n)!=EOF){
    for(i=0;i<n;i++){
        scanf("%lld",&num[i]);
    }
    memset(ans,0,sizeof(ans));
    ans[0] = -1 * num[0];
    ans[1] = 1;
    for(i=1;i<n;i++){
        for(j=200;j>0;j--){
            tmp[j] = ans[j-1];
        }
        tmp[0] = 0;
        for(j=200;j>=0;j--){
            ans[j]*=(num[i]*-1);
        }
        for(j=200;j>=0;j--){
            ans[j] += tmp[j];
        }
    }
    flag = 0;
    for(j=200;j>=0;j--){
        if(ans[j] != 0){
            if(flag == 1){
                if(ans[j] > 0 && ans[j] != 0)
                    printf(" + ");
                else{
                    printf(" - ");
                    ans[j]*=-1;
                }
            }
            flag = 1;
            if(ans[j] > 1 || j == 0)printf("%lld",ans[j]);
            if(j > 1)
                printf("x^%d",j);
            if(j == 1)
                printf("x");
        }
    }
    if(ans[0] == 0)printf(" + 0");
    printf(" = 0\n");
    }
    return 0;
}
