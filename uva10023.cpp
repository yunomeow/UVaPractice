#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct BigInt{
    int num[1006];
    int len;
}x,y,tmp,zero,tx;
void mul(BigInt &a,int k){
    int i,carry,tmp;
    for(i=0;i<a.len;i++){
        a.num[i] *= k;
    }
    carry = 0;
    for(i=0;i<a.len+3;i++){
        a.num[i] += carry;
        if(a.num[i] >= 10000){
            carry = a.num[i] / 10000;
            a.num[i] %= 10000;
        }else
            carry = 0;
    }
    tmp = 1;
    for(i=0;i<a.len + 4;i++){
        if(a.num[i] != 0)tmp = i+1;
    }
    a.len = tmp;
}
void plus(BigInt &a,int k){
    int i,carry = 0,tmp;
    a.num[0] += k;
    for(i=0;i<a.len+2;i++){
        a.num[i] += carry;
        if(a.num[i] >= 10000){
            carry = a.num[i] / 10000;
            a.num[i] %= 10000;
        }else{
            carry = 0;
        }
    }
    tmp = 1;
    for(i=a.len+5;i>=0;i--){
        if(a.num[i] != 0){
            tmp = i+1;
            break;
        }
    }
    a.len = tmp;
}
int compare(BigInt &a,BigInt &b){
    if(a.len > b.len)return 1;
    if(b.len > a.len)return -1;
    int i;
    for(i=a.len;i>=0;i--){
        if(a.num[i] > b.num[i])return 1;
        if(a.num[i] < b.num[i])return -1;
    }
    return 0;
}
void minus(BigInt &a,BigInt &b){
    int i;
    for(i=0;i<a.len;i++){
        if(a.num[i] < 0){
            a.num[i+1]--;
            a.num[i] += 10000;
            a.num[i] -= b.num[i];
        }else if(a.num[i] < b.num[i]){
            a.num[i] += 10000;
            a.num[i+1]--;
            a.num[i] -= b.num[i];
        }else{
            a.num[i] -= b.num[i];
        }
    }
    for(i=a.len-1;i>=0;i--){
        if(a.num[i] != 0){
            a.len = i+1;
            break;
        }
    }
}
void printBigInt(BigInt &a){
    int i;
    for(i=a.len-1;i>=0;i--)
        printf("%d",a.num[i]);
    printf("\n");
}
char s[10005];
int main (){
    int i,T,len,j,b,now,flag=0;
    zero.num[0] = 0;
    zero.len = 1;
    scanf("%d%*c",&T);
    while(T--){
        if(flag == 1)printf("\n");
        flag = 1;
        scanf("%*c%s",s);
        for(i=0;i<1004;i++)x.num[i] = 0;
        for(i=0;i<1004;i++)y.num[i] = 0;
        for(i=0;i<1005;i++)tmp.num[i] = 0;
        for(i=0;i<1005;i++)tx.num[i] = 0;
        len = strlen(s);
        for(i=len-1,j=0,k=-1;i>=0;i--,j++){
            if(j%4 == 0)k++;
            x.num[k] = s.num[k] * 10 + s[i] - 48;
        }
        x.len = k+1;
        y.len = 1;
        tx.len = 1;
        if(len % 4 == 0){
            tx.num[0] = x.num[x.len-1]/100;
        }else if(now % 4 == 1){
            tx.num[0] = x.num[x.len-1]/100;
        }else if(now % 4 == 2){
            tx.num[0] = x.num[x.len-1]%100;            
        }else if(now % 4 == 3){
            tx.num[0] = x.num[x.len-1]%100;            
        }
        while(now >= 0){
            mul(y,10);
            for(b=0;b<10;b++){
                for(j=0;j<y.len+5;j++){
                    tmp.num[j] = y.num[j];
                }
                tmp.len = y.len;
                mul(tmp,2*b);
                plus(tmp,b*b);
                if(compare(tx,tmp) < 0)break;
            }
            for(j=0;j<y.len+5;j++){
                tmp.num[j] = y.num[j];
            }
            tmp.len = y.len;
            b--;
            mul(tmp,2*b);
            plus(tmp,b*b);
            minus(tx,tmp);
            plus(y,b);
            mul(tx,100);
            plus(tx,x.num[now-1]*10 + x.num[now-2]);
            now-=2;
        }
        printBigInt(y);
    }
    return 0;
}
