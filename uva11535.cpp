#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int two[14]= {1,2,4,8,16,32,64,128,256,512,1024,2048};
char ans[10000][100];
int x;
void dfs(int code,int pos){
    int tmp,i,j;
    //printf("code %d pos %d\n",code,pos);
    if(pos == 0){
        if(code == 0){
            printf("Move 1 from B2 to B1\n");
            sprintf(ans[x],"Move 1 from B1 to B2\n");
            x++;
        }else{
            printf("Move 1 from B1 to B2\n");
            sprintf(ans[x],"Move 1 from B2 to B1\n");
            x++;
        }
        return ;
    }
    tmp = code & two[pos];
    //printf("tmp %d\n",tmp);
    if(tmp != 0)
        dfs(code ^ two[pos],pos-1);
    else
        dfs(code,pos-1);
    if(tmp == 0){
        printf("Move %d from B2 to B1\n",pos+1);
        sprintf(ans[x],"Move %d from B1 to B2\n",pos+1);
        x++;
    }else{
        printf("Move %d from B1 to B2\n",pos+1);
        sprintf(ans[x],"Move %d from B2 to B1\n",pos+1);
        x++;
    }
    //printf("pos %d x %d\n",pos,x);
    for(i=x-2;i>=0;i--){
        printf("%s",ans[i]);
        sprintf(ans[x],"%s",ans[i]);
        for(j=strlen(ans[x]);j>=0;j--){
            if(ans[x][j] == '1' && ans[x][j-1] == 'B')ans[x][j] = '2';
            else if(ans[x][j] == '2' && ans[x][j-1] == 'B')ans[x][j] = '1';
        }
        x++;
    }
}
int main (){
    int n,i,b,c,T,tmp;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&b);
        c = 0;
        x = 0;
        for(i=0;i<b;i++){
            scanf("%d",&tmp);
            c = c | two[tmp-1];
        }
       // printf("c %d\n",c);
        dfs(c,n-1);
        printf("\n");
    }
    return 0;
}
/*
2
2 1
1
4 2
1 3
*/

