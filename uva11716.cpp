#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int main (){
    int i,len,T,j,sq;
    char s[100000];
    scanf("%d%*c",&T);
    while(T--){
        gets(s);
        len = strlen(s);
        sq = sqrt(len)+0.5;
        if(sq * sq != len){
            printf("INVALID\n");
            continue;
        }
        
        for(i=0;i<sq;i++){
            for(j=0;j<sq;j++){
                printf("%c",s[j*sq+i]);
            }
        }
        printf("\n");
    }
    return 0;
}
