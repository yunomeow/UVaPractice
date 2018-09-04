#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int use[10000005];
int prime[1000005];
int num[10005];
int sum[10005];
int main (){
    int n,x=1;
    int i,j,k,T;
    use[0] = 1;
    use[1] = 1;
    prime[0] = 2;
    for(i=2;i<10000005;i++){
        if(use[i] == 0){
            prime[x] = i;
            x++;
            for(j=i+i;j<10000005;j+=i){
                use[j] = 1;
            }
        }
    }
    int flag = 0;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        sum[0] = 0;
        num[0] = 0;
        for(i=1;i<=n;i++){
            scanf("%d",&num[i]);
            sum[i] = sum[i-1] + num[i];
        }
        flag = 0;
        for(i=2;i<=n;i++){
            for(j=1;i+j-1<=n;j++){
                if(use[sum[i+j-1] - sum[j-1]] == 0){
                    printf("Shortest primed subsequence is length %d:",i);
                    for(k=j;k<i+j;k++)printf(" %d",num[k]);
                    printf("\n");
                    flag = 1;
                    break;
                }
            }
            if(flag == 1)break;
        }
        if(flag == 0){
            printf("This sequence is anti-primed.\n");
        }
    }



    return 0;
}
