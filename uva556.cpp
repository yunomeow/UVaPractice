#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char MAP[100][100];
int cnt[100][100];
int dir[4][2] = {0,1,-1,0,0,-1,1,0};
int ans[10];
int main (){
    int n,m;
    int d,nowx,nowy,nextx,nexty;
    int tx,ty;
    int i,j;
    //r u l d 0123
    while(1){
        scanf("%d%d",&n,&m);
        if(n == 0 && m == 0)break;
        for(i=0;i<n;i++)
            scanf("%s",MAP[i]);
        memset(cnt,0,sizeof(cnt));
        nowx = n-1;
        nowy = 0;
        d = 0;
        nextx = 0;
        nexty = 0;
        while(nextx != n-1 || nexty != 0){
            nextx = nowx + dir[d][0];
            nexty = nowy + dir[d][1];
            tx = nowx + dir[(d-1+4)%4][0];
            ty = nowy + dir[(d-1+4)%4][1];
            //printf("nextx %d nexty %d d %d\n",nextx,nexty,d);
            if(tx >= 0 && ty >= 0 && tx < n && ty < m && MAP[tx][ty] == '0'){
                nowx = tx;
                nowy = ty;
                d = ((d-1)+4)%4;
                cnt[nowx][nowy]++;
            }else if(nextx < 0 || nexty < 0 || nextx >= n || nexty >= m){
                d++;
                d%=4;
            }else if(MAP[nextx][nexty] == '1'){
                d++;
                d%=4;
            }else{
                nowx = nextx;
                nowy = nexty;
                cnt[nowx][nowy]++;
            }
        }
        memset(ans,0,sizeof(ans));
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                if(cnt[i][j] < 5 && MAP[i][j] == '0'){
                    ans[cnt[i][j]]++;
                }
            }
        }
        for(i=0;i<5;i++){
            printf("%3d",ans[i]);
        }
        printf("\n");

    }
    return 0;
}
