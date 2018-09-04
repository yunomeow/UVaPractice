#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<iostream>
#include<algorithm>
using namespace std;
struct Edge{
    int a,b;
    double c;
}data[1000000];
int ans[1000][2],top;
struct Point{
    int x,y;
}input[1000];
bool cmp(Edge a,Edge b){
    return a.c < b.c;
}
double dis(Point a,Point b){
    return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}
int par[1000];
int find_par(int pos){
    if(par[pos] == pos)return pos;
    par[pos] = find_par(par[pos]);
    return par[pos];
}
void Union(int x,int y){
    int sx = find_par(x);
    int sy = find_par(y);
    par[sx] = sy;
}
int main (){
    int T,n,m;
    int a,b,cnt=0;
    int flag = 0;
    int i,j;
    scanf("%d",&T);
    while(T--){
        if(flag == 1)printf("\n");
        flag = 1;
        scanf("%d",&n);
        for(i=0;i<n;i++){
            scanf("%d%d",&input[i].x,&input[i].y);
        }
        cnt = 0;
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                if(i == j) continue;
                data[cnt].a = i;
                data[cnt].b = j;
                data[cnt].c = dis(input[i],input[j]);
                cnt++;
            }
        }
        sort(data,data+cnt,cmp);
        for(i=0;i<n;i++){
            par[i] = i;
        }
        scanf("%d",&m);
        for(i=0;i<m;i++){
            scanf("%d%d",&a,&b);
            a--;b--;
            Union(a,b);
        }

        top = 0;
        for(i=0;i<cnt;i++){
            if(find_par(data[i].a) != find_par(data[i].b)){
                Union(data[i].a,data[i].b);
                ans[top][0] = data[i].a;
                ans[top][1] = data[i].b;
                top++;
            }
        }
        if(top == 0)printf("No new highways need\n");
        else{
            for(i=0;i<top;i++){
                printf("%d %d\n",ans[i][0]+1,ans[i][1]+1);
            }
        }
    }
    return 0;
}
/*
1

9
1 5
0 0
3 2
4 5
5 1
0 4
5 2
1 2
5 3
3
1 3
9 7
1 2
*/
