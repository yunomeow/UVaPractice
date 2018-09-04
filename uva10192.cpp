#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char s1[150],s2[150];
int dp[150][150];
int MAX(int a,int b){
    if(a > b)return a;
    else return b;
}
int main (){
    int n,i,len1,len2,j,ca=0;
    s1[0] = '0';
    s2[0] = '0';
    while(1){
        gets(s1+1);
        if(strcmp(s1,"0#") == 0)break;
        gets(s2+1);
        len1 = strlen(s1);
        len2 = strlen(s2);
        memset(dp,0,sizeof(dp));
        for(i=1;i<len1;i++){
            for(j=1;j<len2;j++){
                if(s1[i] == s2[j]){
                    dp[i][j] = MAX(MAX(dp[i-1][j-1] + 1,dp[i-1][j]),dp[i][j-1]);
                }else{
                    dp[i][j] = MAX(dp[i][j-1],dp[i-1][j]);
                }
            }
        }
        ca++;
        printf("Case #%d: you can visit at most %d cities.\n",ca,dp[len1-1][len2-1]);
    }
    return 0;
}
