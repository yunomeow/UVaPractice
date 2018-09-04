#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;
struct XD{
    int x,y;
}data[1000];
char in[100];
double num[1000];
inline double slope(int a,int b){
    double x = data[a].x - data[b].x;
    double y = data[a].y - data[b].y;
    if(y == 0)return 1e10;
    return x/y;
}
int main (){
    int i,j,k,n,T;
    int sp=0;
    int ans,tmp;
    scanf("%d%*c%*c",&T);
    while(T--){
        if(sp == 1)printf("\n");
        sp = 1;
        n = 0;
        while(gets(in) && strcmp(in,"") != 0){
            sscanf(in,"%d%d",&data[n].x,&data[n].y);
            n++;
        }
        ans = 0;
        for(i=0;i<n;i++){
            k = 0;
            for(j=0;j<n;j++){
                if(i == j)continue;
                num[k] = slope(i,j);
                k++;
            }
            sort(num,num+k);
            tmp = 1;
            for(j=1;j<k;j++){
                if(fabs(num[j] - num[j-1]) < 1e-6)tmp++;
                else tmp =1;
                if(ans < tmp)ans = tmp;
            }
        }
        printf("%d\n",ans+1);
    }
    return 0 ;
}
