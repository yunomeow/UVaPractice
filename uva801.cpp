#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
double table[105][105];
int from[105][105];
int path[105];
int ABS(int a){
    if(a < 0)return -1*a;
    return a;
}
int main (){
    int T,ca = 0,i,j,k,pos,n,now,x;
    double f,tmp,tmp2,ans,w,wu,wd,dis;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        memset(table,0,sizeof(table));
        for(i=0;i<n;i++){
            scanf("%lf%lf%lf",&dis,&wd,&wu);
            if(i==0){
                for(j=20;j<=40;j++){
                    w = wu*((j-20)/20.0) + wd * ((40-j)/20.0);
                    f = (2000+ABS(j-30)*10) *(dis/(400.0+w));
                    f += 50*(j);
                    table[i][j] = f;
                }
            }else{
                for(j=20;j<=40;j++){
                    tmp = 1e15;
                    w = wu*((j-20)/20.0) + wd * ((40-j)/20.0);
                    f = (2000+ABS(j-30)*10) *(dis/(400.0+w));
                    
                    for(k=20;k<=40;k++){
                        tmp2 = f + table[i-1][k];
                        if(j>k){
                            tmp2 += (j-k)*50;
                        }
                        if(tmp2 < tmp){
                            tmp = tmp2;
                            pos = k;
                        }
                    }
                    
                    table[i][j] = tmp;
                    from[i][j] = pos;
                }
            }
        }
        ans = 1e15;
        for(i=20;i<=40;i++){
            if(ans > table[n-1][i]){
                ans = table[n-1][i];
                now = i;
            }
        }
        path[n-1] = now;
        for(i=n-2;i>=0;i--){
            path[i] = from[i+1][now];
            now = path[i];
        }
        ca++;
        
        printf("Flight %d:",ca);
        for(i=0;i<=n-1;i++){
            printf(" %d",path[i]);
        }
        printf(" %.0lf\n",ceil(ans));
        
    }
    return 0;
}
