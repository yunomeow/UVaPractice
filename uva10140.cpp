#include<stdio.h>
#include<stdlib.h>
long long prime[9999999];
int use[999999],notPrime[1000008];
int x=0;
int main (){
    int L,U,ans1,ans2,a,b,x1,x2,y1,y2;
    long long i,j;
    for(i=2;i<65588;i++){
        if(use[i] == 0){
            prime[x] = i;
            x++;
            for(j=i+i;j<65588;j+=i){
                use[j] = 1;
            }
        }
    }
    while(scanf("%d%d",&L,&U) != EOF){
        for(i=L,j=0;i<=U;i++,j++)notPrime[j] = 0;
        for(i=0;i<x;i++){
            for(j=L/prime[i]-2;prime[i] * j <= U ; j++){
                if(prime[i] * j - L < 0 || j == 1)continue;
                notPrime[prime[i] * j - L] = 1; 
            }
        }
        if(L == 1)notPrime[0] = 1;
        a = -1;
        b = -1;
        ans2 = 0;
        ans1 = 100000008;
        for(i=L;i<=U;i++){
            if(notPrime[i - L] == 0){
                if(a == -1){
                    a = i;
                }else{
                    if(b == -1)b = i;
                    else{a = b;b = i;}
                    if(b-a > ans2){
                        ans2 = b-a;
                        x1 = a;
                        x2 = b;
                    }
                    if(b-a < ans1){
                        ans1 = b-a;
                        y1 = a;
                        y2 = b;
                    }
                }
            }
        }
        if(a == -1 || b == -1)
            printf("There are no adjacent primes.\n");
        else
            printf("%d,%d are closest, %d,%d are most distant.\n",y1,y2,x1,x2);
    }
    return 0;
}
//
