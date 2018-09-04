#include<stdio.h>
#include<stdlib.h>
int day[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int leap(int y){
    if(y % 4 == 0 && y % 100 != 0)return 1;
    if(y % 400 == 0)return 1;
    return 0;
}
void nextDay(int &D,int &M,int &Y){
    if(leap(Y) == 1 && D == 28 && M == 2){
        M = 2;
        D = 29;
        return;
    }
    if(D < day[M]){D++;return;}
    D = 1;
    M++;
    if(M == 13){
        Y++;
        M = 1;
    }
}
int main (){
    int n,d,m,y;
    int now;
    while(1){
        scanf("%d%d%d%d",&n,&d,&m,&y);
        if(n == 0 && d == 0 && m == 0 && y == 0)break;
        while(n >= 365){
            if((m == 2 && d == 29)||m >= 3){
                if(leap(y+1) == 1)
                    now = 366;
                else now = 365;
            }else{
                if(leap(y) == 1)now = 366;
                else now = 365;
            }
            n -= now;
            y++;
        }
        while(n > 0){
            nextDay(d,m,y);
            n--;
        }
        printf("%d %d %d\n",d,m,y);
    }
    return 0;
}
