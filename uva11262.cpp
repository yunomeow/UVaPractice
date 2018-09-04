#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int matrix[][];
struct Point{
    int x,y;
}p1[1000],p2[1000];
int main (){
    int T,n,k;
    int bcnt,rcnt;
    char color[1000];
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&k);
        bcnt = 0;
        for(i=0;i<n;i++){
            scanf("%d%d%s",&tx,&ty,color);
            if(strcmp(color,"blue") == 1){
                p1[bcnt].x = tx;
                p1[bcnt].y = ty;
                bcnt++;
            }
            if(strcmp(color,"red") == 1){
                p2[rcnt].x = tx;
                p2[rcnt].y = ty;
                rcnt++;
            }
        }
        for(i=0;i<bcnt;i++){
            for(j=0;j<rcnt;j++){
            }
        }
    }
    return 0;
}
/*
2
6 2
-3 5 blue
-3 3 red
1 5 blue
2 0 red
4 6 blue
4 -1 red
*/
