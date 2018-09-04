#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<iostream>
using namespace std;
struct Fig{
    char type;
    double x1,y1,x2,y2,x3,y3,r;
}data[100];
double areasd(double x1,double y1,double x2,double y2,double x3,double y3){
    double a,b,c,s;
    a = sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
    b = sqrt((x1-x3)*(x1-x3)+(y1-y3)*(y1-y3));
    c = sqrt((x2-x3)*(x2-x3)+(y2-y3)*(y2-y3));
    s = (a+b+c)/2;
    return sqrt(s * (s-a) * (s-b) * (s-c));
}

double fabss(double x){
    if(x < 0)return -1*x;
    else return x;
}
double aread(double x0,double y0,double x1,double y1,double x2,double y2)
{
  return fabs((x1-x0)*(y2-y0)-(x2-x0)*(y1-y0));
}
double area( double xa, double ya, double xb, double yb, double xc, double yc )
{
    double temp = (xa - xc) * (yb - ya) - (xa - xb) * (yc - ya);
    if ( temp < 0 )
        temp *= -1;
    temp /= 2;
 
    return temp;
}

int main (){
    char shape;
    double x,y;
    int n = 0,i,flag,ca=0;
    char input [5];
    int index = 0;

    while ( scanf ("%s", input) && strcmp (input, "*") != 0 ) {
        if ( strcmp (input, "r") == 0 ) {
            data [index].type = 'r';
            cin >> data [index].x1 >> data [index].y1 >> data [index].x2 >> data[index].y2;
        }
        else if ( strcmp (input, "c") == 0 ) {
            data [index].type = 'c';
            cin >>  data [index].x1 >> data [index].y1 >> data [index].r;
        }
        else {
            data [index].type = 't';
            cin >> data [index].x1 >> data [index].y1 >> data [index].x2;
            cin >> data [index].y2 >> data [index].x3 >> data [index].y3;
        }
        index++;
    }
    n = index;
    while ( cin >> x >> y && x != 9999.9 && y != 9999.9 ) {
        flag = 0;
        ca++;
        for(i=0;i<n;i++){
            switch(data[i].type){
                case 'r': 
                    if(x <= data[i].x2 && x >= data[i].x1 && y <= data[i].y1 && y >= data[i].y2){
                        printf("Point %d is contained in figure %d\n",ca,i+1);
                        flag = 1;
                    }
                    break;
                case 'c': 
                    if(sqrt((x-data[i].x1)*(x-data[i].x1)+(y-data[i].y1)*(y-data[i].y1)) <= data[i].r){
                        printf("Point %d is contained in figure %d\n",ca,i+1);
                        flag = 1;
                    }
                    break;
                case 't': 
                   // printf("%lf %lf\n",area(data[i].x3,data[i].y3,data[i].x1,data[i].y1,data[i].x2,data[i].y2) ,(area(x,y,data[i].x1,data[i].y1,data[i].x2,data[i].y2)+area(x,y,data[i].x1,data[i].y1,data[i].x3,data[i].y3)+area(x,y,data[i].x3,data[i].y3,data[i].x2,data[i].y2)));
                  
                  /*if(area(x,y,data[i].x1,data[i].y1,data[i].x2,data[i].y2)==0
                  ||area(x,y,data[i].x1,data[i].y1,data[i].x3,data[i].y3)==0
                  ||area(x,y,data[i].x3,data[i].y3,data[i].x2,data[i].y2)==0)break;
                    if(fabs(
                    area(data[i].x3,data[i].y3,data[i].x1,data[i].y1,data[i].x2,data[i].y2)
                    -(area(x,y,data[i].x1,data[i].y1,data[i].x2,data[i].y2)
                    +area(x,y,data[i].x1,data[i].y1,data[i].x3,data[i].y3)
                    +area(x,y,data[i].x3,data[i].y3,data[i].x2,data[i].y2))
                    ) < 1e-6){
                        printf("Point %d is contained in figure %d\n",ca,i+1);
                        flag = 1;
                    }*/
        double totalArea = area(data[i].x3,data[i].y3,data[i].x1,data[i].y1,data[i].x2,data[i].y2);

        double abd = area(data[i].x1,data[i].y1,data[i].x2,data[i].y2,x,y);

        double acd = area(data[i].x1,data[i].y1,x,y,data[i].x3,data[i].y3);

        double bcd = area(x,y,data[i].x2,data[i].y2,data[i].x3,data[i].y3);
//printf("%lf %lf %lf %lf %lf\n",totalArea , (abd + acd + bcd),abd,acd,bcd);
        if ( fabs (totalArea - (abd + acd + bcd)) < 1e-6 && abd != 0 && acd != 0 && bcd != 0 ) {
                                printf("Point %d is contained in figure %d\n",ca,i+1);
                        flag = 1;
        }                   
                    break;
            }
        }
        if(flag == 0)
            printf("Point %d is not contained in any figure\n",ca);
    }
    return 0;
}
