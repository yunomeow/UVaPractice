#include<stdio.h>
#include<stdlib.h>
int s[100][100];
int main (){
    int n,i,j,tmp,ca = 0,sum;
    while(1){
        scanf("%d",&n);
        if(n == 0)break;
        ca++;
        printf("Case %d:",ca);
        for(i=0;i<n;i++){
            for(j=0;j<n;j++)
                scanf("%d",&s[i][j]);
        }
        tmp = n;
        while(tmp > 0){
            sum = 0;
           // printf("aaa %d\n",(n-tmp)/2);
            for(i=(n-tmp)/2;i<((n-tmp)/2)+tmp;i++){
                sum += s[(n-tmp)/2][i];
                if((n-tmp)/2 != (n-tmp)/2+tmp-1)
                sum += s[(n-tmp)/2+tmp-1][i];
//                printf("add ( %d, %d)\n",(n-tmp)/2,i);
//                printf("add ( %d, %d)\n",(n-tmp)/2+tmp,i);
            }
            for(i=(n-tmp)/2+1;i<((n-tmp)/2)+tmp-1;i++){
                sum += s[i][(n-tmp)/2];
                if((n-tmp)/2 != (n-tmp)/2+tmp-1)                
                sum += s[i][(n-tmp)/2+tmp-1];
//                printf("add ( %d, %d)\n",i,(n-tmp)/2);
//                printf("add ( %d, %d)\n",i,(n-tmp)/2+tmp-1);
            }
            printf(" %d",sum);
            tmp -= 2;
     
        }
        printf("\n");
    }
    return 0;
} /*
5
5 3 2 7 9
1 7 4 2 4
5 3 2 4 6
1 3 4 5 1
1 4 5 6 3
*/
