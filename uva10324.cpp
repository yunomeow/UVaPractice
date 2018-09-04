#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char s[1000005];
int sum[1000005];
int main (){
    int i,j,tmp,a,b,T,len,ca=0;
    while(gets(s)){
        ca++;
        printf("Case %d:\n",ca);
        len = strlen(s);
        sum[0] = 0;
        for(i=0;i<len;i++){
            sum[i+1] = sum[i] + s[i] - 48;
        }
        scanf("%d",&T);
        while(T--){
            scanf("%d%d%*c",&a,&b);
            if(a > b){tmp = a;a = b;b = tmp;}
            if(sum[b+1] - sum[a] == b-a+1 || sum[b+1]-sum[a] == 0){
                printf("Yes\n");
            }else
                printf("No\n");
        }
    }
    return 0;
}
