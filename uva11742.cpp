#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int n,cnt,m;
struct Rule{
    int a,b,c;
}rule[23];
int seat[10];
int ABS(int a){
    if(a < 0)return -a;
    return a;
}
int check(){
    int i ;
    for(i=0;i<m;i++){

        if(rule[i].c > 0){

            if(ABS(seat[rule[i].a] - seat[rule[i].b]) > rule[i].c)return 0;
        }else{
                //printf("ABS %d\n",ABS(seat[rule[i].a] - seat[rule[i].b]));
            if(ABS(seat[rule[i].a] - seat[rule[i].b]) < ABS(rule[i].c)){
                //printf("here\n");
                return 0;
            }
        }
    }
    /*for(i=0;i<n;i++)
        printf("%d ",seat[i]);
    printf("\n");*/
    return 1;
}
int use[100];
void dfs(int pos){
    int i ;
    if(pos == n){
        if(check() == 1){
            cnt++;
        }
        return ;
    }
    for(i=0;i<n;i++){
        if(use[i] == 0){
            seat[pos] = i;
            use[i] = 1;
            dfs(pos+1);
            use[i] = 0;
        }
    }
}
int main (){
    int i;
    while(1){
        scanf("%d%d",&n,&m);
        if(n == 0 && m == 0)break;
        memset(rule,0,sizeof(rule));
        for(i=0;i<m;i++){
            scanf("%d%d%d",&rule[i].a,&rule[i].b,&rule[i].c);
        }
        cnt = 0;
        dfs(0);
        printf("%d\n",cnt);
    }
    return 0;
}
/*
3 1
0 1 -2
3 0
*/

