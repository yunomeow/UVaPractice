#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main (){
    int T,tmp,now,len,flag = 0,x,ca = 0;
    char s[10000],ss[1000];
    scanf("%d%*c",&T);
    while(T--){
        if(flag == 1)printf("\n");
        flag = 1;
        ca++;
        printf("Message #%d\n",ca);
        gets(s);
        now = 0;
        len = strlen(s);
        while(now < len){
            x = 0;
            while(s[now] != ' '){
                ss[x] = s[now];
                x++;
                now++;
            }
            now++;

            ss[x] = '\0';
            if(strcmp(".-",ss) == 0)printf("A");
            else if(strcmp("-...",ss) == 0)printf("B");
            else if(strcmp("-.-.",ss) == 0)printf("C");
            else if(strcmp("-..",ss) == 0)printf("D");
            else if(strcmp(".",ss) == 0)printf("E");
            else if(strcmp("..-.",ss) == 0)printf("F");
            else if(strcmp("--.",ss) == 0)printf("G");
            else if(strcmp("....",ss) == 0)printf("H");
            else if(strcmp("..",ss) == 0)printf("I");
            else if(strcmp(".---",ss) == 0)printf("J");
            else if(strcmp("-.-",ss) == 0)printf("K");
            else if(strcmp(".-..",ss) == 0)printf("L");
            else if(strcmp("--",ss) == 0)printf("M");
            else if(strcmp("-.",ss) == 0)printf("N");
            else if(strcmp("---",ss) == 0)printf("O");
            else if(strcmp(".--.",ss) == 0)printf("P");
            else if(strcmp("--.-",ss) == 0)printf("Q");
            else if(strcmp(".-.",ss) == 0)printf("R");
            else if(strcmp("...",ss) == 0)printf("S");
            else if(strcmp("-",ss) == 0)printf("T");
            else if(strcmp("..-",ss) == 0)printf("U");
            else if(strcmp("...-",ss) == 0)printf("V");
            else if(strcmp(".--",ss) == 0)printf("W");
            else if(strcmp("-..-",ss) == 0)printf("X");
            else if(strcmp("-.--",ss) == 0)printf("Y");
            else if(strcmp("--..",ss) == 0)printf("Z");
            else if(strcmp("-----",ss) == 0)printf("0");
            else if(strcmp(".----",ss) == 0)printf("1");
            else if(strcmp("..---",ss) == 0)printf("2");
            else if(strcmp("...--",ss) == 0)printf("3");
            else if(strcmp("....-",ss) == 0)printf("4");
            else if(strcmp(".....",ss) == 0)printf("5");
            else if(strcmp("-....",ss) == 0)printf("6");
            else if(strcmp("--...",ss) == 0)printf("7");
            else if(strcmp("---..",ss) == 0)printf("8");
            else if(strcmp("----.",ss) == 0)printf("9");
            else if(strcmp(".-.-.-",ss) == 0)printf(".");
            else if(strcmp("--..--",ss) == 0)printf(",");
            else if(strcmp("..--..",ss) == 0)printf("?");
            else if(strcmp(".----.",ss) == 0)printf("'");
            else if(strcmp("-.-.--",ss) == 0)printf("!");
            else if(strcmp("-..-.",ss) == 0)printf("/");
            else if(strcmp("-.--.",ss) == 0)printf("(");
            else if(strcmp("-.--.-",ss) == 0)printf(")");
            else if(strcmp(".-...",ss) == 0)printf("&");
            else if(strcmp("---...",ss) == 0)printf(":");
            else if(strcmp("-.-.-.",ss) == 0)printf(";");
            else if(strcmp("-...-",ss) == 0)printf("=");
            else if(strcmp(".-.-.",ss) == 0)printf("+");
            else if(strcmp("-....-",ss) == 0)printf("-");
            else if(strcmp("..--.-",ss) == 0)printf("_");
            else if(strcmp(".-..-.",ss) == 0)printf("\"");
            else if(strcmp(".--.-.",ss) == 0)printf("@");            

            if(s[now] == ' '&&now < len){
                printf(" ");
                now++;
                continue;
            }            
        }
        printf("\n");
    }
    
    return 0;
}
