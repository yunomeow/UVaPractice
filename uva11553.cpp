#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int in[100][100];
int use[10];
int n,ans;
void dfs(int pos,int now){
    int i;
    if(pos == n){
        if(ans > now){
            ans = now;
        }
    }
    for(i=0;i<n;i++){
        if(use[i] == 0){
            use[i] = 1;
            dfs(pos+1,now+in[pos][i]);
            use[i] = 0;
        }
    }
}
int main (){
    int T,i,j;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                scanf("%d",&in[i][j]);
        memset(use,0,sizeof(use));
        ans = 100000000;
        dfs(0,0);
        printf("%d\n",ans);
    }
    return 0;
}
/*
3
2
10 10
-5 -5
*/
