#include<stdio.h>
#include<stdlib.h>
inline long long ABS(long long a){
    if(a < 0)return -1*a;
    else return a;
}
int main (){
    int T;
    long long n;
    scanf("%d",&T);
    while(T--){
        scanf("%lld",&n);
        n*=567;
        n/=9;
        n+=7492;
        n*=235;
        n/=47;
        n-=498;
        printf("%lld\n",ABS((n/10)%10));
    }
    return 0;
}
