#include<stdio.h>
#include<stdlib.h>
int num[21];
int two[21];
int main (){
    int n,k,tmp,sum;
    int ans,pos;
    int i,j;
    two[0] = 1;
    for(i=1;i<21;i++)two[i] = two[i-1] * 2;
    while(scanf("%d",&n) != EOF){
        scanf("%d",&k);
        for(i=0;i<k;i++){
            scanf("%d",&num[i]);
        }
        ans = 0;
        for(i=1;i<two[k];i++){
            sum = 0;
            for(j=0;j<k;j++){
                if((i & two[j]) != 0){
                    sum += num[j];
                }
            }
            if(sum <= n && sum > ans){
                ans = sum;
                pos = i;
            }
        }
       // printf("pos %d\n",pos);
        for(i=0;i<k;i++){
            if((pos & two[i]) != 0){
                printf("%d ",num[i]);
            }
        }
        printf("sum:%d\n",ans);
    }
}
/*
5 3 1 3 4
10 4 9 8 4 2
20 4 10 5 7 4
90 8 10 23 1 2 3 4 5 7
45 8 4 10 44 43 12 9 8 2
*/
