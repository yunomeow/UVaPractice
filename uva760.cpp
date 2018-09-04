#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
char s1[500],s2[500];
int dp[500][500];
int cnt;
struct state{
    char s[305];
}ans[500000];
bool cmp(state a,state b){
    return strcmp(a.s,b.s) < 0;
}
int main (){
    int i,j,len1,len2;
    int k,l;
    int flag = 0;
    int MAX;
    while(scanf("%s%s%*c",s1,s2) != EOF){
        memset(dp,0,sizeof(dp));
        if(flag == 1)printf("\n");
        flag = 1;
        len1 = strlen(s1);
        len2 = strlen(s2);
        for(i=0;i<len1;i++){
            for(j=0;j<len2;j++){
                if(s1[i] == s2[j]){
                    if(i == 0 || j == 0){
                        dp[i][j] = 1;
                    }else{
                        dp[i][j] = dp[i-1][j-1] + 1;
                    }
                }else
                    dp[i][j] = 0;
            }
        }
        MAX = 0;
        for(i=0;i<len1;i++){
            for(j=0;j<len2;j++){
                if(MAX < dp[i][j])
                    MAX = dp[i][j];
            }
        }
        if(MAX == 0)printf("No common sequence.\n");
        else{
            cnt = 0;
            for(i=0;i<len1;i++){
                for(j=0;j<len2;j++){
                    if(dp[i][j] == MAX){
                        for(k=i-MAX+1,l=0;k<=i;k++,l++){
                            ans[cnt].s[l] = s1[k];
                        }
                        ans[cnt].s[l] = '\0';
                        cnt++;
                    }
                }
            }
            sort(ans,ans+cnt,cmp);
            for(i=0;i<cnt;i++){
                if(i == cnt-1 || strcmp(ans[i].s,ans[i+1].s)!=0)
                printf("%s\n",ans[i].s);
            }
        }
    }
    return 0;
}
