#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main (){
    char s[100];
    int ans,T,tmp;
    scanf("%d%*c",&T);
    ans = 0;
    while(T--){
        scanf("%s",s);
        if(strcmp(s,"donate") == 0){
            scanf("%d",&tmp);
            ans += tmp;
        }else if(strcmp(s,"report") == 0){
            printf("%d\n",ans);
        }
    }
    return 0;
}
/*
4
donate 1000
report
donate 500
report
*/
