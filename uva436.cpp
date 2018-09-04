#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char name[100][100];
int x;
double dis[100],mat[100][100];
int findname(char s[]){
    int i;
    for(i=0;i<x;i++){
        if(strcmp(name[i],s) == 0)return i;
    }
    strcpy(name[i],s);
    x++;
    return x-1;
}
int main (){
    int i,j,k,n,flag,ca=0,a,b,m,cnt,use;
    char in[100];
    double rate;
    while(1){
        scanf("%d",&n);
        if(n == 0)break;
        flag = 0;
        x = 0;
        ca++;
        memset(mat,0,sizeof(mat));
        memset(dis,0,sizeof(dis));
        for(i=0;i<n;i++){
            scanf("%s",in);
            findname(in);
        }
        scanf("%d",&m);
        for(i=0;i<m;i++){
            scanf("%s",in);
            a = findname(in);
            scanf("%lf",&rate);
            scanf("%s",in);
            b = findname(in);
            mat[a][b] = rate;
        }
        for(i=0;i<n;i++){
            memset(dis,0,sizeof(dis));
            dis[i] = 1;
            cnt = 0;
            while(cnt < n){
                use = 0;
                for(j=0;j<n;j++){
                    for(k=0;k<n;k++){
                        if(dis[k] < dis[j] * mat[j][k]){
                            dis[k] = dis[j] * mat[j][k];
                            //printf("change %d to %d %lf\n",j,k,dis[j] * mat[j][k]);
                            use = 1;
                        }
                    }
                }
                if(use == 0)break;
                cnt++;
            }
            //for(j=0;j<n;j++)printf("%.3lf ",dis[j]);
            //printf("\n");
            if(cnt == n){flag = 1;break;}
        }
        if(flag == 1)printf("Case %d: Yes\n",ca);
        else printf("Case %d: No\n",ca);
    }
    return 0;
}
