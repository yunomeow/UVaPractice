#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
int num[1000005];
int cnt[65540];
int main (){
    int n,k,i,a,b;
    while(scanf("%d",&n)!=EOF){
        memset(cnt,0,sizeof(cnt));
        for(i=0;i<n;i++){
            scanf("%d",&num[i]);
            cnt[num[i]]++;
        }
        sort(num,num+n);
        if(n%2 == 1){
            k = num[n/2];
            printf("%d %d %d\n",k,cnt[k],1);
        }else{
            a = num[n/2-1];
            b = num[n/2];
            printf("%d %d %d\n",a,cnt[a]+cnt[b],b-a+1);
        }
    }
    return 0;
}
