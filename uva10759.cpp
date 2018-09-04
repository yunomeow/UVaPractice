#include<stdio.h>
#include<stdlib.h>
#include<string.h>
long long dice[200],newdice[200];
long long gcd(long long a,long long b){
    while((a%=b)&&(b%=a));
    return a+b;
}
int main (){
    int i,n,x,j,k;
    long long ans,all,g;
    while(1){
        scanf("%d%d",&n,&x);
        if(n == 0 && x == 0)break;
        memset(dice,0,sizeof(dice));
        for(i=1;i<=6;i++){
            dice[i] = 1;
        }
        for(i=0;i<n-1;i++){
            memset(newdice,0,sizeof(newdice));
            for(j=1;j<160;j++){
                for(k=1;k<=6;k++){
                    newdice[j+k] += dice[j];
                }
            }
            for(j=0;j<160;j++)
                dice[j] = newdice[j];
        }
        ans = 0;all = 0;
        for(i=0;i<160;i++)
            all+=dice[i];
        for(i=x;i<=n*6;i++)
            ans+=dice[i];
        if(all != 0 && ans != 0){
            g = gcd(all,ans);
            all/=g;
            ans/=g;
            if(all == 1 && ans == 1)
                printf("1\n");
            else
                printf("%lld/%lld\n",ans,all);
        }else{
            printf("0\n");
        }
    }
    return 0;
}
