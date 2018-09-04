#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int num[25];
int two[26];
int cnt[25];
int main (){
    int T,n,sum,tmp,tsum,tar,j;
    int i,flag;
    two[0] = 1;
    for(i=1;i<21;i++)
        two[i] = 2*two[i-1];
    scanf("%d",&T);
    while(T--){
        memset(cnt,0,sizeof(cnt));
        scanf("%d",&n);
        sum = 0;
        for(i=0;i<n;i++){
            scanf("%d",&num[i]);
            sum += num[i];
        }
        tar = sum / 2 + 1;
        //printf("tar %d\n",tar);
        for(i=1;i<two[n];i++){
            tmp = i;
            j = 0;
            tsum = 0;
            while(tmp > 0){
                if(tmp % 2 == 1){
                    tsum += num[j];
                }
                tmp = tmp >> 1;
                j++;
            }
            //printf("tsum %d\n",tsum);
            if(tsum >= tar){
                tmp = i;
                j = 0;
                while(tmp > 0){
                    if(tmp % 2 == 1){
                        if(tsum - num[j] < tar)
                            cnt[j]++;
                    }
                    tmp = tmp >> 1;
                    j++;
                }
            }
        }
        for(i=0;i<n;i++){
            printf("party %d has power index %d\n",i+1,cnt[i]);
        }
        printf("\n");
    }
    return 0;
}
