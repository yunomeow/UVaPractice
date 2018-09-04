#include<stdio.h>
#include<stdlib.h>
struct Hotel{
    int num[100];
    int p;
}data[100];
int main (){
    int n,m,b,h;
    int w,i,j;
    int MIN;
    while(scanf("%d%d%d%d",&n,&b,&h,&w) != EOF){
        for(i=0;i<h;i++){
            scanf("%d",&data[i].p);
            for(j=0;j<w;j++)
                scanf("%d",&data[i].num[j]);
        }
        MIN = 2100000000;
        for(i=0;i<h;i++){
            for(j=0;j<w;j++){
                if(data[i].num[j] >= n){
                    if(n * data[i].p < MIN && n*data[i].p <= b)
                        MIN = n * data[i].p;
                }
            }
        }
        if(MIN == 2100000000)printf("stay home\n");
        else printf("%d\n",MIN);
    }
    return 0;
}
