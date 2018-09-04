#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct shik{
    char name[100];
    int t;
    
} data[10000];
int main (){
    int i,T,n,d,ca = 0,type;
    char s[100];
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(i=0;i<n;i++){
            scanf("%s%d",data[i].name,&data[i].t);
        }
        scanf("%d%s",&d,s);
      //  printf("----------\n");
        type = 0;
        for(i=0;i<n;i++)
            if(strcmp(data[i].name,s) == 0){
                if(data[i].t <= d)
                    type = 1;
                else if(data[i].t <= d+5)
                    type = 2;
                else
                    type = 3;
                break;
            }
        ca++;
        printf("Case %d: ",ca);
        if(type == 1)printf("Yesss\n");
        else if(type == 2)printf("Late\n");
        else printf("Do your own homework!\n");
    }
    return 0;
}
