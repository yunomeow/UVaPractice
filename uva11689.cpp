#include<stdio.h>
#include<stdlib.h>
int main (){
    int a,b,c,T,tmp,cnt,ex;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d",&a,&b,&c);
        tmp = a+b;
        cnt = 0;
        while(tmp >= c){
            cnt += tmp / c;
            ex = tmp % c;
            tmp /= c;
            tmp += ex;
        }
        printf("%d\n",cnt);
    }
    return 0;
}
