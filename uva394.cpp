#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct ARRAY{
    int L[15];
    int U[15];
    int B;
    int C;
    int D;
    int c[15];
    char name[20];
}data[100000];
int c[20];
int main (){
    char str[20];
    int I[20];
    int i,n,q,j,ans,tmp,num;
    scanf("%d%d%*c",&n,&q);
    for(i=0;i<n;i++){
        scanf("%s%d%d%d",data[i].name,&data[i].B,&data[i].C,&data[i].D);
        for(j=1;j<=data[i].D;j++){
            scanf("%d%d%*c",&data[i].L[j],&data[i].U[j]);
        }
        data[i].c[data[i].D] = data[i].C;
        for(j=data[i].D-1;j>0;j--)
            data[i].c[j] = data[i].c[j+1] * (data[i].U[j+1] - data[i].L[j+1] + 1);
        tmp = 0;
        for(j=1;j<=data[i].D;j++){
            tmp  += data[i].L[j] * data[i].c[j];
        }
        data[i].c[0] = data[i].B - tmp;
    }
    while(q--){
        scanf("%s",str);
        for(i=0;i<n;i++){
            if(strcmp(str,data[i].name) == 0)break;
        }
        ans = 0;
        for(j=1;j<=data[i].D;j++){
            scanf("%d",&I[j]);
            ans += I[j] * data[i].c[j];
        }
        ans += data[i].c[0];
        printf("%s[",str);
        for(j=1;j<=data[i].D;j++){
            if(j!=1)printf(", ");
            printf("%d",I[j]);
        }
        printf("] = %d\n",ans);
    }
}

