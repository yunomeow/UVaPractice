#include<stdio.h>
#include<stdlib.h>
int state[60],nowstate[60],input[60],stack[8][60],top[8];
int oldstate[100000][60],step;
int cmp(){
    int i,j,flag;
    for(i=0;i<step;i++){
        flag = 1;
        for(j=0;j<60;j++){
            if(oldstate[i][j] != state[j]){
                flag = 0;
                break;
            }
        }
        if(flag == 1)return 1;
    }
    return 0;
}
void make_state(){
    int i,j,k=0;
    for(i=0;i<8;i++){
        for(j=0;j<top[i];j++){
            state[k] = stack[i][j];
            k++;
        }
    }
    for(i=0;i<8;i++){
        state[k] = top[i];
        k++;
    }
    for(i=0;i<60;i++)
        oldstate[step][i] = state[i];
//    printf("k = %d\n",k);
}
void init(){
    int i;
    for(i=0;i<8;i++)top[i] = -1;
    top[0] = 52;
    for(i=51;i>=0;i--)
        stack[0][i] = input[i];
}
void printstate(){
    int i,p,now;
    p = 0;now = 0;
    printf("Stack %d: ",p);
    for(i=0;i<52;i++){
        if(now == top[p]){
            now = 0;
            p++;
            printf("\nStack %d: ",p);
        }
        printf("%d ",stack[p][now]);
        now++;
    }
}
void check(int pile){
    int sum,flag,i;
    top[0]--;
    
    if(top[pile] == -1)
        top[pile] = 1;
    else top[pile]++;
    stack[pile][top[pile]-1] = stack[0][top[0]];
    //case 1,2,3
    flag = 1;
    while(flag == 1){
        flag = 0;
        if(top[pile] >= 3){
            sum = stack[pile][0] + stack[pile][1] + stack[pile][top[pile]-1]; //first 2 last 1
          //  printf("stope\n");
            if(sum == 10 || sum == 20 || sum == 30){
                //塞進去 
                for(i=top[0]-1;i>=0;i--){
                    stack[0][i+3] = stack[0][i];
                }
                stack[0][0] = stack[pile][top[pile] - 1];
                stack[0][1] = stack[pile][1];
                stack[0][2] = stack[pile][0];
                for(i=0;i<top[pile];i++){
                    stack[pile][i] = stack[pile][i+2];
                }
                top[0] += 3;
                top[pile] -= 3;
                flag = 1;
                
                continue;
            }
            sum = stack[pile][0] + stack[pile][top[pile]-2] + stack[pile][top[pile]-1]; //first 1 last 2
            if(sum == 10 || sum == 20 || sum == 30){
                //塞進去 
                for(i=top[0]-1;i>=0;i--){
                    stack[0][i+3] = stack[0][i];
                }
                stack[0][0] = stack[pile][top[pile] - 1];
                stack[0][1] = stack[pile][top[pile] - 2] ;
                stack[0][2] = stack[pile][0];
                for(i=0;i<top[pile];i++){
                    stack[pile][i] = stack[pile][i+1];
                }                
                top[0] += 3;
                top[pile] -= 3;
                flag = 1;
                continue;
            }
            sum = stack[pile][top[pile]-3] + stack[pile][top[pile]-2] + stack[pile][top[pile]-1];
            if(sum == 10 || sum == 20 || sum == 30){
                //塞進去 
                for(i=top[0]-1;i>=0;i--){
                    stack[0][i+3] = stack[0][i];
                }
                stack[0][0] = stack[pile][top[pile] - 1];
                stack[0][1] = stack[pile][top[pile] - 2];
                stack[0][2] = stack[pile][top[pile] - 3];
                top[0] += 3;
                top[pile] -= 3;
                flag = 1;
                continue;
            }
        }
    }
    make_state();
  // printstate();
}
int main (){
    int i,now,flag;
    while(1){
        for(i=51;i>=0;i--){
            scanf("%d",&input[i]);
            if(input[i] == 0)return 0;
        }
        init();
        now = 1;step = 0;
        while(1){
            check(now);
            now++;
            if(now > 7)now = 1;
            if(top[0] == 0){printf("Loss: %d\n",step+1);break;}
            if(top[0] == 52){printf("Win : %d\n",step+1);break;}
            flag = cmp();
            if(flag == 1){printf("Draw: %d\n",step+1);break;}
            while(top[now] == 0){
                now++;
                if(now > 7)now = 1;
            }
          //  system("pause");
            step++;
        }
    }
}
