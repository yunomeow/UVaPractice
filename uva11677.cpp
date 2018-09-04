#include<stdio.h>
#include<stdlib.h>
int main (){
    int a,b,c,d,t1,t2,ans;
    while(1){
        scanf("%d%d%d%d",&a,&b,&c,&d);
        if(a == 0 && b == 0 && c == 0 && d == 0)break;
        t1 = a*60+b;
        t2 = c*60+d;
        ans = t2 - t1;
        if(ans < 0)ans+=1440;
        printf("%d\n",ans);
    }
    return 0;
}
