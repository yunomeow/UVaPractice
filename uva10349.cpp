#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int matrix[806][806];
char MAP[804][804];
int dir[4][2] ={1,0,0,1,-1,0,0,-1};
int vis[806],ans,par[806],flag,h,w;
int q[800],head,tail;
void bfs(){
    int i,now;
    q[0] = h*w;
    head = 0;
    tail = 1;
    vis[h*w] = 1;
    while(head != tail){
        now = q[head];
        head++;
        for(i=0;i<h*w+2;i++){
            if(matrix[now][i] == 1 && vis[i] == 0){
                par[i] = now;
                q[tail] = i;
                vis[i] = 1;
                tail++;
                if(i == h*w+1)flag = 1;
            }
        }
    }
}
int main (){
    int T,i,j,k,nx,ny,a,b,now,cnt;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%*c",&h,&w);
        for(i=0;i<h;i++){
            scanf("%s",MAP[i]);
        }
        cnt = 0;
        memset(matrix,0,sizeof(matrix));
        for(i=0;i<h;i++)
            for(j=0;j<w;j++)
                if(MAP[i][j] == '*')
                    cnt++;
        for(i=0;i<h;i++){
            for(j=0;j<w;j++){
                if(MAP[i][j] == '*'){
                    b = i*w+j;                    
                    if((i % 2 == 0 &&j % 2 == 0)||(i%2 == 1 && j % 2 == 1)){
                        for(k=0;k<4;k++){
                            nx = i + dir[k][0];
                            ny = j + dir[k][1];
                            if(nx >= 0 && nx < h && ny >= 0 && ny < w && MAP[nx][ny] == '*'){
                                a = nx * w + ny;
                               // printf("a: %d b %d\n",a,b);
                                matrix[a][b] = 1;
                                matrix[b][h*w+1] = 1;
                            }
                        }
                    }else{
                        matrix[h*w][b] = 1;
                    }
                }
            }
        }
        flag = 1;
        ans = 0;
        while(flag == 1){
            flag = 0;
            memset(vis,0,sizeof(vis));
            bfs();
            if(flag == 1){
                now = h*w+1;
                while(now != h*w){
                    matrix[now][par[now]] = 1;
                    matrix[par[now]][now] = 0;
                    now = par[now];
                }
                ans++;
            }
        }
      //  printf("cnt %d ans %d\n",cnt,ans);
        printf("%d\n",ans+ cnt - 2*ans);
    }
    return 0;
}
