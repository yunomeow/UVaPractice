#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
char MAP[105][105];
char input[10005],word[10005];
char test[10005];
int main (){
    int i,len,x,j,k;
    int T,sq,ca=0,flag;
    scanf("%d%*c",&T);
    while(T--){
        gets(input);
        len = strlen(input);
        x = 0;
        for(i=0;i<len;i++){
            if(input[i] >= 'a' && input[i] <= 'z'){
                word[x] = input[i];
                x++;
            }
        }
        word[x] = '\0';
        //printf("word %s\n",word);
        sq =(int)(sqrt(x)+1e-8);
        ca++;
        printf("Case #%d:\n",ca);
        if(sq * sq == x){
            k = 0;
            flag = 1;
            for(i=0;i<sq;i++){
                for(j=0;j<sq;j++){
                    MAP[i][j] = word[k];
                    k++;
                }
            }

            k = 0;
            for(j=0;j<sq;j++){
                for(i=0;i<sq;i++){
                    test[k] = MAP[i][j];
                    k++;
                }
            }
            test[k] = '\0';
            if(strcmp(test,word) != 0)flag = 0;
            k = 0;
            for(i=sq-1;i>=0;i--){
                for(j=sq-1;j>=0;j--){
                    test[k] = MAP[i][j];
                    k++;
                }
            }
            test[k] = '\0';
            if(strcmp(test,word) != 0)flag = 0;
            k = 0;
            for(j=sq-1;j>=0;j--){
                for(i=sq-1;i>=0;i--){
                    test[k] = MAP[i][j];
                    k++;
                }
            }
            test[k] = '\0';
            if(strcmp(test,word) != 0)flag = 0;
            if(flag == 1)printf("%d\n",sq);
            else printf("No magic :(\n");
        }else printf("No magic :(\n");
    }
    return 0;
}

/*
3
sator arepo tenet opera rotas
this sentence is, quite clearly, not a magic square palindrome! but then again, you never know...
muse sun, eve.s e(y)es even use sum.
*/
