#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;
struct Result{
    int score;
    int ox,oy;
};
class MAPE{
    public:
        int r,c;
        char m[105][105];
        int num;
        int alive;
        MAPE(){
            int i,j;
            for(i=0;i<105;i++)
                for(j=0;j<105;j++)
                    m[i][j] = '-';
            alive = 1;
        }
        void read(int nr,int nc){
            r = nr;
            c = nc;
            int i;
            gets(m[0]);
            for(i=0;i<r;i++){
                gets(m[i]);
                //scanf("%s",m[i]);
            }
        }
        MAPE domerge(MAPE tmp,int ox,int oy,int nn){
            MAPE res;
            int i,j;
            //printf("ox %d oy %d\n",ox,oy);
            if(ox > 0 && oy > 0){
                for(i=0;i<r;i++){
                    for(j=0;j<c;j++){
                        res.m[i][j] = m[i][j];
                    }
                }
                for(i=0;i<tmp.r;i++){
                    for(j=0;j<tmp.c;j++){
                        if(tmp.m[i][j] != '-')
                        res.m[i+ox][j+oy] = tmp.m[i][j];
                    }
                }
                res.r = max(r,tmp.r+ox);
                res.c = max(c,tmp.c+oy);
            }else if(ox > 0 && oy <= 0){
                for(i=0;i<r;i++){
                    for(j=0;j<c;j++){
                        if(m[i][j] != '-')
                        res.m[i][j-oy] = m[i][j];
                    }
                }
                for(i=0;i<tmp.r;i++){
                    for(j=0;j<tmp.c;j++){
                        if(tmp.m[i][j] != '-')
                        res.m[i+ox][j] = tmp.m[i][j];
                    }
                }
                res.r = max(r,tmp.r+ox);
                res.c = max(c-oy,tmp.c);
            }else if(ox <= 0 && oy > 0){
                for(i=0;i<r;i++){
                    for(j=0;j<c;j++){
                        if(m[i][j] != '-')
                        res.m[i-ox][j] = m[i][j];
                    }
                }
                for(i=0;i<tmp.r;i++){
                    for(j=0;j<tmp.c;j++){
                        if(tmp.m[i][j] != '-')
                        res.m[i][j+oy] = tmp.m[i][j];
                    }
                }
                res.r = max(r-ox,tmp.r);
                res.c = max(c,tmp.c+oy);
            }else if(ox <= 0 && oy <= 0){
                for(i=0;i<r;i++){
                    for(j=0;j<c;j++){
                        if(m[i][j] != '-')
                        res.m[i-ox][j-oy] = m[i][j];
                    }
                }
                for(i=0;i<tmp.r;i++){
                    for(j=0;j<tmp.c;j++){
                        if(tmp.m[i][j] != '-')
                        res.m[i][j] = tmp.m[i][j];
                    }
                }
                //printf("OAO %d  %d %d %d\n",r,ox,r-ox,tmp.r);
                res.r = max(r-ox,tmp.r);
                res.c = max(c-oy,tmp.c);
            }
            res.num = nn;
           /* printf("Merge: %d %d\n",res.r,res.c);
            print();
            tmp.print();
            res.print();*/

            return res;
        }
        void print(){
            int i,j;
            printf("    MAP %d:\n",num);
            printf("    +");
            for(i=0;i<c;i++)printf("-");
            printf("+\n");
            for(i=0;i<r;i++){
                printf("    |");
                for(j=0;j<c;j++){
                    printf("%c",m[i][j]);
                }
                printf("|\n");
            }
            printf("    +");
            for(i=0;i<c;i++)printf("-");
            printf("+\n");
        }
        void setNum(int n){
            num = n;
        }
        Result cal(MAPE tmp){
            Result res;
            int i,j,cnt = 0,MAX,px,py;
            int x,y,nx,ny;
            MAX = -1;
           // print();
           // tmp.print();
            for(x=-tmp.r+1;x<r;x++){
                for(y=-tmp.c+1;y<c;y++){
                    cnt = 0;
                   // printf("ox: %d oy : %d\n",x,y);
                    for(i=0;i<r;i++){
                        for(j=0;j<c;j++){
                            nx = i-x;
                            ny = j-y;
                            if(nx < 0 || ny < 0 || nx >= tmp.r || ny >= tmp.c)continue;

                            //printf("compare %c %c %d %d %d %d\n",m[i][j],tmp.m[nx][ny],x,y,nx,ny);
                            if(m[i][j] != '-' && tmp.m[nx][ny] != '-'){

                                if(m[i][j] == tmp.m[nx][ny])cnt++;
                                else{
                                    cnt = -2;
                                    break;
                                }
                            }
                        }
                        if(cnt == -2)break;
                    }
                    if(cnt <= 0)continue;
                    if(MAX < cnt){
                        //printf("x = %d y = %d cnt %d\n",x,y,cnt);
                        px = x;
                        py = y;
                        MAX = cnt;
                    }
                    else if(MAX == cnt && cnt > 0){
                        //printf("=== x = %d y = %d cnt %d\n",x,y,cnt);
                        if(px > x){
                            px = x;
                            py = y;
                        }else if(py == y){
                            if(py > y)py = y;
                        }

                    }
                }
            }
            res.ox = px;
            res.oy = py;
            res.score = MAX;
            return res;
        }
};
int main (){
    int n,ca=0,i,r,c;
    int now,flag,sp,j;
    int ff = 0;
    //freopen("out.txt","w",stdout);
    while(1){
        scanf("%d",&n);
        if(n == 0)break;
        if(ff == 1)
            printf("\n");
        ff = 1;
        now = n;
        MAPE data[40];
        for(i=0;i<n;i++){
            scanf("%d%d",&r,&c);
            data[i].read(r,c);
            data[i].setNum(i+1);
            //data[i].print();
        }
        int pi,pj;
        while(1){
            Result tres,MAXres;
            MAXres.score = -1;
            for(i=0;i<now;i++){
                for(j=i+1;j<now;j++){
                    if(data[i].alive == 1 && data[j].alive == 1){
                        tres = data[i].cal(data[j]);
                        if(tres.score > MAXres.score){
                            MAXres = tres;
                            pi = i;
                            pj = j;
                        }
                    }
                }
            }
            if(MAXres.score <= 0)break;
            data[pi].alive = 0;
            data[pj].alive = 0;
            //printf("MAXres %d %d\n",MAXres.ox,MAXres.oy);
            data[now] = data[pi].domerge(data[pj],MAXres.ox,MAXres.oy,now+1);
            now++;
        }
        ca++;
        printf("Case %d\n",ca);
        sp = 0;
        for(i=0;i<now;i++){
            if(data[i].alive == 1){
                if(sp == 1)printf("\n");
                sp = 1;
                data[i].print();
            }
        }
    }
    return 0;
}
/*

2
3 5
--A-C
----D
----B
3 5
C----
D---F
B----
    MAP 9:
    +-------------+
    |-D--C--------|
    |----G--------|
    |----B-A-C----|
    |--------D---F|
    |-----E--B----|
    |-------------|
    +-------------+
*/
