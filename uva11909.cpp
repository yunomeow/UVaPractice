#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main (){
    int l,w,h;
    double degree,ans;
    while(scanf("%d%d%d%lf",&l,&w,&h,&degree) !=EOF){
        ans = (l*h-0.5*tan(2*acos(0)*degree/180)*l*l)*w;
        if(degree > 45)ans = 0;
        printf("%.3lf mL\n",ans);
    }
    return 0;
}
