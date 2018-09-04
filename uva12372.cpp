#include<stdio.h>
#include<stdlib.h>
int main (){
    int a,b,c,flag,T;
    int ca = 0;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d",&a,&b,&c);
        flag = 1;
        if(a > 20)flag = 0;
        if(b > 20)flag = 0;
        if(c > 20)flag = 0;
        ca++;
        if(flag == 1)printf("Case %d: good\n",ca);
        else if(flag == 0)printf("Case %d: bad\n",ca);
    }
    return 0;
}
