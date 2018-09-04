#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char MAP[10][10],next[10][10];
int dir[4][2] = {1,0,0,1,-1,0,0,-1};
int use[10000];
int main (){
    int T;
    int i,j,k;
    int flag,ans,cnt,tmp;
    scanf("%d%*c",&T);
    while(T--){
        scanf("%*c");
        for(i=0;i<3;i++){
            scanf("%s",MAP[i]);
        }
        flag = 1;
        ans = 0;
        memset(use,0,sizeof(use));
        tmp = 0;
        for(i=0;i<3;i++)
            for(j=0;j<3;j++){
                if(MAP[i][j] == '1'){
                    tmp = tmp * 2 + 1;
                }else{
                    tmp = tmp * 2;
                }
            }
        if(use[tmp] == 0){
            flag = 1;
            use[tmp] = 1;
        }
        while(flag == 1){
            flag = 0;
            for(i=0;i<3;i++){
                for(j=0;j<3;j++){
                    cnt = 0;
                    for(k=0;k<4;k++){
                        if(i+dir[k][0] >= 0 && j+dir[k][1] >= 0 &&
                           i+dir[k][0] <  3 && j+dir[k][1] <  3){
                            if(MAP[i+dir[k][0]][j+dir[k][1]] == '1')
                                cnt++;
                        }
                    }
                    next[i][j] = (cnt%2)+48;
                }
            }
            for(i=0;i<3;i++)
                for(j=0;j<3;j++)
                    MAP[i][j] = next[i][j];
            tmp = 0;
            for(i=0;i<3;i++)
                for(j=0;j<3;j++){
                    if(MAP[i][j] == '1'){
                        tmp = tmp * 2 + 1;
                    }else{
                        tmp = tmp * 2;
                    }
                }
            if(use[tmp] == 0){
                flag = 1;
                use[tmp] = 1;
            }

            ans++;
        }
        printf("%d\n",ans-2);
    }
    return 0;
}
/*
3

111
100
001

101
000
101

000
000
000
*/
