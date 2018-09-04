#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#include<iostream>
using namespace std;
struct Segment{
    int a,b;
}data[100005];
bool cmp(Segment a,Segment b){
    if(a.a == b.a)return a.b > b.b;
    return a.a < b.a;
}
int use[100005];
int main (){
    int T,n,m;
    int i;
    int left,right;
    int nr;
    int a,b,pos;
    int sp=0;
    scanf("%d",&T);
    while(T--){
        if(sp == 1)printf("\n");
        sp = 1;
        scanf("%d",&m);
        n = 0;
        while(1){
            scanf("%d",&a,&b);
            if(a == 0 && b == 0)break;
            data[n].a = a;
            data[n].b = b;
            n++;
        }
        memset(use,0,sizeof(use));
        sort(data,data+n,cmp);
        right = 0;
        flag = 1;
        for(i=0;i<n;i++){
            nr = right;
            pos = -1;
            for(j=i;j<n;j++){
                if(data[j].a > right)break;
                else{
                    if(data[j].b > nr){
                        nr = data[j].b;
                        pos = j;
                    }
                }
            }
            if(pos == -1){
                flag = 0;
                break;
            }
            use[pos] = 1;
            right = nr;
            if(right >= m)break;
            i = j-1;
        }
        if(right < m)flag = 0;
        if(flag == 0){
            printf("0\n");
        }else{
            int cnt = 0;
            for(i=0;i<n;i++){
                if(use[i] == 1)
                    cnt++;
            printf("%d\n",cnt);
            for(i=0;i<n;i++){
                if(use[i] == 1)
                    printf("%d %d\n",data[i].a,data[i].b);
            }
        }
    }
    return 0;
}
