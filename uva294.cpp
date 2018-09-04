#include<stdio.h>
#include<stdlib.h>
int prime[9999999];
int use[999999];
int x=0;
int findans(int n){
    int ans = 1,tmp,i;
    for(i=0;i<x;i++){
        tmp = 0;
        while(n % prime[i] == 0){
            n /= prime[i];
            tmp++;
        }
        if(tmp > 0)ans *= (tmp+1);
    }
    if(n != 1)ans *= 2;
    return ans;
}
int main (){
    int L,U,i,T,j,ans,num,tmp;
    for(i=2;i<65588;i++){
        if(use[i] == 0){
            prime[x] = i;
            x++;
            for(j=i+i;j<65588;j+=i){
                use[j] = 1;
            }
        }
    }
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&L,&U);
        num = 0;
        for(i=L;i<=U;i++){
            tmp = findans(i);
            if(tmp > num){
                ans = i;
                num = tmp;
            }
        }
        printf("Between %d and %d, %d has a maximum of %d divisors.\n",L,U,ans,num);
    }
    return 0;
}
//
