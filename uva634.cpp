#include<stdio.h>
#include<stdlib.h>
struct Point{
    double x,y;
}data[10000],p1,p2;
int cross(Point a,Point b,Point c,Point d){
    double t1,t2,t3,t4,x1,y1,x2,y2;
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
    if(t1*t2 < 0 && t3 * t4 < 0)return 1;
    return 0;
}
int main (){
    int n;
    int x,y;
    int cnt = 0,i;
    while(1){
        scanf("%d",&n);
        if(n == 0)break;
        for(i=0;i<n;i++){
            scanf("%lf%lf",&data[i].x,&data[i].y);
        }
        data[n].x = data[0].x;
        data[n].y = data[0].y;
        scanf("%lf%lf",&p1.x,&p1.y);
        p2.x = 1e10;
        p2.y = p1.y+1;
        cnt = 0;
        for(i=0;i<n;i++){
            if(cross(p1,p2,data[i],data[i+1]) == 1){
                //printf("(%.0lf %.0lf)\n",data[i].x,data[i].y);
                cnt++;
            }
        }
        //printf("cnt %d\n",cnt);
        if(cnt % 2 == 0)printf("F\n");
        else printf("T\n");
    }
    return 0;
}
