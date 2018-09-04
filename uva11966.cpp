#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
struct Point{
    double x,y;
}data[1005];
int par[1005];
int use[1005];
int find_par(int pos){
    if(pos == par[pos])return pos;
    par[pos] = find_par(par[pos]);
    return par[pos];
}
void Union(int x,int y){
    int sx = find_par(x);
    int sy = find_par(y);
    par[sx] = sy;
}
inline double Dist(Point &a,Point &b){
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
int main (){
    double d;
    int n,T,i,j;
    int ans,tmp,ca=0;
    scanf("%d",&T);
    while(T--){
        scanf("%d%lf",&n,&d);
        for(i=1;i<=n;i++){
            scanf("%lf%lf",&data[i].x,&data[i].y);
        }
        for(i=1;i<=n;i++){
            par[i] = i;
        }
        memset(use,0,sizeof(use));
        for(i=1;i<=n;i++){
            for(j=i+1;j<=n;j++){
                if(Dist(data[i],data[j]) <= d){
                    Union(i,j);
                }
            }
        }
        ans = 0;
        for(i=1;i<=n;i++){
            tmp = find_par(i);
            if(use[tmp] == 0){
                ans ++;
                use[tmp] = 1;
            }
        }
        ca++;
        printf("Case %d: %d\n",ca,ans);
    }
    return 0;
}
