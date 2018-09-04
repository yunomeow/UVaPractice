#include<stdio.h>
#include<stdlib.h>
long long cal(long long n){
    long long i,k;
    long long cnt = 0;
    for(i=10,k=1;i<=10000000000ll;i*=10,k++){
        if(n >= i){
            cnt += (k*(9ll * i/ 10))%10000 ;
            //printf("cnt %lld\n",cnt);
            cnt %= 10000;
        }else{
            break;
        }
    }
    //printf("k %lld i %lld\n",k,i);
    cnt += k*((n - i/10)+1);
    cnt %= 10000;
    return cnt;
}
long long two(long long n){
    if(n == 0)return 1;
    long long tmp;
    tmp = two(n/2);
    tmp %= 10000;
    tmp = tmp * tmp;
    tmp %= 10000;
    if(n % 2 == 1){
        tmp *= 2;
    }
    tmp %= 10000;
    return tmp;
}
int main (){
    long long n,ans;
    int ca = 0;
    //printf("cal %lld\n",cal(10001));
    while(1){
        ans = 0;
        scanf("%lld",&n);
        if(n == 0){
            break;
        }
        ans += n;
        ans %= 10000;
        ans += cal(n)-1;
        ans %= 10000;

        ans += n;
        ans %= 10000;
        ans += 2*((n-1)%10000);
        ans %= 10000;

        ans += (n%10000) * two(n-1);

        ans %= 10000;

        ans += cal(n)*two(n-1);
        ans %= 10000;
        ans += two(n) - n%10000 - 1;
        //printf("ans %lld\n",ans);
        ans %= 10000;
        ca++;
        printf("Case %d: %lld\n",ca,(ans+10000)%10000);
    }
    return 0;
}
