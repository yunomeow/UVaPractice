#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int matrix[105][105];
int vis[105],n;
void dfs(int pos){
    int i;
    vis[pos] = 1;
    for(i=1;i<=n;i++){
        if(matrix[pos][i] == 1 && vis[i] == 0){
            vis[i] = 1;
            dfs(i);
        }
    }
}
int main (){
    int i,now,tmp,len,cnt,ans,j;
    int a,b;
    char s[100000];
    while(1){
        scanf("%d%*c",&n);
        memset(matrix,0,sizeof(matrix));
        if(n == 0)break;
        while(1){
            gets(s);
            if(strcmp(s,"0") == 0)break;
            now = 0;len = strlen(s);
            a = -1;
            while(now < len){
                if(a == -1)
                    sscanf(s+now,"%d%n",&a,&tmp);
                else{
                    sscanf(s+now,"%d%n",&b,&tmp);
                    matrix[a][b] = 1;
                    matrix[b][a] = 1;
                }
                now += tmp;
            }
        }
        ans = 0;
        for(i=1;i<=n;i++){
            cnt = 0;
            memset(vis,0,sizeof(vis));
            vis[i] = 1;
            for(j=1;j<=n;j++){
                if(i!=j && vis[j] == 0){
                    dfs(j);
                    cnt++;
                }
            }
            if(cnt > 1)ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}
