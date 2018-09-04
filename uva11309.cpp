#include<stdio.h>
#include<stdlib.h>
int main (){
    int T,i,j,a,b,flag;
    char s[10];
    scanf("%d",&T);
    while(T--){
        scanf("%s",s);
        a = (s[0]-48)*10 + (s[1]-48);
        b = (s[3]-48)*10 + (s[4]-48);
        flag = 0;
        for(i=a;i<=23;i++){
            if(i == a)j = b+1;
            else j = 0;
            for(;j<60;j++){
                if(i == 0){
                    if(j < 10){
                        printf("00:%02d\n",j);
                        flag = 1;
                    }
                    else{
                        if(j%10 == j/10){
                            printf("00:%02d\n",j);
                            flag = 1;
                        }
                    }
                }else{
                    if(i < 10){
                        if(j%10 == i%10){
                            printf("%02d:%02d\n",i,j);
                            flag = 1;
                        }
                    }else{
                        if(j%10 == i/10 && j/10 == i %10){
                            printf("%02d:%02d\n",i,j);
                            flag = 1;
                        }
                    }
                }
                if(flag == 1)break;
            }
            if(flag == 1)break;
        }
        if(flag == 0)printf("00:00\n");
    }
    return 0;
}
