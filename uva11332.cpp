#include<stdio.h>
#include<stdlib.h>
int main (){
    int n,tmp;
    while(1){
        scanf("%d",&n);
        if(n == 0)break;
        while(n >= 10){
            tmp = 0;
            while(n > 0){
                tmp += n%10;
                n /= 10;
            }
            n = tmp;
        }
        printf("%d\n",n);
    }
    return 0;
}
