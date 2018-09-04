#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
char s[1000005],d[3];
int main (){
    int i,now,tmp,len,num,dir,x,ca=0;
    double nowx,nowy;
    while(1){
        gets(s);
        if(strcmp(s,"END") == 0)break;
        len = strlen(s);
        now = 0;
        nowx = 0;nowy = 0;
        while(now < len){
            sscanf(s+now,"%d%n",&num,&tmp);
            now += tmp;
            x = 0;
            while(s[now] != ',' && s[now] != '.'){
                d[x] = s[now];
                x++;
                now++;
            }
            now++;
            d[x] = '\0';
            if(strcmp("N",d)==0){
                nowy += num;
            }else if(strcmp("S",d) == 0){
                nowy -= num;                
            }else if(strcmp("E",d) == 0){
                nowx += num;                
            }else if(strcmp("W",d) == 0){
                nowx -= num;
            }else if(strcmp("NW",d) == 0){
                nowx -= sqrt(2)/2*num;
                nowy += sqrt(2)/2*num;
            }else if(strcmp("NE",d) == 0){
                nowx += sqrt(2)/2*num;
                nowy += sqrt(2)/2*num;
            }else if(strcmp("SW",d) == 0){
                nowx -= sqrt(2)/2*num;
                nowy -= sqrt(2)/2*num;
            }else if(strcmp("SE",d) == 0){
                nowx += sqrt(2)/2*num;
                nowy -= sqrt(2)/2*num;
            }                
        }
        ca++;
        printf("Map #%d\n",ca);
        printf("The treasure is located at (%.3lf,%.3lf).\n",nowx,nowy);
        printf("The distance to the treasure is %.3lf.\n\n",sqrt(nowx*nowx+nowy*nowy));
        
    }
    return 0;
}
