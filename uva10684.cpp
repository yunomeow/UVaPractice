#include<stdio.h>
#include<stdlib.h>
int main (){
    int n,tmp,now,MAX,i;
    while(1){
        scanf("%d",&n);
        if(n == 0)break;
        now = 0;MAX = 0;
        for(i=0;i<n;i++){
            scanf("%d",&tmp);
            now += tmp;
            if(now < 0)now = 0;
            if(now > MAX)MAX = now;
        }
        if(now == 0)
            printf("Losing streak.\n");
        else
            printf("The maximum winning streak is %d.\n",MAX);
    }
    return 0;
}
