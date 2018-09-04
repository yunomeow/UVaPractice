#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char in[10000];
int num[1000];
int main (){
    int ans,cnt;
    int i,score,k,n,len;
    int ball,c;
    while(1){
        gets(in);
        if(strcmp(in,"Game Over") == 0)break;
        k = 0;
        ball = 0;
        len = strlen(in);
        ans = 0;
        for(i=0;i<len;i++){
            if(in[i] == ' ')continue;
            if(in[i] == 'X')score = 10;
            else if(in[i] == '/')score = 10 - num[k-1];
            else score = in[i] - 48;
            num[k] = score;
            ans += score;
            k++;
        }
        n = k;
        //printf("ans %d\n",ans);
        k = 0;
        c = 0;
        ball = 0;
        for(i=0;i<len;i++){
            if(in[i] == ' ')continue;
            if(in[i] == 'X' && ball < 9)ans += num[k+1]+num[k+2];
            else if(in[i] == '/' && ball < 9)ans += num[k+1];
            if(in[i] == '/'){c = 0;ball++;}
            else if(in[i] >= '0'  && in[i] <= '9')c++;
            else{ c = 0;ball++; }
            if(c == 2){ball++;c = 0;}
            k++;
        }
        printf("%d\n",ans);
    }
    return 0;
}
/*
1 0 1 / 2 2 X 3 3 X 1 / 3 / X 1 2
1 0 1 / 2 2 X 3 3 X 1 / 3 / 1 / X 8 0
1 0 1 / 2 2 X 3 3 X 1 / 3 / 1 / 8 / 9
X X X X X X X X X X X X
Game Over
*/
