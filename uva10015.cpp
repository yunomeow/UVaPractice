#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int prime[30000];
int use[50000],x=0;
int alive[4000];
int q[90000000];
int main (){
    int n,i,j,cnt,flag,now,m,dead,head,tail;
    prime[0] = 2;
    x++;
    for(i=3;i<40000;i+=2){
        if(use[i] == 0){
            prime[x] = i;
            x++;
            for(j=i+i;j<40000;j+=i){
                use[j] = 1;
            }
        }
    }
    while(scanf("%d",&n) != EOF){
        if(n == 0)break;
        for(i=1;i<=n;i++)alive[i] =1;
        now = 1;cnt = 0;dead = 0;
        for(i=1;i<=n;i++)q[i] = i;
        head = 1;
        tail = n+1;
        while(dead < n-1){
                cnt = 0;
            while(1){
                cnt++;
                if(cnt == prime[dead]){
                   // printf("%d\n",q[head]);
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
                printf("%d\n",i);
                break;
            }
        }
    }
    return 0;
}
