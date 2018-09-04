#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int cnt[18003];
int main (){
    int x,a,b,c;
    int i,flag,MIN;
    while(1){
        scanf("%d%d%d",&a,&b,&c);
        if(a == 0 && b == 0 && c == 0)break;
        if(a > b)MIN = b;
        else MIN = a;
        x = 2;
        memset(cnt,0,sizeof(cnt));

        for(i=0;i<18002;i++){
            if(i % (2*a) < a-5){
                cnt[i]++;
            }
        }
        for(i=0;i<18002;i++){
            if(i % (2*b) < b-5){
                cnt[i]++;
            }
        }
        if(c != 0){
            for(i=0;i<18002;i++){
                if(i % (2*c) < c-5){
                    cnt[i]++;
                }
            }
            if(c < MIN)MIN = c;
            x++;
            while(1){
                scanf("%d",&c);
                if(c == 0)break;
                if(c < MIN) MIN = c;
                for(i=0;i<18002;i++){
                    if(i % (2*c) < c-5){
                        cnt[i]++;
                    }
                }
                x++;
            }
        }
        flag = 0;
        for(i=2*MIN;i<18001;i++){
            if(cnt[i] == x){
                flag = 1;
                printf("%02d:%02d:%02d\n",i/3600,(i%3600)/60,i%60);
                break;
            }
        }
        if(flag == 0)printf("Signals fail to synchronise in 5 hours\n");
    }
}
