#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct skyly{
    int num;
    char s[100];
}data[10005];
char s[1005],name[1000][105];
int array[100000];
int main (){
    int i,T,n,flag = 0,j,tmp,x,use,k;
    scanf("%d",&T);
    while(T--){
        scanf("%d%*c",&n);
        for(i=0;i<n;i++){
            gets(data[i].s);
        }
        for(i=0;i<n;i++){
            gets(s);
            for(j=0;j<n;j++){
                if(strcmp(data[j].s,s) == 0){
                    strcpy(name[i],s);
                    data[j].num = i;
                    array[j] = i;
                    break;
                }
            }
        }
       // for(i=0;i<n;i++)
        //    printf("%d ",array[i]);
       // printf("\n");
        tmp = -1;
        for(i=n-1;i>=0;i--){
            for(j=i;j>=0;j--){
                if(array[j] >  array[i] && array[i] > tmp)
                    tmp = array[i];
            }
        }
        for(i = tmp;i>=0;i--){
            printf("%s\n",name[i]);
        }
        printf("\n");
    }
    return 0;
}
