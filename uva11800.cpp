#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<iostream>
#include<algorithm>
using namespace std;
struct Point{
    int x,y;
}data[10],p[10];
int inner(Point a,Point b,Point c){
    int x1,x2,y1,y2;
    x1 = a.x - b.x;
    x2 = b.x - c.x;
    y1 = a.y - b.y;
    y2 = b.y - c.y;
    if(x1 * x2 + y1*y2 != 0)
        return 0;
    else
        return 1;
}
int slope(Point a,Point b,Point c,Point d){
    int up,down,up2,down2;
    up = a.y - b.y;
    down = a.x - b.x;
    up2 = c.y - d.y;
    down2 = c.x - d.x;
    if(up * down2 == up2 * down)return 1;
    else return 0;
}
int cross(Point a,Point b,Point c){
    int x1,x2,y1,y2;
    x1 = a.x - b.x;
    x2 = b.x - c.x;
    y1 = a.y - b.y;
    y2 = b.y - c.y;
    if(x1 * y2 - x2 * y1 > 0)return 1;
    if(x1 * y2 - x2 * y1 == 0)return 0;
    return -1;
}
bool cmp(Point a,Point b){
    if(a.x == b.x)return a.y < b.y;
    return a.x < b.x;
}
int main (){
    int T,flag,flag2,ca=0,i,m,mm,tmp,t1;
    scanf("%d",&T);
    while(T--){
        for(i=0;i<4;i++)
            scanf("%d%d",&p[i].x,&p[i].y);
        sort(p,p+4,cmp);
        m = 0;
        for(i=0;i<4;i++){
            if(m < 2){
                data[m].x = p[i].x;
                data[m].y = p[i].y;
                m++;
                continue;
            }else{
                while(m >= 2 && cross(data[m-2],data[m-1],p[i]) < 0){
                    m--;
                }
                data[m].x = p[i].x;
                data[m].y = p[i].y;
                m++;
            }
        }
        mm = m;
        for(i=2;i>=0;i--){
            if(m - mm < 1){
                data[m].x = p[i].x;
                data[m].y = p[i].y;
                m++;
                continue;
            }else{
                while(m - mm >= 1 && cross(data[m-2],data[m-1],p[i]) < 0){
                    m--;
                }
                data[m].x = p[i].x;
                data[m].y = p[i].y;
                m++;
            }
        }
        ca ++;
        printf("Case %d: ",ca);
        if(m <= 4){printf("Ordinary Quadrilateral\n");continue;}
        flag = 1;
        tmp = (data[0].x - data[3].x)*(data[0].x - data[3].x) + (data[0].y - data[3].y)*(data[0].y - data[3].y);
        for(i=0;i<3;i++){
            if(tmp !=  (data[i].x - data[i+1].x)*(data[i].x - data[i+1].x) + (data[i].y - data[i+1].y)*(data[i].y - data[i+1].y)){
                flag = 0;
                break;
            }
        }
        flag2 = 1;
        for(i=0;i<4;i++){
            if(inner(data[i],data[(i+1)%4],data[(i+2)%4]) == 0){
                flag2 = 0;
                break;
            }
        }
        if(flag == 1 && flag2 == 1){
            printf("Square\n");continue;
        }
        if(flag2 == 1){
            printf("Rectangle\n");continue;
        }
        if(flag == 1){
            printf("Rhombus\n");continue;
        }                 
        if((data[0].x+data[2].x) == (data[1].x+data[3].x) && (data[0].y + data[2].y) == data[1].y + data[3].y){
            printf("Parallelogram\n");continue;
        }
       if(slope(data[0],data[1],data[2],data[3]) == 1 || slope(data[0],data[3],data[1],data[2]) == 1){
            printf("Trapezium\n");continue;
        }
        printf("Ordinary Quadrilateral\n");
    }
    return 0;
} 
