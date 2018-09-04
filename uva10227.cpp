#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#include<iostream>
using namespace std;
struct skyly{
    int num[102];
    int len;
}data[105];
int peo[105][105];
int use[105][105];
int len[105];
bool cmp(skyly a,skyly b){
    if(a.len != b.len)return a.len < b.len;
    int i = 0;
    while(i < a.len && a.num[i] == b.num[i])i++;
    return a.num[i] < b.num[i];
}
int main (){
    int i,T,p,t,a,b,cnt,flag,j,first=1;
    char s[100];
    scanf("%d",&T);
    while(T--){
        if(first == 0)printf("\n");
        first = 0;
        scanf("%d%d%*c",&p,&t);
        memset(len,0,sizeof(len));
        memset(use,0,sizeof(use));
        for(i=0;i<101;i++){
            data[i].len = 0;
            for(j=0;j<101;j++)
                data[i].num[j] = 0;
        }
        while(gets(s)){
            if(strcmp(s,"") == 0)break;
            sscanf(s,"%d%d",&a,&b);
            if(use[a][b] == 0){
                peo[a][len[a]] = b;
                len[a]++;
                use[a][b] = 1;
            }
//            printf("a:%d b:%d\n",a,b);
        }
        data[0].len = 0;
        for(i=1;i<=p;i++)
            sort(peo[i],peo[i]+len[i]);
        for(i=1;i<=p;i++){
  //          printf("%d: ",i);
            for(j=0;j<len[i];j++){
                data[i].num[j] = peo[i][j];
    //            printf("%d ",peo[i][j]);
            }
      //      printf("\n");
            data[i].len = len[i];
        }
        sort(data+1,data+p+1,cmp);
        cnt = 1;
        for(i=2;i<=p;i++){
            
            if(data[i].len != data[i-1].len)cnt++;
            else{
                flag = 0;
                for(j=0;j<data[i].len;j++){
                    if(data[i].num[j] != data[i-1].num[j]){
                        flag =1;
                        break;
                    }
                }
                if(flag == 1)cnt++;
            }
        }
        if(p == 0)cnt = 0;
        printf("%d\n",cnt);
    }
}
