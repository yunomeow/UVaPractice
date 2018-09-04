#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int vis[55];
long long dis[55];
int matrix[55][55];
int num(char ch){
    if(ch >= 'A' && ch <= 'Z')return ch-65;
    return ch-97+26;
}
int par[55];
int main(){
    int i,n,t,st,ed,pos,now,j,ca=0;
    long long MIN;
    char c1,c2;
    while(1){
        scanf("%d%*c",&n);
        if(n == -1)break;    
        memset(vis,0,sizeof(vis));
        memset(matrix,0,sizeof(matrix));
        for(i=0;i<n;i++){
            scanf("%c%*c%c%*c",&c1,&c2);
            matrix[num(c1)][num(c2)] = 1;
            matrix[num(c2)][num(c1)] = 1;            
        }
        scanf("%d%*c%c%*c%c",&t,&c1,&c2);
        st = num(c2);
        ed = num(c1);
        for(i=0;i<54;i++)dis[i] = 1000000000000000000ll;
        dis[st] = t;
        for(i=0;i<52;i++){
            pos = -1;
            MIN = 1000000000000000000ll;
            for(j=0;j<52;j++){
                if(dis[j] < MIN && vis[j] == 0){
                    MIN = dis[j];
                    pos = j;
                }
            }
            if(pos == -1)break;
            vis[pos] = 1;
            for(j=0;j<52;j++){
                if(pos < 26){
                    if(matrix[pos][j] > 0 && dis[j] > dis[pos] + ceil(dis[pos] / 19.0)){
                        dis[j] = dis[pos] + ceil(dis[pos] / 19.0);
                        par[j] =pos;
                    }
                }else{
                    if(matrix[pos][j] > 0 && dis[j] > dis[pos] + 1){
                        dis[j] = dis[pos] + 1;
                        par[j] = pos;
                    }
                }
            }
        }
        ca++;
        printf("Case %d:\n",ca);
        printf("%lld\n",dis[ed]);
        //for(i=26;i<52;i++)
          //  printf("%c: %d\n",i+97-26,dis[i]);
      
        now = ed;
        while(now != st){
            if(now < 26)
                printf("%c-",now + 65);
            else
                printf("%c-",now + 97 - 26);
            now = par[now];
        }
            if(now < 26)
                printf("%c",st + 65);
            else
                printf("%c",st + 97 - 26);        
        printf("\n");
    }
    return 0;
}
/*
1
a Z
19 a Z
5
A D
D X
A b
b c
c X
39 A X
-1
*/
