#include<stdio.h>
#include<stdlib.h>
int num[1000005],num2[1000005];
int main (){
    int n,m;
    int cnt,i,j;
    while(1){
        scanf("%d%d",&n,&m);
        if(n == 0 && m == 0)break;
        for(i=0;i<n;i++)scanf("%d",&num[i]);
        for(i=0;i<m;i++)scanf("%d",&num2[i]);
        cnt = 0;
        i = 0;j = 0;
        while(i < n && j < m){
            if(num[i] > num2[j])j++;
            else if(num[i] < num2[j])i++;
            else if(num[i] == num2[j]){
                cnt++;
                i++;
                j++;
            }
        }
        printf("%d\n",cnt);
    }
    return 0;
}
/*
3 3
1
2
3
1
2
4
0 0
*/
