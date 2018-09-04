#include<stdio.h>
#include<stdlib.h>
int main (){
    int n,T;
    int ca=0;
    int ans;
    scanf("%d",&T);
    while(T--){
        ans = 0;
        scanf("%d",&n);
        if(n < 180000)n = 0;
        if(n >= 180000)n-=180000;
        if(n >= 300000){
            n-=300000;
            ans += (int)((300000 * 0.1)+0.99999);
            //ans += 300000 * 0.1;
        }else if(n > 0){
            ans += (int)((n * 0.1)+0.99999);
            //ans += n * 0.1;
            //printf("ans %d\n",ans);
            n = 0;
        }
        if(n >= 400000){
            n-=400000;
            ans += (int)((400000 * 0.15)+0.99999);
            //ans += 400000 * 0.15;
        }else if(n > 0){
            ans += (int)((n * 0.15)+0.99999);
            //ans += n * 0.15;
            n = 0;
        }
        if(n >= 300000){
            n-=300000;
            ans += (int)((300000 * 0.2)+0.99999);
            //ans += 300000 * 0.2;
        }else if(n > 0){
            ans += (int)((n * 0.2)+0.99999);
            //ans += n * 0.2;
            n = 0;
        }
        if(n > 0){
            ans += (int)((n * 0.25)+0.99999);
            //ans += n * 0.25;
            n = 0;
        }
        if(ans < 2000 && ans > 0)ans = 2000;
        ca++;
        printf("Case %d: %d\n",ca,ans);
    }
    return 0;
}
/*
1.      The first 180,000/- of income is tax free.
2.      Next 300,000/- will have 10% tax.
3.      Next 400,000/- will have 15% tax.
4.      Next 300,000/- will have 20% tax.
5.      The rest will have 25% tax.
3
180001
12345
615000
*/
