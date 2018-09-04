#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int hole[505][3];
int MAP[505][505];
int red[505][2],green[505][2],goldx,goldy;
int edge[505][505];
int vis[505][505];
int step[505][505];
int q[100000000][3];
int q2[100000000];
int dir[4][2] = {1,0,0,1,-1,0,0,-1};
int matrix[505][505];
int par[500];
int vis2[500];
int main (){
    int m,n,k,t,T,i,head,tail,j;
    int x,y,d;
    int nowx,nowy,nowstep,nextx,nexty,cap,flag,flow,now;
    int total;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d%d",&n,&m,&k,&t);
        for(i=0;i<k;i++){
            scanf("%d%d",&red[i][0],&red[i][1]);
            red[i][0]--;red[i][1]--;
        }
        for(i=0;i<k;i++){
            scanf("%d%d",&green[i][0],&green[i][1]);
            green[i][0]--;green[i][1]--;
        }
        scanf("%d%d",&goldx,&goldy);
        for(i=0;i<t;i++){
            scanf("%d%d%d",&hole[i][0],&hole[i][1],&hole[i][2]);
            hole[i][0]--;hole[i][1]--;
        }
        for(i=0;i<n;i++)
            for(j=0;j<m;j++)
                scanf("%d",&MAP[i][j]);
        memset(edge,0,sizeof(edge));
        for(i=0;i<n;i++)
            for(j=0;j<k;j++)
                edge[i][j] = -1;
        //build red
        for(i=0;i<k;i++){
            for(j=0;j<n;j++)
                for(d=0;d<m;d++)
                    step[j][d] = 2100000000;
            head = 0;
            tail = 1;
            q[0][0] = red[i][0];
            q[0][1] = red[i][1];
            q[0][2] = 0;
            step[red[i][0]][red[i][1]] = 0;
            //bfs
            while(head != tail){
                nowx = q[head][0];
                nowy = q[head][1];
                nowstep = q[head][2];
                head++;
            //    printf("head %d tail %d nowx %d nowy %d\n",head,tail,nowx,nowy);
                for(j=0;j<4;j++){
                    nextx = nowx + dir[j][0];
                    nexty = nowy + dir[j][1];
                    if(nextx >= 0 && nexty >= 0 &&nextx < n && nexty < m){
                        if(nowstep % 2 == 1){
                            if(step[nextx][nexty] > nowstep){
                                if(MAP[nextx][nexty] > MAP[nowx][nowy])
                                    step[nextx][nexty] = nowstep + 1;
                                else
                                    step[nextx][nexty] = nowstep;
                                q[tail][0] = nextx;
                                q[tail][1] = nexty;
                                q[tail][2] = step[nextx][nexty];
                                tail++;
                            }
                        }else{
                            if(step[nextx][nexty] > nowstep){
                                if(MAP[nextx][nexty] < MAP[nowx][nowy]){
                                    if(step[nextx][nexty] == nowstep+1)continue;                                    
                                    step[nextx][nexty] = nowstep + 1;
                                }
                                else
                                    step[nextx][nexty] = nowstep;
                                q[tail][0] = nextx;
                                q[tail][1] = nexty;
                                q[tail][2] = step[nextx][nexty];
                                tail++;
                            }
                        }
                    }
                }
            }
            for(j=0;j<t;j++){
                edge[j][i+t] = step[hole[j][0]][hole[j][1]];
            }
            /*
            for(j=0;j<n;j++){
                for(d=0;d<m;d++){
                    printf("%d ",step[j][d]);
                }
                printf("\n");
            }*/
        }
        //build green
        for(i=0;i<k;i++){
            for(j=0;j<n;j++)
                for(d=0;d<m;d++)
                    step[j][d] = 2100000000;
            head = 0;
            tail = 1;
            q[0][0] = green[i][0];
            q[0][1] = green[i][1];
            q[0][2] = 0;
            step[red[i][0]][red[i][1]] = 0;
            //bfs
            while(head != tail){
                nowx = q[head][0];
                nowy = q[head][1];
                nowstep = q[head][2];
                head++;
            //    printf("head %d tail %d nowx %d nowy %d\n",head,tail,nowx,nowy);
                for(j=0;j<4;j++){
                    nextx = nowx + dir[j][0];
                    nexty = nowy + dir[j][1];
                    if(nextx >= 0 && nexty >= 0 &&nextx < n && nexty < m){
                        if(nowstep % 2 == 0){
                            if(step[nextx][nexty] > nowstep){
                                if(MAP[nextx][nexty] > MAP[nowx][nowy]){
                                    if(step[nextx][nexty] == nowstep+1)continue;
                                    step[nextx][nexty] = nowstep + 1;
                                }
                                else
                                    step[nextx][nexty] = nowstep;
                                q[tail][0] = nextx;
                                q[tail][1] = nexty;
                                q[tail][2] = step[nextx][nexty];
                                tail++;
                            }
                        }else{
                            if(step[nextx][nexty] > nowstep){
                                if(MAP[nextx][nexty] < MAP[nowx][nowy])
                                    step[nextx][nexty] = nowstep + 1;
                                else
                                    step[nextx][nexty] = nowstep;
                                q[tail][0] = nextx;
                                q[tail][1] = nexty;
                                q[tail][2] = step[nextx][nexty];
                                tail++;
                            }
                        }
                    }
                }
            }
            for(j=0;j<t;j++){
                edge[j][i+t+k] = step[hole[j][0]][hole[j][1]];
            }
            /*
            for(j=0;j<n;j++){
                for(d=0;d<m;d++){
                    printf("%d ",step[j][d]);
                }
                printf("\n");
            }*/
        }
        memset(matrix,0,sizeof(matrix));
        cap = 0;
        flow = 0;
        // source 2*k+1+t sink 2*k+1+t+1
        for(i=0;i<t;i++){
            matrix[i][2*k+t+2] = hole[i][2];
        }
        for(i=0;i<2*k;i++){
            matrix[2*k+t+1][i+t] = 1;
        }
        total = 2*k+3+t;
        while(1){
            for(i=0;i<t;i++){
                for(j=0;j<2*k;j++){
                    if(edge[i][j+t] == cap)
                        matrix[j+t][i] += 1;
                }
            }
            /*
            for(i=0;i<total;i++){
                for(j=0;j<total;j++)
                    printf("%d ",matrix[i][j]);
                printf("\n");
            }*/
            //flow
            flag = 1;
            while(flag == 1){
                flag = 0;
                head = 0;
                tail = 1;
                memset(par,0,sizeof(par));
                memset(vis2,0,sizeof(vis2));
                q2[0] = 2*k+1+t;
                vis2[2*k+1+t] = 1;
                while(head != tail){
                    now = q2[head];
                    head++;
                    //printf("now %d\n",now);
                    for(i=0;i<total;i++){
                        if(matrix[now][i] > 0 && vis2[i] == 0){
                            q2[tail] = i;
                            vis2[i] = 1;
                            tail++;
                            par[i] = now;
                            if(i == 2*k+2+t){flag = 1;break;}
                        }
                    }
                    if(flag == 1)break;
                }
                if(flag == 0)break;
                now = 2*k+2+t;
                while(now != 2*k+1+t){
                    matrix[par[now]][now] --;
                    matrix[now][par[now]] ++;                    
                    now = par[now];
                }
                flow += 1;
            }
            
            //printf("cap %d flow %d\n",cap,flow);
            if(flow >= 2*k - cap)break;
            cap++;
        }
        printf("%d\n",cap);
    }
    return 0;
}
/*
3
4 6 2 5
1 1 1 5 4 1 4 5 3 3
1 2 1 2 6 1 3 2 1 3 6 1 4 3 1
3 2 6 1 3 5
2 1 7 4 4 6
2 3 1 4 3 4
4 3 4 3 2 3
*/
