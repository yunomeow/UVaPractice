#include<stdio.h>
#include<stdlib.h>
int main (){
    int i,flag,n;
    long long tmp;
    while(scanf("%d",&n)!=EOF){
        flag = 2;
        tmp = 1;
        if(n < 0){
            if(n % 2 == 0)flag = 0;
            else flag = 1 ;
        }
        else{
            for(i=1;i<=n;i++){
                tmp *= i;
                if(tmp > 6227020800ll){
                    flag = 1;
                    break;
                }
            }
            if(tmp < 10000){
                flag = 0;
            }
        }
        if(flag == 2)printf("%lld\n",tmp);
        else if(flag == 1 )printf("Overflow!\n");
        else printf("Underflow!\n");
    }
    return 0;
}
