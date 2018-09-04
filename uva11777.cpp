#include<stdio.h>
#include<stdlib.h>
double grade[10];
double MAXval(double a,double b,double c){
    if(a >= b && a >= c)return a;
    if(b >= a && b >= c)return b;
    if(c >= a && c >= b)return c;    
}
int main (){
    int T,i,ca = 0;
    double sum;
    scanf("%d",&T);
    while(T--){
        for(i=0;i<7;i++)
            scanf("%lf",&grade[i]);
        sum = grade[0] + grade[1] + grade[2] + grade[3] + MAXval(grade[4]+grade[5],grade[4]+grade[6],grade[6]+grade[5])/2;
        ca++;
//        printf("sum %lf",sum);
        printf("Case %d: ",ca);
        if(sum >= 90)printf("A");
        else if(sum >= 80)printf("B");
        else if(sum >= 70)printf("C");
        else if(sum >= 60)printf("D");
        else printf("F");
        printf("\n");
    }
    return 0;
}
