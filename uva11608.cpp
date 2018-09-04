#include<stdio.h>
#include<stdlib.h>
int prob[20];
int main (){
    int i,n,tmp,ca = 0;
    while(1){
        scanf("%d",&n);
        if(n < 0)break;
        for(i=0;i<12;i++){
            scanf("%d",&prob[i]);
        }
        ca++;
        printf("Case %d:\n",ca);
        for(i=0;i<12;i++){
            scanf("%d",&tmp);
            if(n >= tmp){printf("No problem! :D\n");n-=tmp;}
            else printf("No problem. :(\n");
            n += prob[i];
        }
    }
    return 0;
}
