#include<stdio.h>
#include<stdlib.h>
int card[25];
int alive[100];
int main (){
    int i,n,k,ca = 0,now,j,cnt,flag;
    while(scanf("%d%d",&n,&k)!=EOF){
        for(i=0;i<20;i++)
            scanf("%d",&card[i]);
        for(i=0;i<n;i++){
            alive[i] = 1;
        }
        now = n;
        for(i=0;i<20;i++){
            cnt = 0;
            if(now <= k)break;
            for(j=0;j<n;j++){
                if(alive[j] == 1){
                    cnt++;                
                    if(cnt % card[i] == 0){
                        alive[j] = 0;
                        now--;
                    }
                }

                if(now <= k)break;
            }
        }
        ca++;
        printf("Selection #%d\n",ca);
        flag = 0;
        for(i=0;i<n;i++)
            if(alive[i] == 1){
                if(flag == 1)printf(" ");
                flag = 1;
                printf("%d",i+1);
            }
        printf("\n\n");
    }
    return 0;
}
