#include<stdio.h>
#include<stdlib.h>
int course[101];
int main (){
    int k,m,c,i,r,tmp,cnt,flag,j,a;
    while(1){
        flag = 1;
        scanf("%d",&k);
        if(k == 0)break;
        scanf("%d",&m);
        for(i=0;i<k;i++){
            scanf("%d",&course[i]);
        }
        for(i=0;i<m;i++){
            scanf("%d%d",&c,&r);
            cnt = 0;
            for(j=0;j<c;j++){
                scanf("%d",&tmp);
                for(a=0;a<k;a++)
                    if(tmp == course[a])
                        cnt++;
            }
            if(cnt < r)flag = 0;
        }
        if(flag == 1)printf("yes\n");
        else printf("no\n");
    }
    return 0;
}
