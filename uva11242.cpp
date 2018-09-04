#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>
using namespace std;
double num[100],num2[100];
double ratio[1000];
int main (){
    int n,m;
    int i,j,k;
    double ans;
    while(1){
        scanf("%d",&n);
        if(n == 0)break;
        scanf("%d",&m);
        for(i=0;i<n;i++)
            scanf("%lf",&num[i]);
        for(i=0;i<m;i++)
            scanf("%lf",&num2[i]);
        k=0;
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                ratio[k] = num2[j]/num[i];
                k++;
            }
        }
        ans = 0;
        sort(ratio,ratio+k);
        for(i=0;i<k-1;i++){
            //printf("%lf \n",ratio[i+1]/ratio[i]);
            if(ans < ratio[i+1]/ratio[i])
                ans = ratio[i+1]/ratio[i];
        }
        printf("%.2lf\n",ans);
    }
    return 0;
}
