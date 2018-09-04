#include<stdio.h>
#include<stdlib.h>
int prime[50000],use[50055],x,p[50005];
int phi(int n){
    double tmp = n;
    int i;
    for(i=0;i<x;i++){
        if(prime[i] > n)break;
        if(n % prime[i] == 0){
            tmp *= (1.0-(1.0/prime[i]));
            while(n % prime[i] == 0)n /= prime[i];
        }
        if(use[n] == 0){
            tmp *= (1.0-(1.0/n));
            break;
        }
    }
    return (int)(tmp + 1e-7);
}
int main (){
    long long ans;
    register unsigned int i,j;
    int n;
    x = 1;
    use[1] = 1;
    use[0] = 1;
    prime[0] = 2;
    for(i=3;i<50001;i+=2){
        if(use[i] == 0){
            prime[x] = i;
            x++;
            for(j=i*i;j<50001;j+=i){
                use[j] = 1;
            }
        }
    }
    for(i=2;i<50001;i++)
        p[i] = phi(i);
    while(1){
        scanf("%d",&n);
        if(n == 0)break;
        ans = 0;
        for(i=n;i > 1;i--){
            ans += p[i];
          //  printf("i:%d phi %d\n",i,phi(i));
        }
        ans *= 2;
        ans++;
        printf("%lld\n",ans);
    }
    return 0;
}
