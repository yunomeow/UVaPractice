#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<iostream>
using namespace std;
struct shik{
    char s[100];
}data[10005];
int flag = 0;
bool cmp(shik a,shik b){
    int lena,lenb,i;
    i = 0;
    lena = strlen(a.s);
    lenb = strlen(b.s);    
    while(i < lena && i < lenb){
        if(a.s[i] != b.s[i])
            return a.s[i] < b.s[i] ;
        i++;
    }
    return lena < lenb; 
}
int main (){
    int T,n,len,last,i,j;
    scanf("%d",&T);
    while(T--){
        scanf("%d%*c",&n);
        for(i=0;i<n;i++){
            scanf("%s",data[i].s);
        }
        sort(data,data+n,cmp);
        last = strlen(data[0].s);
        for(i=1;i<n;i++){
            len = strlen(data[i].s);
            flag = 1;
            for(j=0;j<len && j < last;j++){
                if(data[i-1].s[j] != data[i].s[j]){
                    
                    flag = 0;
                    break;
                }
            }
            if(flag == 1)break;
            last = len;            
        }
        //for(i=0;i<n;i++)
          //  printf("%s\n",data[i].s);
        if(flag == 0)printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
