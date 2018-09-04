#include<stdio.h>
#include<stdlib.h>

long long inv(long long a,long long p){
    int i;
    long long tmp = 1;
    for(i=0;i<p-2;i++){
        tmp *= a;
        tmp %= p;
    }
    return tmp;
}
long long power(long long a,long long k,long long p){
    long long tmp = 1;
    int i;
    for(i=0;i<k;i++){
        tmp*=a;
        tmp %= p;
    }
    return tmp;
}
int main (){
    long long ans;
    long long n;
    long long MOD = 10007;
    ans = 0;
    while(1){
    scanf("%lld",&n);
    //printf("OAQ\n");
    ans = 0;
    if(n == 0)break;
    ans += (((107*power(n,10,MOD))%MOD)*inv(22680,MOD)%MOD);
    ans %= MOD;
    ans -= (((23*power(n,8,MOD))%MOD)*inv(756,MOD)%MOD);
    ans %= MOD;
    ans += (((71*power(n,6,MOD))%MOD)*inv(1080,MOD)%MOD);
    ans %= MOD;
    ans -= (((103*power(n,4,MOD))%MOD)*inv(1134,MOD)%MOD);
    ans %= MOD;
    ans += (((16*power(n,2,MOD))%MOD)*inv(315,MOD)%MOD);
    ans %= MOD;
    printf("%lld\n",(ans+MOD)%MOD);
    }
    return 0;
}
