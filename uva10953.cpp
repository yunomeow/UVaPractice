#include<stdio.h>
#include<string.h>
#include<stdlib.h>
double prob[12];
double dp[55][15];
char s[100];
int main (){
    int n,i,j,k,l,q,r;
    int len,ca=0;
    int odd,even;
    int osum,esum,sum,pos;
    double tmp,ans;
    while(1){
        scanf("%d",&n);
        if(n == 0)break;
        memset(prob,0,sizeof(prob));
        for(i=0;i<n;i++){
            scanf("%d",&pos);
            scanf("%lf",&prob[pos]);
        }
        memset(dp,0,sizeof(dp));
        
        for(i=0;i<11;i++){
            dp[0][0] = 1;
            dp[1][i] = prob[i];
        }
        for(i=2;i<52;i++){
            for(j=0;j<11;j++){
                tmp = 0;
                for(k=0;k<11;k++){
                    for(l=0;l<11;l++){
                        if((l+k) % 11 == j){
                            tmp = tmp + dp[i-1][k] * prob[l];
                            //printf("tmp %lf %d %d %d\n",tmp,data[l].num,data[k].num,data[j].num);
                        }
                    }
                }
                dp[i][j] = tmp;
                //printf("%.10lf\n",tmp);
            }
           // printf("\n");
        }
        ca++;
        printf("Case %d:\n",ca);
        scanf("%d",&q);
        while(q--){
            odd = 0;
            even = 0;
            osum = 0;
            esum = 0;
            scanf("%s%d",s,&r);
            len = strlen(s);
            int type;
            if(len % 2 == 0)type = 1;
            else type = 0;
            for(i=0;i<len;i++){
                if(i % 2 == type){
                    if(s[i] == '*')
                        odd++;
                    else
                        osum += s[i] - 48;
                }else{
                    if(s[i] == '*')
                        even++;
                    else
                        esum += s[i] - 48;                
                }
            }
            /*
            printf("\n");
            for(i=0;i<11;i++){
                printf("%lf\n",dp[even][i]);
            }
            printf("\n");
            for(i=0;i<11;i++){
                printf("%lf\n",dp[odd][i]);
            }
            printf("\n");
            */
            //printf("odd %d even %d\n",odd,even);
            //printf("osum %d esum %d\n",osum,esum);
            ans = 0;
            //printf("val %lf\n",dp[even][1]*dp[odd][2]);
            if(even != 0 && odd != 0){
                for(i=0;i<11;i++){
                    for(j=0;j<11;j++){
                        sum = (i + osum) - (j + esum);
                        //if(sum < 0)sum *= -1;
                        //printf("sum %d\n",sum);
                        while(sum < 0)sum += 11;
                        sum %= 11;
                        if(sum == r){
                            //printf("sum %d\n",sum);
                            ans += dp[odd][i] * dp[even][j];
                            //printf("ans %lf\n",ans);
                        } 
                    }
                }
            }
            if(even == 0 && odd != 0){
                for(i=0;i<11;i++){
                    sum = (i + osum) - (esum);
                    //if(sum < 0)sum *= -1;
                    //printf("sum %d\n",sum);
                    while(sum < 0)sum += 11;
                    sum %= 11;
                    if(sum == r){
                        //printf("sum %d\n",sum);
                        ans += dp[odd][i];
                        //printf("ans %lf\n",ans);
                    } 
                }
            }
            if(even != 0 && odd == 0){
                for(i=0;i<11;i++){
                    sum = (osum) - (i + esum);
                    //if(sum < 0)sum *= -1;
                    //printf("sum %d\n",sum);
                    while(sum < 0)sum += 11;
                    sum %= 11;
                    if(sum == r){
                        //printf("sum %d\n",sum);
                        ans += dp[even][i];
                        //printf("ans %lf\n",ans);
                    } 
                }
            }
            if(even == 0 && odd == 0){
                sum = osum - esum;
                while(sum < 0)sum += 11;
                if(( sum ) % 11 == r){
                    ans = 1;
                }
                else{
                    ans = 0;
                }
            }
            printf("%.8lf\n",ans);
        }
    }
    return 0;
}
/*
10
0 0.1
1 0.1
2 0.1
3 0.1
4 0.1
5 0.1
6 0.1
7 0.1
8 0.1
9 0.1
5
*** 0
12* 0
1** 0
121 0
121 1
0
*/
