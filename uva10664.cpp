#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int num[30],x,flag,sum;
char s[300];
void dfs(int now,int pos){
   // printf("now %d\n",now);
    if(now > sum / 2)
        return ;
    if(now == sum / 2){ 
        flag = 1;
        return ;
    } 
    if(flag == 1)
        return ;
    if(pos == x)
        return ;
    dfs(now+num[pos],pos+1);
    dfs(now,pos+1);
}
int main (){
    int i,T,now,len,tmp;
    scanf("%d%*c",&T);
    while(T--){
        x = 0;now = 0;sum = 0;
        gets(s);
        len = strlen(s);
        while(now < len){
            sscanf(s+now,"%d%n",&num[x],&tmp);
            sum+=num[x];
            now = now + tmp;
            x++;
        } 
     //   printf("sum %d\n",sum);
        flag = 0;
        if(sum%2 == 1)
            printf("NO\n");
        else{
            dfs(0,0);
            if(flag == 1)
                printf("YES\n");
            else
                printf("NO\n");
        }
    }
    return 0;
}
