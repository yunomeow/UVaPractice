#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct shik{
    char s1[100];
    char s2[100];
}data[1000];
char tmp[1000];
int main (){
    int n,m,i,j,flag,len;
    scanf("%d%d%*c",&n,&m);
    for(i=0;i<n;i++){
        scanf("%s%s",data[i].s1,data[i].s2);
    }
    for(i=0;i<m;i++){
        scanf("%s",tmp);
        flag = 1;
        len = strlen(tmp);
        for(j=0;j<n;j++){
            if(strcmp(data[j].s1,tmp) == 0){
                printf("%s\n",data[j].s2);
                flag = 0;
                break;
            }
        }
        if(flag == 1){
            if(len >= 2 && (tmp[len-2] != 'a' && tmp[len-2] != 'o' && tmp[len-2] != 'e' &&tmp[len-2] != 'i' &&
            tmp[len-2] != 'u') && tmp[len - 1] == 'y'){
                for(j=0;j<len-1;j++)
                    printf("%c",tmp[j]);
                printf("ies\n");
            }else if((tmp[len-1] == 'o' || tmp[len-1] == 's' || tmp[len-1] == 'x' || (tmp[len-2]=='c' && tmp[len-1]=='h')
            || (tmp[len-2]=='s' && tmp[len-1]=='h'))){
                printf("%ses\n",tmp);
            
            }else{
                printf("%ss\n",tmp);
            }
        }
    }
  //  system("pause");
    return 0;
}
