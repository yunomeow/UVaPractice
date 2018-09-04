#include<stdio.h>
#include<stdlib.h>
int prime[110000];
int use[110000],p[100000];
int main(){
    int x,i,n,j,y,tn;
    double ans;
    x = 1;
    prime[0] = 2;
    for(i=3;i<110000;i+=2){
        if(use[i] == 0){
            prime[x] = i;
            x++;
            for(j=3;i*j < 110000;j+=2){
                use[i*j] = 1;
            }
        }
    }
    while(1){
        scanf("%d",&n);
        tn = n;
        if(n == 0)break;
        if(n == 1)printf("1\n");
        else{
            y = 0;
            for(i=0;i<x;i++){
                if(prime[i] > tn) break;
                if(tn % prime[i] == 0){
                    p[y] = prime[i];
                    y++;
                    while(tn % prime[i] == 0){
                        tn /= prime[i];
                    } 
                }
            }
            if(tn != 1){ 
                p[y] = tn;
                y++;
            }
            ans = n;
            for(i=0;i<y;i++){
                ans *= (1-(1.0/(double)p[i]));
               // printf("%d %lf\n",p[i],ans);
            }
            printf("%.0lf\n",ans);
        }
    }
    return 0;
}
