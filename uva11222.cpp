#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
int num1[10005],num2[10005],num3[10005],use1[10005],use2[10005],use3[10005];
int m(int a,int b,int c){
    if(a >= b && a >= c)return a;
    if(b >= a && b >= c)return b;
    if(c >= a && c >= b)return c;        
}
int main (){
    int n,i,j,T,a,b,c,cnta,cntb,cntc,MAX,ca=0,flag;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&a);
        for(i=0;i<a;i++)scanf("%d",&num1[i]);
        scanf("%d",&b);
        for(i=0;i<b;i++)scanf("%d",&num2[i]);
        scanf("%d",&c);
        for(i=0;i<c;i++)scanf("%d",&num3[i]);
        sort(num1,num1+a);
        sort(num2,num2+b);        
        sort(num3,num3+c);        
        memset(use1,0,sizeof(use1));
        memset(use2,0,sizeof(use2));
        memset(use3,0,sizeof(use3));               
        for(i=0;i<a;i++){
            flag = 0;
            for(j=0;j<b;j++){
                if(flag == 1)break;
                if(num1[i] == num2[j]){
                    flag = 1;
                    use1[i] = 1;
                } 
            }
            for(j=0;j<c;j++){
                if(flag == 1)break;
                if(num1[i] == num3[j]){
                    flag = 1;
                    use1[i] = 1;
                }
            }
        }

        for(i=0;i<b;i++){
            flag = 0;
            for(j=0;j<a;j++){
                if(flag == 1)break;
                if(num1[i] == num2[j]){
                    flag = 1;
                    use2[i] = 1;
                } 
            }
            for(j=0;j<c;j++){
                if(flag == 1)break;
                if(num2[i] == num3[j]){
                    flag = 1;
                    use2[i] = 1;
                }
            }
        }
        
        for(i=0;i<c;i++){
            flag = 0;
            for(j=0;j<b;j++){
                if(flag == 1)break;
                if(num3[i] == num2[j]){
                    flag = 1;
                    use3[i] = 1;
                } 
            }
            for(j=0;j<a;j++){
                if(flag == 1)break;
                if(num1[i] == num3[j]){
                    flag = 1;
                    use3[i] = 1;
                }
            }
        }        
        cnta = cntb = cntc = 0;
        for(i=0;i<a;i++){ 
            if(i > 0 && (num1[i] == num1[i-1]))continue;
            if(use1[i] == 0)cnta++;
        } 
        for(i=0;i<b;i++){
            if(i > 0 && (num2[i] == num2[i-1]))continue;
            if(use2[i] == 0)cntb++;
        }
        for(i=0;i<c;i++){
            if(i > 0 && (num3[i] == num3[i-1]))continue; 
            if(use3[i] == 0)cntc++;
        }
        MAX = m(cnta,cntb,cntc);
        ca++;
        printf("Case #%d:\n",ca);
        if(cnta == MAX){
            printf("1 %d",MAX);
            for(i=0;i<a;i++){
                if(i > 0 && (num1[i] == num1[i-1]))continue;
                if(use1[i] == 0)
                    printf(" %d",num1[i]);
            }
            printf("\n");
        }
        if(cntb == MAX){
            printf("2 %d",MAX);
            for(i=0;i<b;i++){
                if(i > 0 && (num2[i] == num2[i-1]))continue;                
                if(use2[i] == 0)
                    printf(" %d",num2[i]);
            }
            printf("\n");
        }
        if(cntc == MAX){
            printf("3 %d",MAX);
            for(i=0;i<c;i++){
                if(i > 0 && (num3[i] == num3[i-1]))continue;                            
                if(use3[i] == 0)
                    printf(" %d",num3[i]);
            }
            printf("\n");
        }        
    }
    return 0;
}
