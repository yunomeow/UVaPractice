#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char in[1000005];
int main (){
    int flag,cnt,MAX;
    int i,len,ans;
    while(gets(in)){
        len = strlen(in);
        flag = 0;
        cnt = 0;
        MAX = 0;
        for(i=0;i<len;i++){
            if(in[i] != ' '){
                flag = 0;
                cnt = 0;
            }else{
                cnt++;
                flag = 1;
                if(cnt > MAX)MAX = cnt;
            }
        }
        MAX--;
        ans = 0;
        while(MAX > 0){
            ans++;
            MAX /= 2;
        }
        printf("%d\n",ans);
    }
    return 0;
}
