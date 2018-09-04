#include<stdio.h>
#include<stdlib.h>
int sol(int n){
    int tmp;
    if(n == 1)return 1;
    if(n == 2)return 2;
    if(n%2 == 0)return 2*sol(n/2);
    else{
        tmp = sol((n+1)/2);
        if(tmp == 1)return 2*n-1;
        else return (tmp-1)*2;
    }
}
int main (){
    int n;
    while(1){
        scanf("%d",&n);
        if(n== 0)break;
        printf("%d\n",sol(n));
    }
    return 0;
} 
