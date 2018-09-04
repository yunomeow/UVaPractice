#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int val[30];
char s[100000];
int main (){
    int ans,T,ca=0,len,i;
    for(i=0;i<15;i++)
        val[i] = i%3+1;
    val[15] = 1;
    val[16] = 2;
    val[17] = 3;
    val[18] = 4;
    val[19] = 1;                
    val[20] = 2;
    val[21] = 3;
    val[22] = 1;
    val[23] = 2;
    val[24] = 3;
    val[25] = 4;
    scanf("%d%*c",&T);
    while(T--){
        gets(s);
        len = strlen(s);
        ans = 0;
        for(i=0;i<len;i++){
            if(s[i] == ' ')ans+=1;
            else ans+=val[s[i]-97];
        }
        ca++;
        printf("Case #%d: %d\n",ca,ans);
    }
    return 0;
}
