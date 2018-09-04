#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char stack[100];
int num(char a){
    switch(a){
        case '+':return 1; 
        case '-':return 1;
        case '*':return 2;
        case '/':return 2;
        case '(':return 0;
        case ')':return 0;                                        
    }
}
int main (){
    int T,top,flag = 0;
    char ch,s[10];
    scanf("%d%*c%*c",&T);
    while(T--){
        if(flag == 1)printf("\n");
        flag =1 ;
        top = -1;
        while(scanf("%c",&ch)!=EOF){
            if(ch == '\n')break;
            scanf("%*c");
            if(ch >= '0' && ch <='9')printf("%c",ch);
            else{
                if(ch == ')'){
                    while(top >= 0 && stack[top] != '('){
                        printf("%c",stack[top]);
                        top--;
                    }
                    top--;
                }else if (ch == '('){
                    top++;
                    stack[top] = ch;
                }else{
                    while(top >= 0 && num(stack[top]) >= num(ch)){
                        printf("%c",stack[top]);
                        top--;
                    }
                    top++;
                    stack[top] = ch;                    
                }
            }
        }
        while(top >= 0){
            if(stack[top]!= '(')
                printf("%c",stack[top]);
            top--;
        }
        printf("\n");
    }
    return 0;
}
