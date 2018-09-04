#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
char s[10000];
struct skyly{
    int st;
    int ed;
    int fun;
}data[10005];
bool cmp(skyly a,skyly b){
    //if(a.st == b.st)
        return a.st < b.st;
//    return a.st < b.st;
}
int dp[104][104];
int main (){
    int i,n,j,a,b,c,d,e,MAX,ca = 0,k;
    while(1){
        scanf("%d%*c",&n);
        
        if(n == 0)break;
        for(i=0;i<n;i++){
            gets(s);
            s[2] = s[5] = s[8] = ' ';
            sscanf(s,"%d%d%d%d%d",&a,&b,&c,&d,&e);
            data[i].st = a*60+b;
            data[i].ed = c*60+d;
            if(data[i].st < 360)data[i].st += 1440;
            if(data[i].ed < 360)data[i].ed += 1440;            
            data[i].fun = e;
        }
        sort(data,data+n,cmp);
        MAX = 0;
        memset(dp,-1,sizeof(dp));
        for(i=0;i<n;i++){
            dp[i][i] = data[i].fun;
            for(j=i;j<n;j++){
                if(dp[i][j] == -1)continue;
                for(k = j+1;k < n; k++){
                    if( data[k].st >= data[j].ed || i == j){
                        if(dp[i][j] + data[k].fun > dp[i][k])
                            dp[i][k] = dp[i][j] + data[k].fun;
                    }
                }
            }
        }
        for(i=0;i<n;i++){
            for(j=0;j<n;j++)
                if(dp[i][j] >  MAX)MAX = dp[i][j];
         //       printf("%d ",dp[i][j]);
         //   printf("\n");
        }
        ca++;
        printf("Case %d: %d\n",ca,MAX);
    }
    return 0;
}
//21:15-23:30
