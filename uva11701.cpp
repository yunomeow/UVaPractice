#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int main (){
    char s[10000];
    double n;
    int tmp,sum,flag;
    while(1){
        gets(s);
        if(strcmp(s,"END")==0)break;
        sscanf(s,"%lf",&n);
        while(n-(int)n > 0)n*=10;
        tmp = (int)n;
//        printf("tmp %d %lf\n",tmp,n);
        flag = 1;
        while(tmp > 0){
            if(tmp % 3 == 1){flag = 0;break;}
            tmp /= 3;
            printf("%d\n",tmp);
        }
        if(tmp == 1)flag =1;
        if(flag == 0)printf("NON-MEMBER\n");
        else printf("MEMBER\n");
    }
    return 0;
}
