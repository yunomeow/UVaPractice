#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char s[100005],t[100005];
int main (){
    int i,j,lens,lent;
    while(scanf("%s%s",s,t) != EOF){
        lens = strlen(s);
        lent = strlen(t);
        i = 0;j = 0;
        while(i < lens && j < lent){
            if(s[i] == t[j]){
                i++;j++;
            }else
                j++;
        }
        if(i == lens)printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
