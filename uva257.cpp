#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char s[260],tmp[260];
char pali[50000][256];
int palinum[50000][2];
int main (){
    int i,j,cnt,len,flag,x,ispali,flag2,k,l;
    while(scanf("%s",s)!=EOF){
      //  printf("%s\n",s);
        len = strlen(s);
        x = 0;cnt = 0;
        for(i=3;i<=4;i++){
            for(j=0;j<len;j++){
                if(i+j-1 < len){
                    ispali = 1;
                    for(k=j,l=j+i-1;k<l;k++,l--){
                        //printf("%d %d\n",k,j+i);
                        if(s[k] != s[l]){ispali = 0;break;}
                    }
                    if(ispali == 1){
                        flag = 1;
                        for(k=j,l=0;k<=j+i-1;k++,l++){
                            tmp[l] = s[k];
                        }
                        tmp[l] = '\0';
                        for(k=0;k<x;k++){
                            if(strcmp(tmp,pali[k]) == 0){
                                flag =  0;
                                break;
                            }
                        }
                        if(i == 4 && (tmp[0] == tmp[2] || tmp[1] == tmp[3]))
                            flag = 0;
                        strcpy(pali[x],tmp);
                        x++;                        
                        if(flag == 1){
                            cnt++;
                        }
                        if(cnt > 1)break;
                    }
                   // system("pause");                    
                }
            }
            if(cnt > 1)break;
        }
        if(cnt > 1)printf("%s\n",s);
      //  for(i=0;i<x;i++)
        //    printf("%s--\n",pali[i]);
    }
    return 0;
}
