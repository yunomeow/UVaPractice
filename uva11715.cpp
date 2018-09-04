#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main (){
    double u,v,a,s,t;
    int n,ca=0;
    while(1){
        scanf("%d",&n);
        if(n == 0)break;
        ca++;
        printf("Case %d: ",ca);
        if(n == 1){
            scanf("%lf%lf%lf",&u,&v,&t);
            a = (v-u)/t;
            s = (v*v - u*u)/ (2*a);
            printf("%.3lf %.3lf\n",s,a);
        }else if(n == 2){
            scanf("%lf%lf%lf",&u,&v,&a);
            t = (v-u)/a;
            s = (v*v - u*u) / (2*a);
            printf("%.3lf %.3lf\n",s,t);
        }else if(n == 3){
            scanf("%lf%lf%lf",&u,&a,&s);
            v = sqrt(u*u+2*a*s);
            t = (v-u)/a;
            printf("%.3lf %.3lf\n",v,t);
        }else{
            scanf("%lf%lf%lf",&v,&a,&s);
            u = sqrt(v*v -  2*a*s);
            t = (v-u)/a;
            printf("%.3lf %.3lf\n",u,t);
        }
    }
    return 0;
}
