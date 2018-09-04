#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int happy[10000],x,first;
int appear[10000];
int solve(int n){
    int tmp = 0,tn = n,flag;
    if(n < 10000 && appear[n] == 1){
        happy[n] = 0;
        return 0;
    }
    if(n < 10000)
        appear[n] = 1;
    if(n == 1){
        happy[n] = 1;
        return happy[n];
    }
    if(n < 10000 && happy[n] != -1)
        return happy[n];
    while(tn > 0){
        tmp += (tn%10)*(tn%10);
        tn /= 10;
    }
    flag = solve(tmp);
    if(n < 10000)
        happy[n] = flag;
    return flag;
}
int main (){
    int n,T,tmp,ori,flag,next,ca = 0,i;
    scanf("%d",&T);
    for(i=0;i<10000;i++)
        happy[i] = -1;
    while(T--){
        scanf("%d",&n);
        first = 0;
        x = n;
        memset(appear,0,sizeof(appear));
        flag = solve(n);
        ca++;
        if(flag == 0)
            printf("Case #%d: %d is an Unhappy number.\n",ca,n);
        else 
            printf("Case #%d: %d is a Happy number.\n",ca,n);
    }
}
