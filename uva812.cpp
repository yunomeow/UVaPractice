#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
int num[55][25],sum[55][25],top[55];
int ans[505],ans2[505];
int main (){
    int w,i,j,n,tmp,MAXp,ca=0,minnum,flag,k,x,y;
    while(1){
        scanf("%d",&w);
        if(w == 0)break;
        if(ca != 0)printf("\n");
        for(i=0;i<w;i++){
            scanf("%d",&n);
            top[i] = n;
            for(j=0;j<n;j++)
                scanf("%d",&num[i][j]);
        }
        for(i=0;i<w;i++){
            sum[i][0] = 10-num[i][0];
            for(j=1;j<top[i];j++){
                sum[i][j] = (10-num[i][j])+sum[i][j-1];
            }
        }
        MAXp = 0;minnum = 0;
        memset(ans,-1,sizeof(ans));
        ans[0] = 0;
        for(i=0;i<w;i++){
            tmp = 0;
            for(j=0;j<top[i];j++)
                if(sum[i][j] > tmp)
                    tmp = sum[i][j];
            y = 0;
            for(j=0;j<top[i];j++){
                if(sum[i][j] == tmp){
                    for(k=0;k<10;k++){
                        if(ans[k] != -1){
                            ans2[y] = ans[k]+j+1;
                            y++;
                        }
                    }
                }
            }
            if(tmp == 0){
                for(k=0;k<10;k++){
                    if(ans[k] != -1){
                        ans2[y] = ans[k];
                        y++;
                    }
                }
            }
           // printf("y %d\n",y);
            if(y != 0){
                sort(ans2,ans2+y);
                x = 0;
                for(j = 0;j < y;j++){
                    if(j == 0 || ans2[j] != ans2[j-1]){
                        ans[x] = ans2[j];
                        x++;
                    }
                }
            }
            MAXp += tmp;
        }
        ca++;
        printf("Workyards %d\n",ca);
        printf("Maximum profit is %d.\n",MAXp);
        printf("Number of pruls to buy:");
        for(i=0;i < x && i < 10;i++)
            printf(" %d",ans[i]);
        printf("\n");
    }

    return 0;
}
