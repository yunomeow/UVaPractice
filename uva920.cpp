#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;
struct Point{
    double x,y;
}data[105];
bool cmp(Point a,Point b){
    if(a.x == b.x)return a.y < b.y;
    return a.x < b.x;
}
int main (){
    int T,n,first,second,i,j,k;
    double len,dis,fh,sh,a,b,x,y;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        len = 0;
        for(i=0;i<n;i++){
            scanf("%lf%lf",&data[i].x,&data[i].y);
        }
        sort(data,data+n,cmp);
        i = 0;
        while(i < n-1){
            fh = -1;
            for(k=i;k<n;k++){
                if(data[k].y > fh){
                    fh = data[k].y;
                    first = k;
                }
            }
            sh = -1;
            for(k=first+1;k<n;k++){
                if(data[k].y > sh){
                    sh = data[k].y;
                    second = k;
                }  
            }
            dis = sqrt((data[first].x - data[second].x)*(data[first].x - data[second].x)+
                (data[first].y - data[second].y)*(data[first].y - data[second].y));
            if(second - first == 1){
                len += dis;
            }else{
                a = (data[first].y - data[first+1].y)/(data[first].x - data[first+1].x);
                b = data[first].y - a * data[first].x ;

                x = (data[second].y - b)/a;
                y = data[second].y;
             //   printf("%lf %lf %lf %lf\n",a,b,x,y) ;
                len += sqrt((data[first].x - x)*(data[first].x - x) + (data[first].y - y)*(data[first].y - y));
            }
            i = second;
            //printf("len %lf first %d second %d\n",len,first,second);
            //system("pause");
        }
        printf("%.2lf\n",len);
    }
    return 0;
}
