#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Big{
    int num[1005];
    int len;
}dp[1005];
void Add(Big &a,Big &b){    // a = a+b
    int len,i,carry;
    if(a.len > b.len)len = a.len;
    else len = b.len;
    for(i=0;i<len;i++){
        a.num[i] += b.num[i];
    }
    carry = 0;
    for(i=0;i<len;i++){
        a.num[i] += carry;
        carry = a.num[i] / 100000000;
        a.num[i] %= 100000000;
    }
    a.len = len;
    if(carry > 0){
        a.num[len] = carry;
        a.len = len+1;
    }
} 
int main (){
    int i,j,n;
    dp[0].len = 1;
    dp[0].num[0] = 1;
    dp[1].len = 1;
    dp[1].num[0] = 2;
    dp[2].len = 1;
    dp[2].num[0] = 5;
    dp[3].len = 1;
    dp[3].num[0] = 13;
    for(i=4;i<1005;i++){
        Add(dp[i],dp[i-1]);
        Add(dp[i],dp[i-1]);
        Add(dp[i],dp[i-2]);
        Add(dp[i],dp[i-3]);                        
    }
    while(scanf("%d",&n) != EOF){ 
        for(i=dp[n].len-1;i>=0;i--){
            if(i == dp[n].len -1)printf("%d",dp[n].num[i]);
            else printf("%08d",dp[n].num[i]);
        }
        printf("\n");
    } 
    return 0;
}
