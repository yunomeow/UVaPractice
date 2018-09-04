#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main (){
    char s[10000];
    int n,i,j,len;
    while(1){
        scanf("%d",&n);
        if(n == 0)break;
        scanf("%s",s);
        len = strlen(s);
        n = len / n;
        for(i=0;i<len;i+=n){
            for(j=n-1;j>=0;j--)
                printf("%c",s[i+j]);
        }
        printf("\n");
    }
    return 0;
}
