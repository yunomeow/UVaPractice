#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>
using namespace std;
struct shik{
    int a,b,val;
}data[1000005],data2[1000006];
int num[1005],x;
bool cmp(shik a,shik b){
    if(a.val == b.val)
        return a.a > b.a;
    return a.val < b.val;
}
int main (){
    int n,left,right,mid,ans,i,j;
    while(1){
        scanf("%d",&n);
        if(n == 0)break;
        x = 0;
        for(i=0;i<n;i++)
            scanf("%d",&num[i]);
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                if(i == j)continue;
                data[x].a = num[i];
                data[x].b = num[j];
                data[x].val = num[i] + num[j];
                x++;
            }
        }
        x = 0;
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                if(i == j)continue;
                data2[x].a = num[i];
                data2[x].b = num[j];
                data2[x].val = num[i] - num[j];
                x++;
            }
        }
        sort(data,data+x,cmp);
        sort(data2,data2+x,cmp);
        ans = -2147000000;
     //   for(i=0;i<x;i++)printf("%d ",data[i].val);
     //   printf("\n");
      //  for(i=0;i<x;i++)printf("%d ",data2[i].val);
       // printf("\n");
        for(i=0;i<x;i++){
            left = 0;right = x;
            while(right - left > 1){
                mid = (left + right)/2;
                if(data2[mid].val < data[i].val)
                    left = mid;
                else
                    right = mid;
            }
           // printf("r %d\n",right);
            for(j=right;j > right - 5&&  j >= 0; j--){
                if(data[i].val == data2[j].val){
                  //  printf("in\n");
                    if(data[i].a != data2[j].a && data[i].a != data2[j].b && data[i].b != data2[j].a && data[i].b != data2[j].b){
                        if(data2[j].a > ans)
                            ans = data2[j].a;
                    }
                }
            }
        }
        if(ans != -2147000000)printf("%d\n",ans);
        else printf("no solution\n");
    }
    return 0;
}

