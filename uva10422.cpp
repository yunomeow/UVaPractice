#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<set>
#include<queue>
#include<iostream>
using namespace std;
struct state{
    char name[30];
    int step;
    bool operator < (const state &a) const{
        return strcmp(name,a.name) < 0;
    }
}tmp;
int dir[8][2] = {-2,1, 2,1, -2,-1, 2,-1, 1,2, 1,-2, -1,2, -1,-2};
char MAP[10][10];
char final[] = "111110111100 110000100000";
queue<state> q;
set<state> s,s2;
int main (){
    int i,T,j,k,z;
    int tx,ty,nx,ny,nowstep,flag;
    int ans;
    char start[30],nowMAP[10][10],ch,nextstate[30];
    set<state>::iterator it;
    for(k=0;k<25;k++){
        tmp.name[k] = final[k];
    }
    tmp.step = 0;
    q.push(tmp);
    s.insert(tmp);
    while(!q.empty()){
        nowstep = q.front().step;
        k = 0;
        for(i=0;i<5;i++){
            for(j=0;j<5;j++){
                nowMAP[i][j] = q.front().name[k];
                if(nowMAP[i][j] == ' '){
                    tx = i;
                    ty = j;
                }
                k++;
            }
        }
        q.pop();
        for(k=0;k<8;k++){
            nx = tx + dir[k][0];
            ny = ty + dir[k][1];
            if(nx >= 0 && ny >= 0 && nx < 5 && ny < 5){
                ch = nowMAP[tx][ty];
                nowMAP[tx][ty] = nowMAP[nx][ny];
                nowMAP[nx][ny] = ch;
                z = 0;
                for(i=0;i<5;i++){
                    for(j=0;j<5;j++){
                        tmp.name[z] = nowMAP[i][j];
                        z++;
                    }
                }
                tmp.name[z] = '\0';
                if(s.find(tmp) == s.end()){
                    tmp.step = nowstep + 1;
                    if(nowstep+1 <= 5){
                        q.push(tmp);
                        s.insert(tmp);
                    }
                }
                ch = nowMAP[tx][ty];
                nowMAP[tx][ty] = nowMAP[nx][ny];
                nowMAP[nx][ny] = ch;
            }
        }
    }
    //printf("%d\n",s.size());
    scanf("%d%*c",&T);
    while(T--){
        s2.clear();
        for(i=0;i<5;i++){
            gets(MAP[i]);
        }
        k=0;
        for(i=0;i<5;i++){
            for(j=0;j<5;j++){
                start[k] = MAP[i][j];
                k++;
            }
          //  printf("%s\n",MAP[i]);
        }
        start[k] = '\0';
        //printf("%s\n",start);
        while(!q.empty())q.pop();
        ans = 1000;
        flag = 0;
//=============================================
        for(k=0;k<25;k++){
            tmp.name[k] = start[k];
        }
        tmp.step = 0;
        q.push(tmp);
        s2.insert(tmp);
        it = s.find(tmp);
        if(it != s.end()){
            ans = it->step;
            flag = 1;
        }
        if(flag == 0){
        while(!q.empty()){
            nowstep = q.front().step;
            k = 0;
            for(i=0;i<5;i++){
                for(j=0;j<5;j++){
                    nowMAP[i][j] = q.front().name[k];
                    if(nowMAP[i][j] == ' '){
                        tx = i;
                        ty = j;
                    }
                    k++;
                }
            }
            q.pop();
            for(k=0;k<8;k++){
                nx = tx + dir[k][0];
                ny = ty + dir[k][1];
                if(nx >= 0 && ny >= 0 && nx < 5 && ny < 5){
                    ch = nowMAP[tx][ty];
                    nowMAP[tx][ty] = nowMAP[nx][ny];
                    nowMAP[nx][ny] = ch;
                    z = 0;
                    for(i=0;i<5;i++){
                        for(j=0;j<5;j++){
                            tmp.name[z] = nowMAP[i][j];
                            z++;
                        }
                    }
                    tmp.name[z] = '\0';

                    if(s2.find(tmp) == s2.end()){
                        tmp.step = nowstep + 1;
                        it = s.find(tmp);
                        if(it != s.end()){
                            if(ans > nowstep + it->step + 1){
                                ans = nowstep + it->step + 1;
                                
                            }
                            flag = 1;
                            //printf("%s\n",tmp.name);  
                        }   
                                           
                        if(nowstep+1 <= 4){
                            q.push(tmp);
                            s2.insert(tmp);
                        }
                    }
                    ch = nowMAP[tx][ty];
                    nowMAP[tx][ty] = nowMAP[nx][ny];
                    nowMAP[nx][ny] = ch;
                }
            }
        }
        }
       // printf("size s2 %d\n",s2.size());
        if(flag == 0){
            printf("Unsolvable in less than 11 move(s).\n");
        }else{
            printf("Solvable in %d move(s).\n",ans);
        }
    }
    return 0;
} 

