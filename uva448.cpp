#include<stdio.h>
#include<stdlib.h>
int num[20005];
int main (){
    int T,n,i,left,right,MAX,tl,tr,tmp,ca = 0,minus= 0;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        MAX = 0;
        minus = 0;
        for(i=0;i<n-1;i++){
            scanf("%d",&num[i]);
            if(num[i] >= 0)minus = 1;
        }
        tl = 0;tr = 0;tmp = 0;left = 0;right = 0;
        for(i=0;i < n-1;i++){
            tmp += num[i];
            if(tmp > MAX || (tmp == MAX && right - left < i - tl)){
                MAX = tmp;
                left = tl;
                right = i;
            }
            if(tmp < 0){
                tl = i+1;
                tmp = 0;
            }
        }
        ca++;
        if(minus == 1)
            printf("The nicest part of route %d is between stops %d and %d\n",ca,left+1,right+2);
        else 
            printf("Route %d has no nice parts\n",ca);
    }
    return 0;
}
