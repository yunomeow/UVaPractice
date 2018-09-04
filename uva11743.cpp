#include<stdio.h>
#include<stdlib.h>
int main (){
    int T,n,sum1,sum2,i,j,tmp;
    scanf("%d",&T);
    while(T--){
        sum1 = 0;sum2 = 0;
        for(i=0;i<4;i++){
            scanf("%d",&n);
            for(j=0;j<4;j++){
                if(j%2 == 0){
                    tmp = n % 10;
                    sum2 += tmp;
                }else{
                    tmp = n % 10;
                    tmp *= 2;
                    while(tmp > 0){
                        sum1 += tmp % 10;
                        tmp /= 10;
                    }
                }
                n /= 10;
            }
        }
        if((sum1+sum2)%10==0){
            printf("Valid\n");
        }else
            printf("Invalid\n");
    }
    return 0;
}
