#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int prime[30000];
int use[50000],x=0;
int main (){
    int n,len,now,tmp,i,a,b,j,cnt,flag;
    char s[100005];
    prime[0] = 2;
    x++;
    for(i=3;i<40000;i+=2){
        if(use[i] == 0){
            prime[x] = i;
            x++;
            for(j=i+i;j<40000;j+=i){
                use[j] = 1;
            }
        }
    }
    while(1){
        gets(s);
        if(strcmp(s,"0") == 0)break;
        n = 1;now = 0;len = strlen(s);
        while(now < len){
            sscanf(s+now,"%d%d%n",&a,&b,&tmp);
            for(i=1;i<=b;i++)
                n = n * a;
            now+=tmp;
        }
        n--;
        flag = 0;
        for(i=x-1;i>=0;i--){
            cnt = 0;
            while(n % prime[i] == 0){
                cnt++;
                n /= prime[i];
            }
            if(cnt > 0){
                if(flag == 1)printf(" ");
                printf("%d %d",prime[i],cnt);
                flag = 1;
            }
        }
        printf("\n");
    }
    return 0;
}

