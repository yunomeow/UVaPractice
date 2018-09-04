#include<stdio.h>
#include<stdlib.h>
struct Point{
    int x,y;
};
struct seg{
    Point a,b;
}data[10005];
int cross(Point a,Point b,Point c,Point d){
    int t1,t2,t3,t4,x1,y1,x2,y2;
    x1 = a.x - b.x;
    y1 = a.y - b.y;
    x2 = c.x - a.x;
    y2 = c.y - a.y;
    t1 = x1 * y2 - x2 * y1;
    x2 = d.x - a.x;
    y2 = d.y - a.y;
    t2 = x1 * y2 - x2 * y1;

    x1 = c.x - d.x;
    y1 = c.y - d.y;
    x2 = a.x - c.x;
    y2 = a.y - c.y;
    t3 = x1 * y2 - x2 * y1;
    x2 = b.x - c.x;
    y2 = b.y - c.y;
    t4 = x1 * y2 - x2 * y1;
    //printf("%d %d %d %d\n",t1,t2,t3,t4);
    if(t1*t2 < 0 && t3 * t4 < 0)return 1;
    return 0;
}
int main (){
    int T,n,i,cnt = 0,j,flag = 0;
    scanf("%d",&T);
    while(T--){
        if(flag == 1)printf("\n");
        flag = 1;
        scanf("%d",&n);
        for(i=0;i<n;i++){
            scanf("%d%d%d%d",&data[i].a.x,&data[i].a.y,&data[i].b.x,&data[i].b.y);
        }
        cnt = 0;
        for(i=0;i<n;i++){
            for(j=i+1;j<n;j++){
                if(cross(data[i].a,data[i].b,data[j].a,data[j].b) == 1)cnt++;
            }
        }
        printf("%d\n",cnt*2+n);
    }
    return 0;
}
