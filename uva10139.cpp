#include<stdio.h>
#include<stdlib.h>
int use[66666],prime[66666];
int main(){
    int n,m,x,ii,cnt,flag,tmp,nn,mm;
    long long i,j;
    x = 1;
    prime[0] = 2;
    for(i=3;i<65536;i+=2){
        if(use[i] == 0){
            prime[x] = i;
            x++;
            ii = 2*i;
            for(j=i*i;j < 65536; j+=ii){
                use[j] = 1;
            }
        }
    }
    while(scanf("%d%d",&n,&m)!=EOF){
        flag = 1;
        mm = m;
        for(i=0;i<x;i++){
            tmp = 0;
            if(m < prime[i])break;
            while(m % prime[i] ==0){
                m /= prime[i];
                tmp++;
            }
            if(tmp > 0){
                cnt = 0;
                nn = n;
                while(nn > 0){
                    cnt += nn / prime[i];
                    nn /= prime[i];
                }
                if(cnt < tmp){flag = 0;break;}
            }
        }
        if(m != 0){
            if(n < m)flag = 0;
        }
        if(m == 0||n == 0)flag = 0 ;
        if(mm == 1 && n == 0)flag = 1;
        if(flag == 1)
            printf("%d divides %d!\n",mm,n);
        else
            printf("%d does not divide %d!\n",mm,n);
    }
    return 0;
}
