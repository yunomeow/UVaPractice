#include<stdio.h>
#include<stdlib.h>
int main (){
    long long T,a,b,c,ca = 0;
    scanf("%lld",&T);
    while(T--){
        scanf("%lld%lld%lld",&a,&b,&c);
        ca++;printf("Case %lld: ",ca);
        if(a+b <= c || b+c <= a || a+c <= b || a <= 0 || b <= 0 || c <= 0){
            printf("Invalid\n");
        }else if(a == b && b == c){
            printf("Equilateral\n");
        }else if(a == b || b == c || a== c){
            printf("Isosceles\n");
        }else
            printf("Scalene\n");
        
    }
    return 0;
}
