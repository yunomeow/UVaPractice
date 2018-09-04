#include<stdio.h>
#include<stdlib.h>
int ans[10005];
int main (){
    int T,n,i,j,MIN;
    for(i=1;i<=10000;i++){
        MIN = 10000;
        for(j=i;j>0;j--){
            if(i - j*j >=0 ){
                if(MIN > ans[i-j*j]+1)
                    MIN = ans[i-j*j]+1;
            }
        }
        ans[i] = MIN;
    }
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        printf("%d\n",ans[n]);
    } 
    return 0;
}
