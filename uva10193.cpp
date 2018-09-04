#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int gcd(int a,int b){
    while((a%=b) && (b%=a));
    return a+b;
}
int main (){
    int T,len,a,b,i,ca = 0;
    char s1[100],s2[100];
    scanf("%d%*c",&T);
    while(T--){
        scanf("%s%s",s1,s2);
        len = strlen(s1);
        a = 0;
        for(i=0;i<len;i++){
            a = a*2 + s1[i]-48;
        }
        len = strlen(s2);
        b = 0;
        for(i=0;i<len;i++){
            b = b*2 + s2[i]-48;
        }
        ca++;
        if(gcd(a,b) != 1)printf("Pair #%d: All you need is love!\n",ca);
        else printf("Pair #%d: Love is not all you need!\n",ca);
    }
    return 0;
}


