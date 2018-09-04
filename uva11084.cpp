#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
int use[15],num[15],val[15],x = 0,len;
long long ans[3628810];
void dfs(int pos){
    int i;
    long long tmp;
    if(pos == len){
        tmp = 0;
        for(i=0;i<len;i++)
            tmp = tmp * 10 + val[i];
        ans[x] = tmp;
        x++;
        return ;
    }
    for(i=0;i<len;i++){
        if(use[i] == 0 && (i == 0 || (i > 0 && num[i] != num[i-1]) )){
            val[pos] = num[i];
            use[i] = 1;
            dfs(pos+1);
            use[i] = 0;
        }
    }
}
int main (){
    int T,n,d,cnt= 0,i;
    char s[10090];
    scanf("%d%*c",&T);
    while(T--){
        scanf("%s%d",s,&d);
        printf("%s\n",s);
        len = strlen(s);
        for(i=0;i<len;i++){
            num[i] = s[i]-48;
        }
       // printf("len %d\n",len);
        x = 0;
        dfs(0);
        cnt = 0;
        sort(ans,ans+x);
       // printf("x = %d\n",x);
        if(ans[0] % d == 0)cnt++;
      //  printf("\n");
        for(i=1;i<x;i++)
            if(ans[i] != ans[i-1] && ans[i] % d == 0)
                cnt++;
        printf("%d\n",cnt);
    }
    return 0;
}
