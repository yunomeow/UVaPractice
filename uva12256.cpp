#include<stdio.h>
#include<stdlib.h>
long long ans[100];
int main (){
    int i,ca = 0,n;
    ans[1] = 1;
    ans[2] = 1;
    ans[3] = 1;
    for(i=4;i<=61;i++)
        ans[i] = ans[i-1] + ans[i-2] + ans[i-3];
    while(1){
        ca++;
        scanf("%d",&n);
        if(n == 0)break;
        printf("Case %d: %lld\n",ca,ans[n]);
    }
    return 0;
}
