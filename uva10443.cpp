#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char MAP[105][105];
char nextMAP[105][105];
int dir[4][2]  = {1,0,0,1,-1,0,0,-1};
int main (){
    int T,n,m,k;
    int i,j,z,y;
    int nx,ny;
    int flag = 0;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d",&n,&m,&k);
        if(flag == 1)printf("\n");
        flag = 1;
        for(i=0;i<n;i++){
            scanf("%s",MAP[i]);
        }
        for(i=0;i<k;i++){
            for(j=0;j<n;j++){
                strcpy(nextMAP[j],MAP[j]);
            }
            for(j=0;j<n;j++){
                for(z = 0;z < m;z++){
                    for(y = 0;y<4;y++){
                        nx = j + dir[y][0];
                        ny = z + dir[y][1];
                        if(nx >= 0 && ny >= 0 && nx < n && ny < m){
                            if(MAP[j][z] == 'S'){
                                if(MAP[nx][ny] == 'P'){
                                    nextMAP[nx][ny] = 'S';
                                }
                            }
                            if(MAP[j][z] == 'R'){
                                if(MAP[nx][ny] == 'S'){
                                    nextMAP[nx][ny] = 'R';
                                }
                            }
                            if(MAP[j][z] == 'P'){
                                if(MAP[nx][ny] == 'R'){
                                    nextMAP[nx][ny] = 'P';
                                }
                            }                            
                        }
                    }
                } 
            }
            for(j=0;j<n;j++){
                strcpy(MAP[j],nextMAP[j]);
            }            
        }
        for(i=0;i<n;i++)printf("%s\n",MAP[i]);
    }
}
/*
2
3 3 1
RRR
RSR
RRR
3 4 2
RSPR
SPRS
PRSP
*/
