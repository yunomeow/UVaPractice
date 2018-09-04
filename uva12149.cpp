#include<stdio.h>
#include<stdlib.h>
int main (){
    long long n;
    long long ans;
    int i;
    while(1){
        scanf("%lld",&n);
        if(n == 0)break;
        ans = 0;
        for(i=1;i<=n;i++){
            ans += i*i;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
