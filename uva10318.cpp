#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char MAP[3][3];
int dir[9][2] = {-1,-1,0,-1,1,-1,
                 -1,0,0,0,1,0,
                 -1,1,0,1,1,1};
int type[9];
int n,flag,m;
int ans[100];
int press[40];
int light[10][10],step;
int check(){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            if(light[i][j] == 0)return 0;
        }
    }
    return 1;
}
void dfs(int pos,int now){
    int i,x,y,nx,ny,t=0,valid,j,k;
    int oldlight[10][10];
    if(pos == n*m+1){
        if(check() == 1){
            if(now < step){
                for(i=1;i<=n*m;i++){
                    if(press[i] == 1){
                        ans[t] = i;
                        t++;
                    }
                }
                step = now;
            }
        }
        return ;
    }
    if(now > step)return;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            oldlight[i][j] = light[i][j];
        }
    }
    press[pos] = 1;
    x = (pos-1) / m;
    y = (pos-1) % m;
    for(k=0;k<9;k++){
        nx = x + dir[k][1];
        ny = y + dir[k][0];
        if(nx >= 0 && ny >= 0 && nx < n && ny < m){
            if(type[k] == 1){
                if(light[nx][ny] == 1)
                   light[nx][ny] = 0;
                else
                   light[nx][ny] = 1;
            }
        }
    }
    valid = 1;
    for(i=0;i<x-2;i++){
        for(j=0;j<m;j++){
            if(light[i][j] == 0){
                valid = 0;
                break;
            }
        }
        if(valid == 0)break;
    }
    if(valid == 1)
        dfs(pos+1,now+1);
    press[pos] = 0;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            light[i][j] = oldlight[i][j];
        }
    }
    dfs(pos+1,now);
}
int main (){
    int i,j,k,now,tmp,next,l,nx,ny,ca=0;
    while(1){
        scanf("%d%d",&n,&m); 
        if(n == 0 && m == 0)break;
        for(i=0;i<3;i++){
            scanf("%s",MAP[i]);
        }
        k = 0;
        for(i=0;i<3;i++){
            for(j=0;j<3;j++){
                if(MAP[i][j] == '*')type[k] = 1;
                else type[k] = 0;  
                k++;
            }
        }
        memset(light,0,sizeof(light));
        step = 100000000;
        dfs(1,0);
        ca++;
        printf("Case #%d\n",ca);
        if(step == 100000000)printf("Impossible.\n");
        else{
            for(i=0;i<step;i++){
                if(i!=0)printf("-");
                printf("%d",ans[i]);
            }
            printf("\n");
        }
    }
    return 0;
}
/*
2 3
**.
.*.
*..
4 5
.*.
***
.*.
2 2
...
.**
...
4 3
*.*
...
..*
*/
