#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char input[1000];
int month[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int main (){
    int i,T;
    int m,d,y;
    int leap,ca=0;
    scanf("%d",&T);
    while(T--){
        scanf("%s",input);
        d = (input[2]-48)*10 + (input[3]-48);
        m = (input[0]-48)*10 + (input[1]-48);
        y = (input[4]-48)*1000 + (input[5]-48)*100 + (input[6]-48)*10 + (input[7]-48);
        for(i=0;i<280;i++){
            d++;
            if(y % 4 == 0 && (y % 100 != 0 || y % 400 == 0))leap = 1;
            else leap = 0;
            if(m == 2 && d == 29 && leap == 1){
                //printf("%d %d/%d/%d \n",ca,m,d,y);
                continue;
            }
            if(d > month[m]){
                d = 1;
                m++;
            }
            if(m > 12){
                m = 1;
                y++;
            }
            //printf("%d %d/%d/%d \n",ca,m,d,y);
        }
        ca++;
        printf("%d %02d/%02d/%04d ",ca,m,d,y);
        if((m == 1 && d >= 21) || (m == 2 && d <= 19))printf("aquarius\n");
        if((m == 2 && d >= 20) || (m == 3 && d <= 20))printf("pisces\n");
        if((m == 3 && d >= 21) || (m == 4 && d <= 20))printf("aries\n");
        if((m == 4 && d >= 21) || (m == 5 && d <= 21))printf("taurus\n");
        if((m == 5 && d >= 22) || (m == 6 && d <= 21))printf("gemini\n");
        if((m == 6 && d >= 22) || (m == 7 && d <= 22))printf("cancer\n");
        if((m == 7 && d >= 23) || (m == 8 && d <= 21))printf("leo\n");
        if((m == 8 && d >= 22) || (m == 9 && d <= 23))printf("virgo\n");
        if((m == 9 && d >= 24) || (m == 10 && d <= 23))printf("libra\n");
        if((m == 10 && d >= 24) || (m == 11 && d <= 22))printf("scorpio\n");
        if((m == 11 && d >= 23) || (m == 12 && d <= 22))printf("sagittarius\n");
        if((m == 12 && d >= 23) || (m == 1 && d <= 20))printf("capricorn\n");        
    }
    return 0;
}
/*
2 
01232009 
11222008
Aquarius 	January, 21 	February, 19
Pisces 	February, 20 	March, 20
Aries 	March, 21 	April, 20
Taurus 	April, 21 	May, 21
Gemini 	May, 22 	June, 21
Cancer 	June, 22 	July, 22
Leo 	July, 23 	August, 21
Virgo 	August, 22 	September, 23
Libra 	September, 24 	October, 23
Scorpio 	October, 24 	November, 22
Sagittarius 	November, 23 	December, 22
Capricorn 	December, 23 	January, 20 
*/
