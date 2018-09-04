#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<iostream>
#include<queue>
#include<string.h>
using namespace std;
int matrix[150][150];
int dis[10005];
queue<int> q;
int inq[10005];
int hotel[10005];
struct edge{
    int a,c;
}tmp;
vector<edge> v[10005];
int main (){
    int n,m,h;
    int i,j,k;
    int a,b,c;
    int now;
    while(1){
        scanf("%d",&n);
        if(n == 0)break;
        scanf("%d",&h);
        for(i=0;i<h;i++){
            scanf("%d",&hotel[i]);
        }
        for(i=1;i<=n;i++)v[i].clear();
        scanf("%d",&m);
        for(i=0;i<m;i++){
            scanf("%d%d%d",&a,&b,&c);
            tmp.a = b;
            tmp.c = c;
            v[a].push_back(tmp);
            tmp.a = a;
            tmp.c = c;
            v[b].push_back(tmp);
        }
        hotel[h] = 1;
        hotel[h+1] = n;
        h+=2;
        for(i=0;i<h;i++){
            for(j=0;j<h;j++)
                matrix[i][j] = 100000000;
        }
        for(i=0;i<h;i++){
            for(j=0;j<=n;j++)dis[j] = 100000000;
            while(!q.empty())q.pop();
            memset(inq,0,sizeof(inq));
            q.push(hotel[i]);
            dis[hotel[i]] = 0;
            inq[hotel[i]] = 1;
            while(!q.empty()){
                now = q.front();
                inq[now] = 0;
                q.pop();
                for(j=0;j<v[now].size();j++){
                    if(dis[now] + v[now][j].c < dis[v[now][j].a]){
                        dis[v[now][j].a] = dis[now] + v[now][j].c;
                        if(inq[v[now][j].a] == 0){
                            q.push(v[now][j].a);
                            inq[v[now][j].a] = 1;
                        }
                    }
                }
            }
            for(j=0;j<h;j++){
                if(dis[hotel[j]] <= 600){
                    matrix[i][j] = 1;
                }
            }
        }
        for(i=0;i<h;i++)matrix[i][i] = 0;
       /* for(i=0;i<h;i++){
            for(j=0;j<h;j++){
                printf("%9d ",matrix[i][j]);
            }
            printf("\n");
        }*/
        for(k=0;k<h;k++){
            for(i=0;i<h;i++){
                for(j=0;j<h;j++){
                    if(matrix[i][k] + matrix[k][j] < matrix[i][j]){
                        matrix[i][j] = matrix[i][k] + matrix[k][j];
                    }
                }
            }
        }
        /*for(i=0;i<h;i++){
            for(j=0;j<h;j++){
                printf("%9d ",matrix[i][j]);
            }
            printf("\n");
        }*/
        if(matrix[h-2][h-1] < 100000000)printf("%d\n",matrix[h-2][h-1]-1);
        else printf("-1\n");
    }
    return 0;
}
/*
6
3 2 5 3
8
1 2 400
3 2 80
3 4 301
4 5 290
5 6 139
1 3 375
2 5 462
4 6 300
3
0
2
1 2 371
2 3 230
0
*/
