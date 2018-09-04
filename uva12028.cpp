#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>
using namespace std;
long long a[100005];
long long sum[100005];
int main (){
    int k,c,n,T;
    int i,ca=0;
    long long ans;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d%lld",&k,&c,&n,&a[0]);
        for(i=1;i<n;i++){
            a[i] = (k*a[i - 1] + c)%1000007;
        }
        sort(a,a+n);
        ans = 0;
        sum[0] = a[0];
        for(i=1;i<n;i++){
            sum[i] = sum[i-1] + a[i];
        }
        for(i=0;i<n;i++){
            ans += ((i+1) * a[i] - sum[i]);
        }
        ca++;
        printf("Case %d: %lld\n",ca,ans);
    }
    return 0;
}
