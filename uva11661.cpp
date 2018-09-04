#include<stdio.h>
#include<stdlib.h>
char s[2000005];
int main (){
    int i,lastD,lastR,dis,n;
    while(1){
        scanf("%d%*c",&n);
        if(n == 0)break;
        gets(s);
        lastD = -1;lastR = -1;
        dis = 2100000000;
        for(i=0;i<n;i++){
            if(s[i] == 'Z'){
                dis = 0;
                break;
            }
            if(s[i] == 'R' || s[i] == 'D'){
                if(s[i] == 'D'){
                        if(lastR != -1 && dis > i - lastR)
                            dis = i - lastR;
                        lastD = i;
                }
                if(s[i] == 'R'){
                        if(lastD != -1 && dis > i - lastD)
                            dis = i - lastD;
                        lastR = i;
                }
            }
        }
        printf("%d\n",dis);
    }
    return 0;
    
}
