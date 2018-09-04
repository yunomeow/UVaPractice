#include<stdio.h>
#include<stdlib.h>
int main (){
    int n,x,y,a,b;
    while(1){
        scanf("%d",&n);
        if(n == 0)break;
        scanf("%d%d",&x,&y);
        while(n--){
            scanf("%d%d",&a,&b);
            if(a == x || y == b)printf("divisa\n");
            else if(a > x && b > y)printf("NE\n");
            else if(a > x && b < y)printf("SE\n");
            else if(a < x && b > y)printf("NO\n");
            else if(a < x && b < y)printf("SO\n");
        }
    }
    return 0;
}
/*
3
2 1
10 10
-10 1
0 33
4
-1000 -1000
-1000 -1000
0 0
-2000 -10000
-999 -1001
0
*/
