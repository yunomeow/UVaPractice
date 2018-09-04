#include<stdio.h>
#include<stdlib.h>
int main (){
    int low,high,i,n,T,ca = 0,last,tmp;
    scanf("%d",&T);
    while(T--){
        ca++;
        scanf("%d",&n);
        printf("Case %d: ",ca);
        low = 0; high = 0;
        scanf("%d",&last);
        for(i=1;i<n;i++){
            scanf("%d",&tmp);
            if(tmp > last)high++;
            if(tmp < last)low++;
            last = tmp;
        }
        printf("%d %d\n",high,low);
    }
    return 0;
}
