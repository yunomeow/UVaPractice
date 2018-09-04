#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int num[10000];
int main (){
    int T,n,a1,a2,ca=0,i;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(i=0;i<n;i++){
            scanf("%d",&num[i]);
        }
        a1 = 0;
        for(i=0;i<n;i++){
            a1 += (num[i] / 30 + 1)*10;
        }
        a2 = 0;
        for(i=0;i<n;i++){
            a2 += (num[i] / 60 + 1)*15;
        }
        ca++;

        printf("Case %d: ",ca);
        if(a1 < a2)printf("Mile %d\n",a1);
        else if(a1 > a2)printf("Juice %d\n",a2);
        else printf("Mile Juice %d\n",a1);
    }
    return 0;
}
