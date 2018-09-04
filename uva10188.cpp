#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char s[1000][200],tmp[200];
int stack[200005];
int main (){
    int i,ca=0,n,m,j,len,top,ttop,flag;
    while(1){
        top = 0;
        scanf("%d%*c",&n);
        if(n == 0)break;
        for(i=0;i<n;i++){
            gets(s[i]);
            len = strlen(s[i]);
            for(j=0;j<len;j++){
                if(s[i][j] >= '0' && s[i][j] <= '9'){
                    stack[top] = s[i][j] - 48;
                    top++;
                }
            }
        }
        scanf("%d%*c",&m);
        flag = 2;
        ttop = 0;
        for(i=0;i<m;i++){
            gets(tmp);
            len = strlen(tmp);
            if(strcmp(s[i],tmp) != 0 && flag == 2)flag = 1;
            for(j=0;j<len;j++){
                if(tmp[j] >= '0' && tmp[j] <= '9'){
                    if(tmp[j]-48 != stack[ttop])
                        flag = 0;
                    ttop++;
                }
            }
        }
        if(flag == 2 && n != m)flag = 1;
        if(ttop != top)flag = 0;
        ca++;
        if(flag == 2){
            printf("Run #%d: Accepted\n",ca);
        }else if(flag == 1){
            printf("Run #%d: Presentation Error\n",ca);
        }else{
            printf("Run #%d: Wrong Answer\n",ca);
        }
        
    } 
    return 0;
}
