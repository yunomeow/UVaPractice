#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
int cnt[300];
int main (){
    int T,i,len,MAX;
    char s[10000];
    scanf("%d%*c",&T);
    while(T--){
        gets(s);
        len = strlen(s);
        memset(cnt,0,sizeof(cnt));
        for(i=0;i<len;i++){
            cnt[tolower(s[i])]++;
        }
        MAX = 0;
        for(i=80;i<200;i++)
            if(cnt[i] > MAX)
                MAX = cnt[i];
       // printf("%d\n",MAX);
        for(i=80;i<200;i++)
            if(cnt[i] == MAX)
                printf("%c",i);
        printf("\n");
    }
    return 0;
}
