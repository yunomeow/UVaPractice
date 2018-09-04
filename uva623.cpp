#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int num[10000];
int main (){
    int n,i,j,flag;

    while(scanf("%d",&n)!=EOF){
        if(n < 2)printf("%d!\n1\n",n);
        else{
            memset(num,0,sizeof(num));
            num[0] = 1;
            for(i=2;i<=n;i++){
                for(j=0;j<1000;j++)
                    num[j] *= i;
                for(j=0;j<1000;j++){
                    if(num[j] >= 1000){
                        num[j+1] += num[j] / 1000;
                        num[j] %= 1000;
                    }
                }
            }
            flag = 0;
            printf("%d!\n",n);
            for(j=1000;j>=0;j--){
                if(flag == 1)printf("%03d",num[j]);
                else{
                    if(num[j] != 0){
                        printf("%d",num[j]);
                        flag = 1;
                    }
                }
            }
            printf("\n");
        }
    }
    return 0;
}
