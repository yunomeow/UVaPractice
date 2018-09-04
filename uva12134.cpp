#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char in[1005],out[1005];
int ok[100];
int change(char ch){
    if(ch >= '0' && ch <= '9')return ch - '0';
    if(ch >= 'A' && ch <= 'Z')return ch - 'A' + 10;
    if(ch >= 'a' && ch <= 'z')return ch - 'a' + 36;
}
char getCh(int k){
    if(k < 10)return k+'0';
    else if(k >= 10 && k < 36)return k - 10 + 'A';
    else if(k >= 36 && k < 62)return k - 36 + 'a';
}
int main (){
    int n,len1,len2,i,ca=0;
    int flag,pos,j;
    //freopen("in.txt","r",stdin);
    while(1){
        scanf("%d",&n);
        if(n == 0)break;
        flag = 1;
        memset(ok,-1,sizeof(ok));
        //printf("n = %d\n",n);
        for(i=0;i<n;i++){
            scanf("%s%s",in,out);
            len1 = strlen(in);
            len2 = strlen(out);
            if(len1 < len2){
                flag = 0;
            }else{
                for(j=1;j<len2-1;j++){
                    if(in[j] != out[j]){
                        flag = 0;
                    }else{
                        if(ok[change(in[j])] == -1){
                            ok[change(in[j])] = 1;
                        }else if(ok[change(in[j])] == 0){
                            flag = 0;
                        }
                    }
                }
                if(len1 > len2){
                    //printf("okend: %c\n",in[len2-1]);
                    if(ok[change(in[len2-1])]  == -1)
                        ok[change(in[len2-1])] = 0;
                    else if(ok[change(in[len2-1])] == 1){
                        flag = 0;
                    }
                }
            }
        }
        //for(i=0;i<10;i++)
        //printf("%d\n",ok[i]);
        ca++;
        printf("Case %d: ",ca);
        if(flag == 1){
            pos = -1;
            for(i=61;i>=0;i--)if(ok[i] == 1)break;
            pos = i;
            //printf("pos %d\n",pos);
            if(pos == -1){
                for(i=0;i<62;i++){
                    if(ok[i] == -1){
                        printf("[%c]\n",getCh(i));
                        pos = i;
                        break;
                    }
                }
                if(pos == -1)printf("I_AM_UNDONE\n");
            }else{
                printf("[");
                for(i=0;i<=pos;i++){
                    if(ok[i] != 0){
                        printf("%c",getCh(i));
                    }
                }
                printf("]\n");
            }

        }else{
            printf("I_AM_UNDONE\n");
        }
    }
    return 0;
}
/*
5
"11" "11"
"243" "24"
"563" "56"
"784" "784"
"789" "78"
1
"A" "b"
0
*/
