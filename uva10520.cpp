#include<stdio.h>
#include<stdlib.h>
#include<string.h>
long long a[105][105];
long long MAX(long long a,long long b){
    if(a > b)return a;
    return b;
}
int n;
long long cal(int i,int j){
    long long tmp,val = -100000,v1,v2;
    int k;
    if(a[i][j] != -1)return a[i][j] ;
    //printf("i: %d j: %d\n",i,j);
    if(i < j){
        for(k=i;k<j;k++){
            tmp = cal(i,k) + cal(k+1,j);
            val = MAX(tmp,val);
        }
        a[i][j] = val;
        return a[i][j]; 
    }else{
        v1 = 0;
        if(i == n){
            v1 = 0;
        }else{
            for(k=i+1;k<=n;k++){
                tmp = cal(k,1) + cal(k,j);
                v1 = MAX(v1,tmp);
            }
        }
        v2 = 0;
        if(j == 0){
            v2 = 0;
        }else{
            for(k=1;k<j;k++){
               // printf("%d %d\n",cal(i,k),cal(n,k));
                tmp = cal(i,k) + cal(n,k);
               // printf("tmp %d\n",tmp);
                v2 = MAX(v2,tmp);
            }
        }        
        a[i][j] = v1 + v2;
       // printf("v1 %d v2 %d\n",v1,v2);
        return a[i][j];
    }
}
int main (){
    int num;
    while(scanf("%d%d",&n,&num) != EOF){
        memset(a,-1,sizeof(a));
        a[n][1] = num;
        printf("%lld\n",cal(1,n));
    }
    return 0;
}
