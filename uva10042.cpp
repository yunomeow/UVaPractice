#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int prime[80000];
int use[80000],x=0,T;
int countdigit(int n){
    int tmp;
    tmp = 0;
    while(n > 0){
        tmp += n % 10;
        n /= 10;
    }
    return tmp;
}
int main (){
    int n,len,now,tmp,i,a,b,j,cnt,flag,sump,sumd,isprime;
    char s[100005];
    prime[0] = 2;
    x++;
    for(i=3;i<70000;i+=2){
        if(use[i] == 0){
            prime[x] = i;
            x++;
            for(j=i+i;j<70000;j+=i){
                use[j] = 1;
            }
        }
    }
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        while(1){
            n++;
            tmp = n;
            sumd = 0;sump = 0;
            while(tmp > 0){
                sumd += tmp % 10;
                tmp /= 10;
            }
            isprime = 0;
            tmp = n;
            for(i=0;i<x;i++){
                while(tmp % prime[i] == 0){
                    isprime++;
                    sump += countdigit(prime[i]);
                    tmp /= prime[i];
                }
            }
            if(tmp > 1){
                isprime++;
                sump += countdigit(tmp);
            }
            if(isprime == 1)continue;
            else{
                if(sump == sumd){
                    printf("%d\n",n);
                    break;
                }
            }
        }
    }
    return 0;
}
