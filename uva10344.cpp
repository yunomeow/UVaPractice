#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int flag = 0,num[6],tmp[6],use[6];
char s[6];
void dfs(int pos,int val){
    int i;
    if(flag == 1)return;
    if(pos == 4){
        if(val == 23){
            flag = 1;
        }
        return;
    }
  //  printf("pos %d val %d\n",pos,val);
    for(i=0;i<3;i++){
        s[pos] = i+48;
        switch(i){
            case 0:
                dfs(pos+1,val+tmp[pos+1]);
                break;
            case 1:
                dfs(pos+1,val-tmp[pos+1]);
                break;
            case 2:
                dfs(pos+1,val*tmp[pos+1]);
                break;
        }
    }
}
void solve(int pos){
    if(pos == 5){
        dfs(0,tmp[0]);
    }
    if(flag == 1)return;
    int i;
    for(i=0;i<5;i++){
        if(use[i] == 0){
            use[i] = 1;
            tmp[pos] = num[i];
            solve(pos+1);
            use[i] = 0;
        }
    }
}
int main (){
    while(1){
        scanf("%d%d%d%d%d",&num[0],&num[1],&num[2],&num[3],&num[4]);
        if(num[0] == 0 && num[1] == 0 &&num[2] == 0 &&num[3] == 0 &&num[4] == 0 )
            break;
        flag = 0;
        memset(use,0,sizeof(use));
        solve(0);
        if(flag == 1)
            printf("Possible\n");
        else
            printf("Impossible\n");
    }
    return 0;
}
