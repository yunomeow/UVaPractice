#include<stdio.h>
#include<stdlib.h>
int isprime[33];
int use[20],num[20];
void dfs(int pos,int n){
    int i;
    if(pos == n){
        if(isprime[num[pos-1] + 1]==1){
            for(i=0;i<n;i++){
                if(i != 0)printf(" ");
                printf("%d",num[i]);
            }
            printf("\n");
        }
        return ;
    }
    for(i=1;i<=n;i++){
        if(use[i] == 0){
            if(isprime[num[pos-1] + i] == 1){
                num[pos] = i;
                use[i] = 1;
                dfs(pos+1,n);
                use[i] = 0;
            }
        }
    }
}
int main (){
    int n,flag = 0,ca = 0;
    isprime[2] = isprime[3] = isprime[5] = isprime[7] = 1;
    isprime[11] = isprime[13] = isprime[17] = isprime[19] = 1;    
    isprime[23] = isprime[29] = isprime[31] = 1;
    num[0] = 1;
    use[1] = 1;
    while(scanf("%d",&n) != EOF){
        if(flag == 1)printf("\n");
        flag = 1;
        ca++;
        printf("Case %d:\n",ca);
        dfs(1,n);
    } 
    return 0;
}
