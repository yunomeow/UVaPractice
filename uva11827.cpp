#include<stdio.h>
#include<stdlib.h>
#include<string.h>
long long gcd(long long a,long long b){
    while((a%=b)&& (b%=a));
    return a+b;
}
long long num[10005];
char s[1000005];
int main (){
    long long ans;
    int tmp,now,len,T,i,j,x;
    scanf("%d%*c",&T);
    while(T--){
        x = 0;
        ans = 0;
        now = 0;
        gets(s);
        len = strlen(s);
        while(now < len){
            sscanf(s+now,"%lld%n",&num[x],&tmp);
            now += tmp;
            x++;
        }
        for(i=0;i<x;i++)
            for(j=i+1;j<x;j++)
                if(num[i]!= 0 && num[j] != 0 && gcd(num[i],num[j]) > ans)
                    ans = gcd(num[i],num[j]);
        printf("%lld\n",ans);
    }
    return 0;
}
