#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Edge{
    char name[30];
    int dis;
}matrix[105][105];
char name[10005][50];
char s[100],tmp[100];
int dis[105],par[105],vis[105],stack[105];
int main (){
    int i,j,len,a,b,n = 0,k,d,st,ed,now,MIN,top;
    while(1){
        gets(s);
        if(strcmp(s,"") == 0)break;
        len = strlen(s);
        i = 0;k = 0;
        while(s[i] != ','){
            tmp[k] = s[i];
            i++;
            k++;
        }
        tmp[k] = '\0';
        for(j=0;j<n;j++){
            if(strcmp(name[j],tmp) == 0){a = j;break;}
        }
        if(j == n){
            a = j;
            strcpy(name[j],tmp);
            n++;
        }
        k = 0;i++;
        while(s[i] != ','){
            tmp[k] = s[i];
            i++;
            k++;
        }
        tmp[k] = '\0';
        
        for(j=0;j<n;j++){
            if(strcmp(name[j],tmp) == 0){b = j;break;}
        }
        
        if(j == n){
            b = j;
            strcpy(name[j],tmp);
            n++;
        }
        k = 0;i++;
        while(s[i] != ','){
            tmp[k] = s[i];
            i++;
            k++;
        }
        tmp[k] = '\0';
        d = 0;i++;
        while(i < len){
            d = d * 10 + s[i] - 48;
            i++;
        }
        if(matrix[a][b].dis == 0 || (matrix[a][b].dis != 0 && d < matrix[a][b].dis)){
            matrix[a][b].dis = d;
            strcpy(matrix[a][b].name,tmp);
            matrix[b][a].dis = d;
            strcpy(matrix[b][a].name,tmp);            
        }    
    }

    while(gets(s)){
        k = 0;i = 0;
        while(s[i] != ','){
            tmp[k] = s[i];
            i++;
            k++;
        }
        tmp[k] = '\0';
        for(j=0;j<n;j++){
            if(strcmp(tmp,name[j])== 0){
                st = j;
                break;
            }
        }
        i++;
        k = 0;
        while(i < len){
            tmp[k] = s[i];
            i++;
            k++;
        }
        tmp[k] = '\0';
        for(j=0;j<n;j++){
            if(strcmp(tmp,name[j])== 0){
                ed = j;
                break;
            }
        }
        for(i=0;i<n;i++){
            dis[i] = 2100000000;
            vis[i] = 0;
        }
        dis[st] = 0;
        for(i=0;i<n;i++){
            MIN = 2100000000;
            for(j=0;j<n;j++){
                if(vis[j] == 0 && dis[j] < MIN){
                    k = j;
                    MIN = dis[j];
                }
            }
            vis[k] = 1;
            for(j=0;j<n;j++){
                if(matrix[k][j].dis != 0 && dis[k] + matrix[k][j].dis < dis[j]){
                    dis[j] = matrix[k][j].dis + dis[k];
                    par[j] = k;
                }
            }
        }
        top = 0;
        now = ed;
        while(now != st){
            stack[top] = now;
            top++;
            now = par[now];
        }
        stack[top] = st;
        printf("\n\nFrom                 To                   Route      Miles\n");
        printf("-------------------- -------------------- ---------- -----\n");
        for(i=top;i>0;i--){
            printf("%-20s %-20s %-10s %5d\n",name[stack[i]],name[stack[i-1]],matrix[stack[i]][stack[i-1]].name,matrix[stack[i]][stack[i-1]].dis);
        }
        printf("                                                     -----\n");
        printf("                                          Total      %5d\n",dis[ed]);
    }
    return 0;
}

