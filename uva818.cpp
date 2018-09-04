#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int open[16],n;
int ans = 100;
int matrix[20][20];
int newmatrix[20][20];
int vis[20];
int num[20];
int degree[20];
int total;
int cycle_detect;
void find_cycle(int pos){
    int i;
    num[total] = pos;
    total++;
    vis[pos] = 1;
    for(i=1;i<=n;i++){
        if(vis[i] == 0 && matrix[pos][i] == 1){
            find_cycle(i);
        }
    }
}
void dfs(int pos,int now){
    int i,j,cnt,k,tmp;
    if(pos == n+1){
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                newmatrix[i][j] = matrix[i][j];
            }
        }
        memset(vis,0,sizeof(vis));
        for(i=1;i<=n;i++){
            if(open[i] == 1){
                vis[i] = 1;
                for(j=1;j<=n;j++){
                    newmatrix[i][j] = 0;
                    newmatrix[j][i] = 0;
                }
            }
        }
        cnt = 0;
        cycle_detect = 0;
        for(i=1;i<=n;i++){
            if(open[i] == 0 && vis[i] == 0){
                total = 0;
                find_cycle(i);
                cnt++;
                memset(degree,0,sizeof(degree));
                for(j=0;j<total;j++){
                    tmp = 0;
                    for(k=1;k<=n;k++){
                        if(newmatrix[num[j]][k] == 1)tmp++;
                    }
                    degree[tmp]++;
                }
                for(j=3;j<20;j++)if(degree[j] > 0)cycle_detect = 1;
                if(total > 1 && degree[1] != 2)cycle_detect = 1;
            }
        }
       // printf("cycle_detect %d cnt %d now %d\n",cycle_detect,cnt,now);
        if(cycle_detect == 1)return;
        if(now >= cnt-1){
            if(ans > now)ans = now;
        }
        return ;
    }
    if(now >= ans)return;
    open[pos] = 1;
    dfs(pos+1,now+1);
    open[pos] = 0;
    dfs(pos+1,now);
}

int main (){
    int i,a,b,ca=0;
    while(1){
        scanf("%d",&n);
        if(n == 0)break;
        memset(matrix,0,sizeof(matrix));
        while(1){
            scanf("%d%d",&a,&b);
            if(a == -1 && b == -1)break;
            matrix[a][b] = 1;
            matrix[b][a] = 1;
        }
        ans = 100;
        dfs(1,0);
        ca++;
        printf("Set %d: Minimum links to open is %d\n",ca,ans);
    }
    return 0;    
}
/*
5 1 2 2 3 4 5 -1 -1
7 1 2 2 3 3 1 4 5 5 6 6 7 7 4 -1 -1
4 1 2 1 3 1 4 -1 -1
3 1 2 2 3 3 1 -1 -1
3 1 2 2 1 -1 -1
*/
