#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int alive[100];
int q[90000000];
int main (){
    int n,i,j,cnt,flag,now,m,dead,head,tail,k,first;
    while(scanf("%d%d",&n,&k) != EOF){
        if(n == 0 && k == 0)break;
        for(first = 1;first <= n;first++){
            for(i=1;i<=n;i++)alive[i] = 1;
            now = 1;cnt = 0;dead = 0;
            for(i=first,j=1;j<=n;j++,i++){
                if(i > n)i = 1;
                q[j] = i;
            }
            for(j=1;j<=n;j++)
                printf("%d ",q[j]);
            printf("\n");
            head = 1;
            tail = n+1;
            
            while(dead < n-1){
                cnt = 0;
                while(1){
                    cnt++;
                    if((cnt == k && dead == 0) || (cnt == k+1 && dead > 0)){
                        printf("dead: %d\n",q[head]);
                        alive[q[head]] = 0;                    
                        head++;
                        break;
                    }
                    q[tail] = q[head];
                    head++;
                    tail++;
                }
    
               // printf("now %d\n",now);
                dead++;
            }
            for(i=0;i<=n;i++){
                if(alive[i] == 1){
                    printf("now %d\n",i);
                   // break;
                }
            }
        }
    }
    return 0;
}
