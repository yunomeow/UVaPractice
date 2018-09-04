#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int matrix[30][30],appear[30];
int end[30],vis[30],t;
void dfs(int pos){
    int i;
    vis[pos] = 1;
    for(i=0;i<26;i++){
        if(matrix[pos][i] == 1 && vis[i] == 0){
            dfs(i);
        }
    }
    end[t] = pos;
    t++;
}
int main(){
    char pre[25]="",now[25];
    int lenp,lenn,i,j,flag;
    while(1){
        scanf("%s",now);
        lenn = strlen(now);
        for(i=0;i<lenn;i++)
            appear[now[i]-65] = 1;
        if(strcmp(now,"#") == 0)break;
        if(strcmp(pre,"")!=0){
            for(i=0;i < lenn && i < lenp;i++){
                if(pre[i] != now[i] && now[i] >='A' && pre[i] >= 'A'){
                    matrix[pre[i]-'A'][now[i]-'A'] = 1;
                    
                   // printf("%c -> %c\n",pre[i],now[i]);
                    break;
                }
            }
        }
        strcpy(pre,now);
        lenp = strlen(pre);
    }
    t = 0;   
/*
     for(i=0;i<26;i++){
        for(j=0;j<26;j++)
            printf("%d ",matrix[i][j]);
        printf("\n");
    }
    */
    for(i=0;i<26;i++){
        if(vis[i] == 0)
            dfs(i);
    }
    for(i=t-1;i>=0;i--){
        if(appear[end[i]] == 1){
            printf("%c",end[i]+65);
        }
    }
    printf("\n");
    system("pause");
    return 0;
}
