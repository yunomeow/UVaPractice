#include<stdio.h>
#include<stdlib.h>
int n;
long long ans;
int num[500005],tmp1[500005],tmp2[500005];
void mergesort(int left,int right){
    int mid = (right+left)/2,i,j,k;
    if(left >= right)return;
    mergesort(left,mid);
    mergesort(mid+1,right);
    for(i=left,j=0;i<=mid;i++,j++)
        tmp1[j] = num[i];
    for(i=mid+1,j=0;i<=right;i++,j++)
        tmp2[j] = num[i];
    i = 0;j = 0;
    k = left;
    while(i < mid-left+1 && j < right - mid){
        if(tmp1[i] <= tmp2[j]){
            num[k] = tmp1[i];
            i++;
        }else{
            ans += (mid-left+1)-i;
            num[k] = tmp2[j];
            j++;
        }
        k++;
    }
    while(i < mid-left+1){
            num[k] = tmp1[i];
            i++;
            k++;
    }  
    while(j < right - mid){
            ans += (mid-left+1)-i;
            num[k] = tmp2[j];
            j++;
            k++;
    }      
}
int main (){
    int i;
    while(1){
        scanf("%d",&n);
        if(n == 0)break;
        for(i=0;i<n;i++)
            scanf("%d",&num[i]);
        ans = 0;
        mergesort(0,n-1);
      //  for(i=0;i<n;i++)
      //      printf("%d ",num[i]);
       // printf("\n");
        printf("%lld\n",ans);
    }
    return 0;
}
