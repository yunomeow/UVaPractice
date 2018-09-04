#include<stdio.h>
#include<stdlib.h>
int main (){
    int i,MAX,MIN,T,n,tmp,pos,dis;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        MAX = 0;MIN = 100;
        for(i=0;i<n;i++){
            scanf("%d",&tmp);
            if(tmp < MIN)MIN = tmp;
            if(tmp > MAX)MAX = tmp;
        }
        dis = 100000;
        for(i=0;i<100;i++){
            if(i < MIN && i < MAX){
                if(MAX - i < dis)
                    dis = MAX - i;
            }else{
                if(i <= MAX && i >= MIN){
                    if(MAX - MIN < dis)
                        dis = MAX - MIN;
                }else{
                    if(i - MIN < dis)
                        dis= i - MIN;
                }
            }
        }
        printf("%d\n",dis*2);
    }
    return 0;
}
