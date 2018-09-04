#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char s[100];
inline int change(char ch){
    if(ch == 'A')return 2;
    if(ch == 'B')return 2;    
    if(ch == 'C')return 2;
    if(ch == 'D')return 3;
    if(ch == 'E')return 3;
    if(ch == 'F')return 3;
    if(ch == 'G')return 4;
    if(ch == 'H')return 4;
    if(ch == 'I')return 4;
    if(ch == 'J')return 5;
    if(ch == 'K')return 5;
    if(ch == 'L')return 5;
    if(ch == 'M')return 6;
    if(ch == 'N')return 6;
    if(ch == 'O')return 6;           
    if(ch == 'P')return 7;
    if(ch == 'Q')return 7;
    if(ch == 'R')return 7;
    if(ch == 'S')return 7;
    if(ch == 'T')return 8;
    if(ch == 'U')return 8;
    if(ch == 'V')return 8;
    if(ch == 'W')return 9;
    if(ch == 'X')return 9;
    if(ch == 'Y')return 9;
    if(ch == 'Z')return 9;                
}
int main (){
    int i,len;
    while(gets(s)){
        len = strlen(s);
        for(i=0;i<len;i++){
            if(s[i] <= 'Z' && s[i] >= 'A'){
                s[i] = change(s[i]) + 48;
            }
        }
        printf("%s\n",s);
    }
}
