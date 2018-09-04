#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int cost[37];
int ans[37];
int main (){
    int i,T,n,num,tmp,MIN,ca=0,flag = 0;
    scanf("%d",&T);
    while(T--){
        if(flag == 1)printf("\n");
        flag = 1;
        ca++;
        printf("Case %d:\n",ca);
        for(i=0;i<36;i++)
            scanf("%d",&cost[i]);
        scanf("%d",&n);
        while(n--){
            memset(ans,0,sizeof(ans));
            scanf("%d",&num);
            printf("Cheapest base(s) for number %d:",num);
            MIN = 2100000000;
            for(i=2;i<=36;i++){
                tmp = num;
                while(tmp > 0){
                    ans[i] += cost[tmp % i];
                    tmp /= i;
                }
                if(ans[i] < MIN)
                    MIN = ans[i];
            }
            for(i=2;i<=36;i++)
                if(ans[i] == MIN)
                    printf(" %d",i);
            printf("\n");
        }
    }
    return 0;
}
