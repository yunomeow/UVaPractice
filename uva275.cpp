#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int ans[2055];
int vis[2055];
int main (){
    int up,down,i,flag,k,last,first;
    while(1){
        scanf("%d%d",&up,&down);
        if(up == 0 && down == 0)break;
        flag = 0;
        for(i=0;i<1001;i++)
            vis[i] = -1;
        vis[up] = 0;
        for(i=0;i<2*down+1;i++){
            up = up * 10;
            ans[i] = up/down;
            up -= down * (up/down) ;
            if(vis[up] != -1){last = i-vis[up]+1;k = i;break;}
            vis[up] = i+1;
            if(up == 0){k = i;flag = 1; break;}
        }
        first = 0;
        if(flag == 1){
            printf(".");
            for(i=0;i<=k;i++){
                if((i %50 == 49 && k > i))printf("\n");
                printf("%d",ans[i]);
            }
            printf("\nThis expansion terminates.\n\n");
        }else{
            printf(".");
            for(i=0;i<=k;i++){
                if((i %50 == 49 && k > i))printf("\n");
                printf("%d",ans[i]);
            }
            printf("\nThe last %d digits repeat forever.\n\n",last);
        }
    }
    return 0;
}
