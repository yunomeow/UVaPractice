#include<stdio.h>
#include<stdlib.h>
int use[20000006];
int ans[1000006][2];
int main(){
    int i,j,n,x = 0;
    for(i=2;i<20000001;i++){
        if(use[i] == 0){
            for(j=i+i;j<20000001;j+=i){
                use[j] = 1;
            }
        }
    }
    for(i=2;i<20000000;i++){
        if(use[i] == 0 && use[i+2] == 0 ){
            ans[x][0] = i;
            ans[x][1] = i+2;
            x++;
        }
    }
    while(scanf("%d",&n)!=EOF){
        printf("(%d, %d)\n",ans[n-1][0],ans[n-1][1]);
    }
    return 0;
}
