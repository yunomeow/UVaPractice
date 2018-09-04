#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int poly[1000];
char s[1004];
int main (){
    int tmp,now,len,x,i,j,num,flag,ans,numtmp;
    while(gets(s)){
        len = strlen(s);
        now = 0;
        x = 0;
        while(now < len){
            sscanf(s+now,"%d%n",&num,&tmp);
            poly[x] = num;
            x++;
            now = now + tmp;
        }
        gets(s);
        now = 0;
        len = strlen(s);
        flag = 0;
        while(now < len){
            sscanf(s+now,"%d%n",&num,&tmp);
            now = now + tmp;
            if(flag == 1)printf(" ");
            flag = 1;
            ans = 0;
            numtmp = 1;
            for(i=x-1;i>=0;i--){
                ans += poly[i]*numtmp;
                numtmp *= num;
            }
            printf("%d",ans);
        }        
        printf("\n");
    }
    return 0;
}
