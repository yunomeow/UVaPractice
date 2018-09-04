#include<stdio.h>
#include<stdlib.h>
int isprime[10005];
int prime[200000];
int use[200000];
int main (){
    int a,b,i,j,n,flag,cnt,x=0,k;
    for(i=2;i<20005;i++){
        if(use[i] == 0){
            prime[x] = i;
            x++;
            for(j=2;i*j<20005;j++){
                use[i*j] = 1;
            }
        }
    }
    for(i=0;i<=10000;i++){
        k = i*i+i+41;
        flag = 1;
        for(j=0;j<x;j++){
            if(prime[j] >= k)break;
            if(k % prime[j] == 0){
                flag = 0;
                break;
            }
        }
        if(flag == 1){
            isprime[i] = 1;
        }
    }
    while(scanf("%d%d",&a,&b) != EOF){
        cnt = 0;
        for(i=a;i<=b;i++){
            if(isprime[i]==1)cnt++;
        }
        printf("%.2lf\n",100*((double)cnt/(double)(b-a+1))+1e-9);
    }
    return 0;
}
