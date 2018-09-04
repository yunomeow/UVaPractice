#include<stdio.h>
#include<stdlib.h>
int matrix[105][105],val[105][105];
int main (){
    int i,n,m,j,k,tmp,ans;
    while(1){
        scanf("%d%d",&n,&m);
        if(n ==0 && m == 0)break;
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                scanf("%d",&matrix[i][j]);
            }
        }
        for(i=0;i<n;i++){
            tmp = 0;
            for(j=0;j<m;j++){
                if(matrix[i][j] == 1){
                    tmp = 0;
                    val[i][j] = 0;
                }else{
                    tmp++;
                    val[i][j] = tmp;
                }
            }
        }
        ans = 0;
        for(i=0;i<m;i++){
            for(j=i;j<m;j++){
                tmp = 0;
                for(k=0;k<n;k++){
                    if(val[k][j] >= j-i+1){
                        tmp += j-i+1;
                    //    printf("--%d\n",tmp);
                    }else
                        tmp = 0;
                    if(tmp > ans)ans = tmp;
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
