#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct State{
    int dir;
    int par;
    int use;
}data[3628810];
int num[3][3];
int q[4000000][10];
int fact[10];
int ans[1000000];
int clearlist[1000000];
inline int cal(){
    int tmp[10],val=0,i,j,k=0;
    for(i=0;i<3;i++)
        for(j=0;j<3;j++){
            tmp[k] = num[i][j];
            k++;
        }
    for(i=0;i<10;i++){
        for(j=i+1;j<10;j++)
            if(tmp[i]<tmp[j])tmp[j]--;
        val += fact[8-i] * (tmp[i]-1);
        //printf("%d\n",val);
    }
    return val;
}
int main (){
    int i,j,head,tail,k,t,c,old,z,now,first,cnt,flag,top;
    fact[0] = 1;
    for(i=1;i<10;i++)fact[i] = i * fact[i-1];
            k = 0;
            for(i=0;i<3;i++){
                for(j=0;j<3;j++){
                    num[i][j] = k+1;
                    k++;
                }
            }        
        memset(data,0,sizeof(data));
        first = cal();
        
        data[first].use = 1;
        head = 0;tail = 1;k = 0;
        for(i=0;i<3;i++){
            for(j=0;j<3;j++){
                q[0][k] = num[i][j];
                k++;
            }
        }
        flag = 0;
        while(head < tail){
            k = 0;
            for(i=0;i<3;i++){
                for(j=0;j<3;j++){
                    num[i][j] = q[head][k];
                    k++;
                }
            }
            old = cal();
            for(z=0;z<6;z++){
                switch(z){
                    case 0:
                    case 1:
                    case 2:
                        t = num[z][0];  num[z][0] = num[z][1];  num[z][1] = num[z][2];  num[z][2] = t;
                        c = cal();
                        if(data[c].use == 0){
                            data[c].use = 1;
                            data[c].par = old;
                            data[c].dir = z;
                            top++;
                            k = 0;
                            for(i=0;i<3;i++){
                                for(j=0;j<3;j++){
                                    q[tail][k] = num[i][j];
                                    k++;
                                }
                            }
                            tail++;
                        }
                        t = num[z][2];  num[z][2] = num[z][1];  num[z][1] = num[z][0];  num[z][0] = t;
                        break;
                    case 3:
                    case 4:
                    case 5:
                        t = num[2][z-3];  num[2][z-3] = num[1][z-3];  num[1][z-3] = num[0][z-3];  num[0][z-3] = t;
                        c = cal();
                        if(data[c].use == 0){
                            data[c].use = 1;
                            data[c].par = old;
                            data[c].dir = z;
                            k = 0;
                            for(i=0;i<3;i++){
                                for(j=0;j<3;j++){
                                    q[tail][k] = num[i][j];
                                    k++;
                                }
                            }
                            tail++;
                        }
                        t = num[0][z-3];  num[0][z-3] = num[1][z-3];  num[1][z-3] = num[2][z-3];  num[2][z-3] = t;
                        break;
                }
            }
            head++;
        }
    while(1){
        
        scanf("%d",&num[0][0]);
        if(num[0][0] == 0)break;
        for(i=0;i<3;i++){
            for(j=0;j<3;j++){
                if(i == 0 && j == 0)continue;
                scanf("%d",&num[i][j]);
            }
        }
        first = cal();
        now = first;
        cnt = 0;
        if(data[first].use == 1)flag = 1;
        else flag = 0;
        if(flag == 1){
            while(now != 0){
                ans[cnt] = data[now].dir;
                now = data[now].par;
                cnt++;
            }
            printf("%d ",cnt);
            for(i=0;i<cnt;i++){
                switch(ans[i]){
                    case 0:printf("H1");break;
                    case 1:printf("H2");break;
                    case 2:printf("H3");break;
                    case 3:printf("V1");break;
                    case 4:printf("V2");break;
                    case 5:printf("V3");break;                                                                                                    
                }
            }
            printf("\n");
        }else{
            printf("Not solvable\n");
        }
    }
    return 0;
}
