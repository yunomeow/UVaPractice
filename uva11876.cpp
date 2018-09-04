#include<stdio.h>
#include<stdlib.h>
int prime[1000005];
int use[1000005];
int num[1000005];
int main (){
    int i,j,x,a,b,ca=0;
    int nod,tmp,cnt,ans;
    int left,right,mid;
    int aa,ab,T;
    prime[0] = 2;
    x = 1;
    for(i=3;i<1000005;i+=2){
        if(use[i] == 0){
            prime[x] = i;
            x++;
            for(j=i+i;j<1000005;j+=i){
                use[j] = 1;
            }
        }
    }
    num[0] = 1;
    nod = 0;
    for(i=1;i<70002;i++){
        num[i] = num[i-1] + nod;
        tmp = num[i];
        nod = 1;
        for(j=0;j<x;j++){
            if(prime[j] > tmp)break;
            cnt = 0;
            while(tmp % prime[j] == 0){
                tmp /= prime[j];
                cnt++;
            }
            nod *= cnt+1;
        }

    }
    //printf("%d\n",num[i-1]);
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&a,&b);
        left = 0;
        right = 70000;
        while(right - left > 1){
            mid = (right+left)/2;
            if(num[mid] > a)right = mid;
            else left = mid;
        }
        for(i=left-2;i<left+2;i++){
            if(i < 0)continue;
            if(num[i+1] > a && num[i] >= a){
                aa = i;
                break;
            }
        }

        left = 0;
        right = 70000;
        while(right - left > 1){
            mid = (right+left)/2;
            if(num[mid] > b)right = mid;
            else left = mid;
        }
        for(i=left-2;i<left+2;i++){
            if(i < 0)continue;
            if(num[i+1] > b && num[i] <= b){
                ab = i;
                break;
            }
        }
        //printf("aa %d ab %d %d %d\n",aa,ab,num[aa],num[ab]);
        if(ab >= aa)ans = ab - aa + 1;
        else ans = 0;
        ca++;
        printf("Case %d: %d\n",ca,ans);
    }
    return 0;
}
