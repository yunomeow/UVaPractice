#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main (){
    double n;
    while(scanf("%lf",&n)!= EOF){
        while(n > 18){
            n /= 18;
        }
        if(n > 9)printf("Ollie wins.\n");
        else printf("Stan wins.\n");
    }
    return 0;
}
