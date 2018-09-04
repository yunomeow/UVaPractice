#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int matrix[100][100];
int vis[100],group[100],n;
void dfs(int pos,int x){
    int i;
    vis[pos] = 1;
    for(i=0;i<=n;i++){
        if(matrix[pos][i] == 1 && vis[i] == 0){
            dfs(i,x);
        }
    }
}
int main (){
    int i,T,x,ans,MAX,cnt,flag = 0,j;
    char ch,ch2;
    scanf("%d%*c%*c",&T);
    while(T--){
        if(flag == 1)printf("\n");
        flag = 1;
        scanf("%c%*c",&ch);
        memset(matrix,0,sizeof(matrix));
        n = ch - 'A';
        while(scanf("%c",&ch) !=EOF){
            if(ch == '\n')break;
            scanf("%c%*c",&ch2);
//            printf("%d to %d\n",ch-'A',ch2-'A');
            matrix[ch-'A'][ch2-'A'] = 1;
            matrix[ch2-'A'][ch-'A'] = 1;
        }
        for(i=0;i<=n;i++)group[i] = vis[i] = 0;
        x = 0;
        for(i=0;i<=n;i++){
            if(vis[i] == 0){
                dfs(i,x);
                x++;
            }
        }
        printf("%d\n",x);
    }
}
