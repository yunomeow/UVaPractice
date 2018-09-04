#include<stdio.h>
#include<stdlib.h>
int n;
int vis[1000];
int matrix[105][105];
void dfs(int pos){
    int i;
    vis[pos] = 0;
    for(i=0;i<n;i++){
        if(i == pos)continue;
        if(matrix[pos][i] == 1 && vis[i] == 0)
            dfs(i);
    }
}
int main (){
    char in[100];
    int m,a,i,len;
    while(1){
        scanf("%d",&n);
        if(n == 0)break;
        scanf("%d%s",&a,in);
        len = strlen(in);
        in[0] = ' ';
        in[len-1] = ' ';
        sscanf(in,"%d",&m);
        memset(matrix,0,sizeof(matrix));
        memset(vis,0,sizeof(vis));
        for(i=0;i<m;i++){
            scanf("%d",&b);
            matrix[a][b] = 1;
            matrix[b][a] = 1;
        }
    }
    return 0;
}
/*
8
0 (1) 1
1 (3) 2 0 3
2 (2) 1 3
3 (3) 1 2 4
4 (1) 3
7 (1) 6
6 (1) 7
5 (0)
*/

