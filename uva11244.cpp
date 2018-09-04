#include<stdio.h>
#include<stdlib.h>
char MAP[105][105];
int dir[8][2] = {0,1,1,0,-1,0,0,-1,1,1,1,-1,-1,1,-1,-1};
int main(){
    int i,j,n,m,cnt,k,x,y,flag;
    while(1){
        scanf("%d%d%*c",&n,&m);
        if(n == 0 && m == 0)break;
        for(i=0;i<n;i++)
            gets(MAP[i]);
        cnt = 0;
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                if(MAP[i][j] != '*')continue;
                flag = 1;
                for(k=0;k<8;k++){
                    x = i + dir[k][0];
                    y = j + dir[k][1];
                    if(x >= 0 && x < n && y >= 0 && y < m){
                        if(MAP[x][y] == '*'){
                            flag = 0;
                            break;
                        }
                    } 
                }
                if(flag == 1)cnt++;
            }
        }
        printf("%d\n",cnt);
    }
    return 0;
}
