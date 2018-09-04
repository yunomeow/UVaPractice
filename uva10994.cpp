#include<stdio.h>
#include<stdlib.h>
long long f(long long n){
    long long i,j,tmp = 0;
    while(n > 0){
        tmp += 45*(n/10);
        for(j=n%10;j>0;j--)
            tmp+=j;
        n/=10;
    }
    return tmp;
}
int main (){
    int i,p,q;
    while(1){
        scanf("%d%d",&p,&q);
        if(p < 0 && q < 0)break;
        printf("%lld\n",f(q)-f(p-1));
    }
    return 0;
}
