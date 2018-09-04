#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char s1[100],s2[100];
char dict[5000][200];
struct vocab{
    char name[100];
    char la[100];
    char lb[100];
    int a,b;
    int len;
}data[4005];
int matrix[4005][4005],dis[4005],vis[4005];
int main (){
    int i,j,k,m,a,b,c,x,MIN,st,ed;
    while(scanf("%d%*c",&m) != EOF){
        if(m == 0)break;
        x = 0;
        scanf("%s%s",s1,s2);
        for(i=0;i<m;i++){
            scanf("%s%s%s",data[i].la,data[i].lb,data[i].name);
            for(j=0;j<x;j++){
                if(strcmp(data[i].la,dict[j]) == 0){
                    data[i].a = j;
                    break;
                }
            }
            if(j == x){
                strcpy(dict[j],data[i].la);
                data[i].a = j;
                x++;
            }
            for(j=0;j<x;j++){
                if(strcmp(data[i].lb,dict[j]) == 0){
                    data[i].b = j;
                    break;
                }
            }
            if(j == x){
                strcpy(dict[j],data[i].lb);
                data[i].b = j;
                x++;
            }
            data[i].len = strlen(data[i].name);
        }
        for(i=0;i<m+2;i++){
            vis[i] = 0;
            for(j=0;j<m+2;j++)
                matrix[i][j] = -1;
        }
        for(i=0;i<x;i++){
            if(strcmp(s1,dict[i]) == 0){
                st = i;
                break;
            }
        }
        if(i == x){
            strcpy(dict[i],s1);
            st = i;
            x++;
        }
        for(i=0;i<x;i++){
            if(strcmp(s2,dict[i]) == 0){
                ed = i;
                break;
            }
        }
        if(i == x){
            strcpy(dict[i],s2);
            ed = i;
            x++;
        }
        for(i=0;i<m;i++){
            for(j=0;j<m;j++){
                if(i!=j){
                    if(data[i].a == data[j].b || data[i].a == data[j].a ||data[i].b == data[j].a ||data[i].b == data[j].b){
                        if(data[i].name[0] != data[j].name[0]){
                            matrix[i][j] = data[i].len;
                        }
                    }
                }
            }
        }
        for(i=0;i<m;i++){
            if(st == data[i].a || st == data[i].b){
                matrix[m][i] = 0;
            }
        }
        for(i=0;i<m;i++){
            if(ed == data[i].a || ed == data[i].b){
                matrix[i][m+1] = data[i].len;
            }
        }
        for(i=0;i<m+2;i++)dis[i] = 10000000;
        dis[m] = 0;
        for(i=0;i<m+2;i++){
            MIN = 10000000;
            for(j=0;j<m+2;j++){
                if(vis[j] == 0 && dis[j] < MIN){
                    MIN = dis[j];
                    k = j;
                }
            }
            if(MIN == 10000000)break;
            vis[k] = 1;
            for(j=0;j<m+2;j++){
                if(k!=j && matrix[k][j] != -1 && dis[j] > dis[k] + matrix[k][j]){
                    dis[j] = dis[k] + matrix[k][j];
                }
            }
        }
        if(dis[m+1] != 10000000)
            printf("%d\n",dis[m+1]);
        else
            printf("impossivel\n");
    }
    return 0;
}
/*
4
portugues frances
ingles espanhol red
espanhol portugues amigo
frances ingles date
espanhol ingles actual
*/
