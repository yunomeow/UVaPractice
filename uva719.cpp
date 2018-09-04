#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char s[10005];
int ans[10005],ans2[10005];
int main (){
    int i,T,now,x,MIN,y,len,k,j;
    scanf("%d%*c",&T);
    while(T--){
        scanf("%s",s);
        len = strlen(s);
        i = 0;j = 1;k = 0;
        while(i < len && j < len && k < len){
            if(s[(i+k)%len] == s[(j+k)%len])k++;
            else if(s[(i+k)%len] > s[(j+k)%len]){i = i+k+1;k = 0;if(i <= j)i = j+1;}
            else if(s[(i+k)%len] < s[(j+k)%len]){j = j+k+1;k = 0;if(j <= i)j = i+1;}
           // printf("%d %d %d\n",i,j,k);        
        }
        if(i < j)
            printf("%d\n",i+1);
        else   
            printf("%d\n",j+1);
    }
    return 0;
}
