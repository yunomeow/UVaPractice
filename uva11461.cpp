#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main (){
    int i,a,b,sq,cnt;
    while(1){
        scanf("%d%d",&a,&b);
        if(a == 0 && b == 0)break;
        cnt = 0;
        for(i=a;i<=b;i++){
            sq = (int)(sqrt(i)+0.5);
            if(sq * sq == i)cnt++;
        }
        printf("%d\n",cnt);
    }
    return 0;
}
