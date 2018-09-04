#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Card{
    int num;
    char color;
}data[14][4],now;
int top[15];
int number(char a){
    switch(a){
        case 'A':return 1;
        case '2':return 2;
        case '3':return 3;
        case '4':return 4;
        case '5':return 5;
        case '6':return 6;
        case '7':return 7;
        case '8':return 8;
        case '9':return 9;
        case 'T':return 10;
        case 'J':return 11;
        case 'Q':return 12;        
        case 'K':return 13;
    }
}
int main (){
    char s[10],ch[] ="0A23456789TJQK";
    int i,cnt,tmp;
    while(1){
        for(i=0;i<52;i++){
            scanf("%s",s);
            if(strcmp(s,"#") == 0)return 0;
            data[13-i%13][i/13].color = s[1];
            data[13-i%13][i/13].num = number(s[0]);
        }
        for(i=1;i<=13;i++)top[i] = 0;
        top[13] ++;
        cnt = 1;
        now.color = data[13][0].color;
        now.num = data[13][0].num;
        while(1){
           // printf("%d: %c %d\n",cnt,now.color,now.num);
            if(top[now.num] == 4)break;
            tmp = now.num;
            now.color = data[now.num][top[now.num]].color;
            now.num = data[now.num][top[now.num]].num;
            top[tmp]++;
            cnt++;
        }
        printf("%02d,%c%c\n",cnt,ch[now.num],now.color);
    }
    return 0;
}

