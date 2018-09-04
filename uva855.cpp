#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
struct XD{
    int x,y;
}data[100000];
bool cmp(XD a,XD b){
    return a.x < b.x;
}
bool cmp2(XD a,XD b){
    return a.y < b.y;
}
int main (){
    int n,m,f,i,T;
    int x,y;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d",&n,&m,&f);
        for(i=0;i<f;i++)
            scanf("%d%d",&data[i].x,&data[i].y);

        sort(data,data+f,cmp);
        x = data[(f-1)/2].x;
        sort(data,data+f,cmp2);
        y = data[(f-1)/2].y;
        printf("(Street: %d, Avenue: %d)\n",x,y);
    }
    return 0;
}
/*
2
2 2 2
1 1
2 2
7 7 11
1 2
1 7
2 2
2 3
2 5
3 4
4 2
4 5
4 6
5 3
6 5
*/
