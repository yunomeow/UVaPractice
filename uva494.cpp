#include<stdio.h>

int main(){
    int state=0, count=0;

    while(1){//�ܦh��
        count =0;
    while(1){//�C�@��
        char ch = getchar();
        if(ch==EOF) return 0;//Ū����F
        if(state==0){
            if(ch=='\n')break;
                else if((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z')){
                count = count +1;
                state=1;
                }
                else
                state =0;
            }
            else{//state==1
                if(ch=='\n')break;
                else if((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z'))
                state=1;
                else
                state =0;
            }
        }
        state = 0;
        printf("%d\n",count);
    }
    return 0;
}
