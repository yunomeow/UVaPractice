#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
struct XD{
    int s,e;
    int ns,ne;
}data[1000];
int dp[605][605],plane[605][605];
int solve(int s,int e){
    int MAX=0,tmp;
    if(dp[s][e] != -1)return dp[s][e];
    //printf("s : %d e : %d\n",s,e);
    if(e - s <= 1){
        return plane[s][e];
    }

    int i;
    for(i=s+1;i<e;i++){
        tmp = solve(s,i) + solve(i,e);
        //printf("s %d e %d tmp %d %d\n",s,e,tmp,plane[s][e]);
        if(tmp > MAX)MAX = tmp;
    }
    dp[s][e] = MAX + plane[s][e];
    return dp[s][e];
}
int event[1000];
int main (){
    int T,n,now,i,j,k;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        now = 0;
        for(i=0;i<n;i++){
            scanf("%d%d",&data[i].s,&data[i].e);
            event[now]= data[i].s;now++;
            event[now]= data[i].e;now++;
        }
       // printf("now %d\n",now);
        sort(event,event+now);
        k = 0;
        for(i=0;i<now;i++){
            if(i == 0 || event[i] != event[i-1]){
                for(j=0;j<n;j++){
                    if(data[j].s == event[i]){
                        data[j].ns = k;
                    }
                    if(data[j].e == event[i]){
                        data[j].ne = k;
                    }
                }
                k++;
            }
        }
     /*   printf("========\n");
        for(i=0;i<n;i++){
            printf("%d %d\n",data[i].ns,data[i].ne);
        }
        printf("========\n");*/
        memset(plane,0,sizeof(plane));
        for(i=0;i<n;i++){
            plane[data[i].ns][data[i].ne]++;
        }
       /* printf("k = %d\n",k);
        for(i=0;i<k;i++){
            for(j=0;j<k;j++)printf("%d ",plane[i][j]);
            printf("\n");
        }*/
        memset(dp,-1,sizeof(dp));
        printf("%d\n",solve(0,k-1));

        /*for(i=0;i<k;i++){
            for(j=0;j<k;j++)printf("%d ",dp[i][j]);
            printf("\n");
        }*/
    }
    return 0;
}
/*
2
4
1 10
2 5
3 7
6 9
3
10 12
10 15
13 17
*/
