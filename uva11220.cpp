#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char s[10000],ss[10000];
int main (){
    int T,tmp,cnt,now,len,tlen,ca=0,flag = 0,i;
    scanf("%d%*c%*c",&T);
    while(T--){
        if(flag == 1)printf("\n");
        flag = 1;
        ca++;
        printf("Case #%d:\n",ca);
        while(gets(s)){
            
            if(strcmp(s,"") == 0){
                break;
            }
            len = strlen(s);
            for(i = len-1;i >= 0;i--){
                if(s[i] != ' ')break;
                else s[i] = 0;
            }
            len = strlen(s);
            now = 0;
            cnt = 1;
            while(now < len){
                sscanf(s+now,"%s%n",ss,&tmp);
               // printf("ss = \"%s\"\n",ss);
                now += tmp;
               // printf("now = %d len = %d tmp = %d\n",now,len,tmp);
                tlen = strlen(ss);
                if(tlen >= cnt){
                    printf("%c",ss[cnt-1]);
                    cnt++;
                }else
                    continue;
            }
            printf("\n");
        }
    }
    return 0;    
}


