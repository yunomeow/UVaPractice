#include<stdio.h>
#include<stdlib.h>
int main (){
    int n,k,p,T,ca = 0;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d",&n,&k,&p);
        ca++;
        printf("Case %d: ",ca);
        if((k+p)%n == 0)printf("%d\n",n);
        else printf("%d\n",(k+p)%n);
    }
}
