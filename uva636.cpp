#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
char in[10000];
int main (){
    int b,tmp,i,len,m;
    while(1){
        scanf("%s",in);
        len = strlen(in);
        if(strcmp(in,"0")==0)break;
        m = 0;
        for(i=0;i<len;i++){
            if(in[i]>m)m = in[i];
        }
        m-=48;
        b = m+1;
        while(1){
            tmp = 0;
            for(i=0;i<len;i++){
                tmp = tmp * b + in[i]-48;
            }
            if((int)(sqrt(tmp)+1e-5)*(int)(sqrt(tmp)+1e-5) == tmp){
                break;
            }
            b++;
        }
        printf("%d\n",b);
    }
    return 0;
}
