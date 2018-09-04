#include<stdio.h>
#include<stdlib.h>
#include<math.h>
double p,q,r,s,t,u;
double fabs(double a){
    if(a < 0)return -1*a;
    else return a;
}
int main (){
    double x,left,right,mid,val,tmp1,tmp2;
    int flag;
    while(scanf("%lf%lf%lf%lf%lf%lf",&p,&q,&r,&s,&t,&u) != EOF){
        left = 1;right = 0;flag = 1;
        tmp1 = p*exp(-1) + q*sin(1) + r*cos(1) + s*tan(1) + t * 1 * 1 + u;
        tmp2 = p*exp(0) + q*sin(0) + r*cos(0) + s*tan(0) + u;
        if((tmp1 > 0 && tmp2 > 0 )||(tmp1 < 0 && tmp2 < 0))flag = 0;
        if(flag == 1){
            while(fabs(right - left) > 1e-8){
                mid = (left + right)/2;
                val = p*exp(-1*mid) + q*sin(mid) + r*cos(mid) + s*tan(mid) + t * mid * mid + u;
                if(val < 0)left = mid;
                else right = mid;
            }
        }
        if(flag == 0)
            printf("No solution\n");
        else
            printf("%.4lf\n",right);
    }
    return 0;
}
