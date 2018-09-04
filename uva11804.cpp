#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#include<iostream>
using namespace std;
struct shik{
    int att,def;
    char s[100];
}data[100];
bool cmp(shik a,shik b){
    if(a.att == b.att)
        return a.def < b.def;
    return a.att > b.att;
}
bool cmp2(shik a,shik b){
    int lena = strlen(a.s),lenb = strlen(b.s),i,j;
    i = 0;
    j = 0;
    while(i < lena && j < lenb){
        if(a.s[i] != b.s[j])
            return a.s[i] < b.s[i];
        i++;
        j++;
    }
    return lena < lenb;
}
int main (){
    int ca = 0,T,i;
    scanf("%d%*c",&T);
    while(T--){
        for(i=0;i<10;i++){
           scanf("%s%d%d",data[i].s,&data[i].att,&data[i].def);
        }
        sort(data,data+10,cmp2);        
        sort(data,data+10,cmp);
        sort(data,data+5,cmp2);
        sort(data+5,data+10,cmp2);    
        ca++;
        printf("Case %d:\n",ca);
        printf("(%s, %s, %s, %s, %s)\n",data[0].s,data[1].s,data[2].s,data[3].s,data[4].s);
        printf("(%s, %s, %s, %s, %s)\n",data[5].s,data[6].s,data[7].s,data[8].s,data[9].s);

    }
    return 0;
}
