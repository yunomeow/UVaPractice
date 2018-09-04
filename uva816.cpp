#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char name[100];
int valid[10][10][4][4];
int vis[10][10][4];
int ans[10000][2];
int q[100000][3];
int dir[4][2] = {-1,0,0,1,1,0,0,-1};
int par[10][10][4][3];
int finddir(char c){
    switch(c){
        case 'N':return 0;
        case 'E':return 1;
        case 'S':return 2;
        case 'W':return 3;
    }
}
int LEFT(int d){
    d--;
    if(d < 0)d = 3;
    return d;
}
int RIGHT(int d){
    d++;
    d %= 4;
    return d;
}
int FORWARD(int d){
    //d+=2;
    //d %= 4;
    return d;
}
int main(){
    char s[100],stdir;
    int stx,sty,edx,edy,stdd,edd;
    int ssx,ssy,ssd;
    int a,b,d,i;
    int len,cnt;
    int nowx,nowy,nowd,nextx,nexty,nextd;
    int head,tail,flag,x;
    while(1){
        scanf("%s",name);
        if(strcmp("END",name) == 0)break;
        memset(valid,0,sizeof(valid));
        scanf("%d%d%*c%c%*c%d%d",&stx,&sty,&stdir,&edx,&edy);
        while(1){
            scanf("%d",&a);
            if(a == 0)break;
            scanf("%d",&b);
            while(1){
                scanf("%s",s);
                if(strcmp(s,"*")==0)break;
                len = strlen(s);
                d = finddir(s[0]);
                for(i=1;i<len;i++){
                    if(s[i] == 'L')
                        valid[a][b][d][LEFT(d)] = 1;
                    if(s[i] == 'R')
                        valid[a][b][d][RIGHT(d)] = 1;
                    if(s[i] == 'F')
                        valid[a][b][d][FORWARD(d)] = 1;

                }
            }
        }

        //bfs
        memset(vis,0,sizeof(vis));
        flag = 0;
        head = 0;
        tail = 1;
        stdd = finddir(stdir);
        if(stdd == 0){
            q[0][0] = stx-1;
            q[0][1] = sty;
            vis[stx-1][sty][stdd] = 1;    
        }else if(stdd == 1){
            q[0][0] = stx;
            q[0][1] = sty+1;
            vis[stx][sty+1][stdd] = 1;    
        }else if(stdd == 2){
            q[0][0] = stx+1;
            q[0][1] = sty;        
            vis[stx+1][sty][stdd] = 1;    
        }else{
            q[0][0] = stx;
            q[0][1] = sty-1;        
            vis[stx][sty-1][stdd] = 1;            
        }
        ssx = q[0][0];
        ssy = q[0][1];
        ssd = stdd;
        edd = ssd;
        q[0][2] = stdd;
//        vis[stx][sty][stdd] = 1;
        while(head != tail){
            nowx = q[head][0];
            nowy = q[head][1];
            nowd = q[head][2];
            if(nowx == edx && nowy == edy){
                flag = 1;
                break;
            }
            head++;
         //   printf("nowx %d nowy %d nowd %d\n",nowx,nowy,nowd);
            for(i=0;i<4;i++){
                if(valid[nowx][nowy][nowd][i] == 1){
                    nextx = nowx + dir[i][0];
                    nexty = nowy + dir[i][1];
                    if(vis[nextx][nexty][i] == 0){
                        vis[nextx][nexty][i] = 1;
                        par[nextx][nexty][i][0] = nowx;
                        par[nextx][nexty][i][1] = nowy;
                        par[nextx][nexty][i][2] = nowd;
                        q[tail][0] = nextx;
                        q[tail][1] = nexty;
                        q[tail][2] = i;
                        if(nextx == edx && nexty == edy){flag = 1;edd = i;}
                        tail++;
                    }
                }
                if(flag == 1)break;
            }
            if(flag == 1)break;
        }
        printf("%s",name);
        cnt = 0;
        if(flag == 0)printf("\n  No Solution Possible\n");
        else{
            nowx = edx;
            nowy = edy;
            nowd = edd;
            x = 0;
            while(ssx != nowx || ssy != nowy || ssd != nowd){
                ans[x][0] = nowx;
                ans[x][1] = nowy;
                x++;
                nextx = par[nowx][nowy][nowd][0];
                nexty = par[nowx][nowy][nowd][1];
                nextd = par[nowx][nowy][nowd][2];
                nowx = nextx;
                nowy = nexty;
                nowd = nextd;
            }
            cnt = 2;
            printf("\n  (%d,%d) (%d,%d)",stx,sty,ssx,ssy);
            for(i=x-1;i>=0;i--){
                if(cnt % 10 == 0)printf("\n ");
                printf(" (%d,%d)",ans[i][0],ans[i][1]);
                cnt++;
            }
            printf("\n");
        }
    }
    return 0;
}

/*
SAMPLE
3 1 N 3 3
1 1 WL NR *
1 2 WLF NR ER *
1 3 NL ER *
2 1 SL WR NF *
2 2 SL WF ELF *
2 3 SFR EL *
0
*/
