#include<stdio.h>
#include<stdlib.h>
#include<string.h>
long long num[1000];
int part[1000];
int main (){
    int i,T,n,k,flag;
    long long left,right,mid,need,tmp;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&k);
        for(i=0;i<n;i++)
            scanf("%lld",&num[i]);
        left = 0; right = 2147483647;
        while(right - left > 1){
            mid = ( left + right ) / 2;
            memset(part,0,sizeof(part));
            need = 0;
            tmp = 0;
            flag = 1;
            for(i=0;i<n;i++){
                if(tmp > mid){
                    flag = 0;
                    break;
                }
                if(tmp + num[i] > mid){
                    part[i] = 1;
                    need++;
                    tmp = num[i];
                }else{
                    tmp += num[i];
                }
            }
            if(need > k-1)flag = 0;
            if(flag == 1)right = mid;
            else left = mid;
        }
        memset(part,0,sizeof(part));
        tmp = 0;
        need = 0;
        mid = right;
        for(i=n-1;i>=0;i--){
            if(tmp + num[i] > mid){
                part[i] = 1;
                need++;
                tmp = num[i];
            }else{
                tmp += num[i];
            }
        }    
        for(i=0;i<n;i++){
            if(need < k-1 && n > need + 1){
                if(part[i+1] == 0){
                    part[i+1] = 1;
                    need++;
                }
            }else
                break;
        }
        for(i=0;i<n;i++){
            printf("%d",num[i]);
            if(i != n-1)printf(" ");
            if(part[i] == 1)printf("/ ");
            
        }
        printf("\n");
    }
    return 0;
}
