#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main (){
    int i,T,x,k,a,b,p,q;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&x,&k);
        a = (int)floor((float)x/(float)k);
        b = (int)ceil((float)x/(float)k);        
//        printf("%d %d\n",a,b);
        int flag = 1;
        for(p=0;a*p<=x;p++){
            q = (x - a*p)/b;
            if(x == a*p+b*q){
                printf("%d %d\n",p,q);
                flag = 0;
                break;
            }
        }
    }
    return 0;
}
