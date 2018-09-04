#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
struct skyly{
    int cor[5];
}data[10005];
int tmp[5];
int num[10005];
bool cmp2(int a,int b){
    return a < b;
}
bool cmp(skyly a,skyly b){
    int i=0;
    while(i<5){
        if(a.cor[i] != b.cor[i])
            return a.cor[i] < b.cor[i];
        i++;
    }
    return a.cor[0] < b.cor[0];
}
int main (){
    int i,n,j,MAX,cnt,k,l,nowMAX,ans,flag;
    while(1){
        scanf("%d",&n);
        if(n == 0)break;
        for(i=0;i<n;i++){
            for(j=0;j<5;j++){
                scanf("%d",&tmp[j]);
            }
            sort(tmp,tmp+5);
            for(j=0;j<5;j++)
                data[i].cor[j] = tmp[j];
        }
        sort(data,data+n,cmp);
        memset(num,0,sizeof(num));
        nowMAX = 0;
        for(i=0;i<n;i++){
            MAX = 0;
            for(j=0;j<n;j++){
                if(i!=j){
                    flag = 1;
                    for(k=0;k<5;k++){
                            if(data[i].cor[k] != data[j].cor[k]){
                                flag = 0;
                                break;
                            }
                    }
                    if(flag == 1)MAX++;
                }
            }
            if(MAX > nowMAX)nowMAX = MAX;
            num[i] = MAX;
        }
        ans = 0;
        for(i=0;i<n;i++)
            if(num[i] == nowMAX)
                ans++;
        printf("%d\n",ans);                
    }
    return 0;
}
