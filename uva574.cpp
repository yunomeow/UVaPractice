#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
struct shik{
    char s[1000];
}data[10000];
bool cmp(shik a,shik b){
    int lena=strlen(a.s),lenb=strlen(b.s),i=0;
    while(i < lena && i < lenb){
        if(a.s[i] != b.s[i])
            return a.s[i] > b.s[i];
        i++;
    }
    return lena < lenb;
}
int num[20],use[20];
int target,n,pri;
void dfs(int pos,int sum){
    int i,flag=0,x=0,same = 0,len;
    if(pos == n){
        if(sum == target){
            for(i=0;i<n;i++){
                if(use[i] == 1){
                    len = strlen(data[pri].s);
                    if(flag == 0){
                        sprintf(data[pri].s+len,"%d",num[i]);
                    }else{
                        sprintf(data[pri].s+len,"+%d",num[i]);
                    }
                    flag = 1;
                }
            }
            pri++;
        }
        return ;
    }
    use[pos] = 1;
    dfs(pos+1,sum+num[pos]);
    use[pos] = 0;
    dfs(pos+1,sum);
}
int main (){
    int i;
    while(1){
        scanf("%d%d",&target,&n);
        if(n == 0)break;
        for(i=0;i<10000;i++)
            data[i].s[0] = '\0';
        for(i=0;i<n;i++)
            scanf("%d",&num[i]);
        pri = 0;
        printf("Sums of %d:\n",target);
        dfs(0,0);
        if(pri == 0)printf("NONE\n");
        else{
            sort(data,data+pri,cmp);
            printf("%s\n",data[0].s);
            for(i=1;i<pri;i++){
                if(strcmp(data[i].s,data[i-1].s) ==0)
                    continue;
                else
                    printf("%s\n",data[i].s);
            }
        }
    }
    return 0;
}
