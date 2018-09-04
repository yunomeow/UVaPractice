#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char s1[400],s2[400];
int main (){
    int i,len1,len2,flag,T;
    scanf("%d",&T);
    while(T--){
        scanf("%s%s",s1,s2);
        len1 = strlen(s1);
        len2 = strlen(s2);
        flag = 1;
        if(len1 != len2)flag = 0;
        if(flag == 1){
            for(i=0;i<len1;i++){
                if((s1[i] == 'a' || s1[i] == 'e' || s1[i] == 'i'|| s1[i] == 'o'|| s1[i] == 'u')
                &&(s2[i] == 'a' || s2[i] == 'e' || s2[i] == 'i'|| s2[i] == 'o'|| s2[i] == 'u'))
                    continue;
                else {
                    if(s1[i]!=s2[i]){
                        flag= 0;
                        break;
                    }
                }
            }
        }
        if(flag == 0)printf("No\n");
        else printf("Yes\n");
    }
    return 0;
}
