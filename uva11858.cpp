#include<stdio.h>
#include<stdlib.h>
int num[1000005];
int tmp1[1000005],tmp2[1000005];
long long ans;
void mergesort(int left,int right){
    int i,j,n1,n2,mid,k;
    mid = (left+right)/2;
    if(right <= left)return;
    mergesort(left,mid);
    mergesort(mid+1,right);
    n1 = 0;
    for(i=left;i<=mid;i++){
        tmp1[n1] = num[i];
        n1++;
    }
    n2 = 0;
    for(i=mid+1;i<=right;i++){
        tmp2[n2] = num[i];
        n2++;
    }
    i = 0;j = 0;k = left;
    while(i < n1 && j < n2){
        if(tmp1[i] <= tmp2[j]){
            num[k] = tmp1[i];
            k++;
            i++;
        }else{
            num[k] = tmp2[j];
            ans += n1 - i;
            //printf("ans %d n1 %d n2 %d i %d\n",ans,n1,n2,i);
            k++;
            j++;
        }
    }
    while(i < n1){
        num[k] = tmp1[i];
        k++;
        i++;
    }
    while(j < n2){
        num[k] = tmp2[j];
        k++;
        j++;
    }
}
int main (){
    int n,i;
    while(scanf("%d",&n) != EOF){
        for(i=0;i<n;i++)
            scanf("%d",&num[i]);
        ans = 0;
        mergesort(0,n-1);
        printf("%lld\n",ans);
    }
    return 0;
}
