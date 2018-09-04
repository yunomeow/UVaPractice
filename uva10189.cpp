#include<stdio.h>
#include<stdlib.h>
char MAP[105][105];
int dir[8][2] = {1,0,0,1,-1,0,0,-1,1,-1,-1,1,1,1,-1,-1};
int main (){
    int i,j,k,cnt,x,y,ca = 0,n,m;
    while(1){
        scanf("%d%d%*c",&n,&m);
        if(n == 0 && m == 0)break;
        for(i=0;i<n;i++)
            scanf("%s",MAP[i]);
        if(ca != 0)printf("\n");
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                if(MAP[i][j] == '.'){
                    cnt = 0;
                    for(k=0;k<8;k++){
                        x = i+dir[k][0];
                        y = j+dir[k][1];
                        if(x >= 0 && y >= 0 && x < n && y < m){
                            if(MAP[x][y] == '*')
                                cnt++;
                        }
                    }
                    MAP[i][j] = cnt + '0';
                }
            }
        }
        ca++;
        printf("Field #%d:\n",ca);
        for(i=0;i<n;i++)
            printf("%s\n",MAP[i]);
    }
    return 0;
}
