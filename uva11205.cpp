#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>
using namespace std;
int num[105][105];
int use[20];
int ans,n,p;
int data[105];

void check(){
    int i,j,k=0,cnt=0,flag;
    for(i=0;i<n;i++){
        data[i] = 0;
        for(j=0;j<p;j++){
            if(use[j] == 1){
                data[i] = data[i] * 2 + num[i][j];
            }
        }
    }
    for(j=0;j<p;j++)
        if(use[j] == 1)cnt++;
    sort(data,data+n);
    for(i=1;i<n;i++){
        if(data[i]==data[i-1])return;
    }
    if(ans > cnt) ans = cnt;
}
void dfs(int pos){
    if(pos == p){
        check();
        return;
    }
    use[pos] = 0;
    dfs(pos+1);
    use[pos] = 1;
    dfs(pos+1);
    use[pos] = 0;
}
int main (){
    int T,i,j;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&p,&n);
        for(i=0;i<n;i++){
            for(j=0;j<p;j++)
                scanf("%d",&num[i][j]);
        }
        ans = 100;
        dfs(0);
        printf("%d\n",ans);
    }
    return 0;
}
/*
2
7
10
1 1 1 0 1 1 1
0 0 1 0 0 1 0
1 0 1 1 1 0 1
1 0 1 1 0 1 1
0 1 1 1 0 1 0
1 1 0 1 0 1 1
1 1 0 1 1 1 1
1 0 1 0 0 1 0
1 1 1 1 1 1 1
1 1 1 1 0 1 1
*/
