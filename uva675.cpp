#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
struct point{
       int x;
       int y;
       }c[100006],old[1000];
int cross(point o,point a,point b){
        double i;
        i=((double)a.x-o.x)*((double)b.y-a.y)-((double)a.y-o.y)*((double)b.x-a.x);
        if(i<0) return -1;
        else{
            if(i==0)return 0;
            else return 1;
        }
}
bool cmp(point a,point b){
     if(a.x==b.x)
       return a.y<b.y;
     else
       return a.x<b.x;
}
point tmp[200005];
int main ()
{
    char s[100],*ss;
    int n,m,t,i,T,end = 1,flag=0,cnt,j;
    while(end){
        n = 0;
        if(flag == 1)printf("\n");
        flag = 1;
        while(1){
            ss = gets(s);
            if(ss == NULL)end = 0;
            if(ss == NULL || strcmp(s,"") == 0)break;
            sscanf(s,"%d%*c%d",&c[n].x,&c[n].y);
            old[n].x = c[n].x;
            old[n].y = c[n].y;
            n++;
        }
        sort(c,c+n,cmp);
        m=0;
        for(i=0;i<n;i++){
          tmp[m].x=c[i].x;
          tmp[m].y=c[i].y;
          while(m>=2&&cross(tmp[m-2],tmp[m-1],tmp[m])<=0){
            m--;
            tmp[m].x=c[i].x;
            tmp[m].y=c[i].y;}
          m++;
        }
        t=m+1;
        for(i=n-2;i>=0;i--){
          tmp[m].x=c[i].x;
          tmp[m].y=c[i].y;
          while(m>=t&&cross(tmp[m-2],tmp[m-1],tmp[m])<=0){
            m--;
            tmp[m].x=c[i].x;
            tmp[m].y=c[i].y;
            }
          m++;
        }
        cnt = 0;
        int ff = 1;
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                if(old[i].x == tmp[j].x && old[i].y == tmp[j].y){
                  //  
                    i = j;
                    ff = 0;
                    break;
                }
            }
            if(ff == 0)break;
        }
      //  printf("%d %d---\n",old[i].x,old[i].y);
        while(cnt < m){
            cnt++;
            printf("%d, %d\n",tmp[i].x,tmp[i].y);
            i++;
            if(i == m-1)i = 0;
        }
    }
	return 0;
}
