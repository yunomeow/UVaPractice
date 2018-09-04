#include<stdio.h>
#include<stdlib.h>
int main (){
    unsigned long long k,tmp,i;
    int flag ;
    while(1){
        scanf("%llu",&k);
        if(k == 0)break;
        tmp = (k-1)*10;
        flag = 0;
        for(i=tmp+1;i<=k*10;i++){
            if(i%9==0){
                if(flag == 1)printf(" ");
                printf("%llu",i/9);
                flag =1 ;
            }
        }
        printf("\n");
    }
}
