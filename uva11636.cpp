#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main (){
    int n,ca=0,ans;
    while(1){
        scanf("%d",&n);
        if(n < 0)break;
        ca++;
//        printf("== %lf\n",log(n)/log(2));
        ans = (int)(log(n)/log(2));
        if(log(n)/log(2) > (int)(log(n)/log(2)))ans++;
        printf("Case %d: %d\n",ca,ans);
    }
}
