#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>
using namespace std;
typedef long long int64;
//vector<int64> prime;
long long prime[2000000];
int use[20000005],x;
inline int64 solve(int64 n){
    int64 res = 1;
    int cnt;
    for(int i=0;i<x ;i++){
        cnt = 0;
        if(prime[i]*prime[i] > n)break;
        if(n == 1ll)break;
        while(n % prime[i] == 0){
            cnt++;
            n /= prime[i];
        }
        if(cnt >= 1)
            res *= (cnt+1);
    }
    if(n != 1)res *= 2;
    return res;
}
int main (){
    int64 N,ans,a,b,c;
    x = 0;
    prime[x] = 2;
    x++;
    for(int i=3;i<20000005;i+=2){
        if(use[i] == 0){
            prime[x] = i;
            x++;
            for(int j=i+i;j<20000005;j+=i)
                use[j] = 1;
        }
    }
    while(scanf("%lld",&N), N){
        c = 4 * N - 3;
        ans = solve(c);
        printf("%lld %lld\n",N,ans);
    }
    return 0;
}
