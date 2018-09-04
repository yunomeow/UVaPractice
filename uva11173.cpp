#include<stdio.h>
#include<stdlib.h>
int two[32];
int main (){
    int cnt,i,n,k,T,left,right,mid;
    two[0] = 1;
    for(i=1;i<=30;i++)
        two[i] = two[i-1]*2;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&k);
        left = 0; right = two[n]-1;
        cnt = 0;
        for(i=n-1;i>=0;i--){
            mid = (left + right) / 2;
            if(cnt % 2 == 0){
                if(k < two[i]){ 
                    right = mid;
                } 
                else{
                    left = mid;
                    k -= two[i];
                    cnt++;
                }
            }else{
                if(k < two[i]){
                    left = mid;
                    cnt++;
                }else{
                    right = mid;
                    k -= two[i];
                }
            }
     //       printf("left %d right %d\n",left,right);
        }
        printf("%d\n",right);
    }
    return 0;
}
