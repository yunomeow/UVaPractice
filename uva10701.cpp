#include<stdio.h>
#include<stdlib.h>
char pre[100],in[100],post[100];
int n;
void dfs(int left,int right){
    int first = 100,tmp,pos,i,j;
    if(left < 0 || right >= n  || left > right)return;
    if(left == right){
        printf("%c",in[left]);
        return;
    }
   // printf("left %d right %d\n",left,right);
    for(i=left;i<=right;i++){
        for(j=0;j<n;j++){
            if(pre[j] == in[i]){
                if(first > j){
                    first = j;
                    pos = i;
                }
                break;
            }
        }
    }
  //  printf("pos %d\n",pos);
  //  system("pause");
    dfs(left,pos-1);
    dfs(pos+1,right);
    dfs(pos,pos);
}
int main (){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%s%s",&n,pre,in);
        dfs(0,n-1);
        printf("\n");
    }
}
