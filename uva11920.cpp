#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main (){
    int i,len,T;
    char s[1005];
    scanf("%d%*c",&T);
    while(T--){
        scanf("%s",s);
        len = strlen(s);
        for(i=0;i<len;i++){
            if(s[i] == '?'){
                if(i == 0 && s[i]!='?')
                    s[i] = s[i] = (!(s[i+1]-48))+48;;
                else if(i>0&& i<len-1&&s[i-1]==s[i+1])
                    s[i] = (!(s[i-1]-48))+48;
                else if(i == len-1 && s[i]!='?')
                    s[i] = (!(s[i-1]-48))+48;
            }
        }
    }
    return 0;
}
