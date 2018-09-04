#include<stdio.h>
#include<stdlib.h>
struct XD{
    char s[1000];
    int val;
}data[20];
int main (){
    int T,i,ca=0;
    int MAX;
    scanf("%d",&T);
    while(T--){
        for(i=0;i<10;i++)
            scanf("%s%d",data[i].s,&data[i].val);
        MAX = 0;
        for(i=0;i<10;i++){
            if(data[i].val > MAX)MAX = data[i].val;
        }
        ca++;
        printf("Case #%d:\n",ca);
        for(i=0;i<10;i++)
            if(data[i].val == MAX)
                printf("%s\n",data[i].s);
    }
    return 0;
}
/*
2
www.youtube.com 1
www.google.com 2
www.google.com.hk 3
www.alibaba.com 10
www.taobao.com 5
www.bad.com 10
www.good.com 7
www.fudan.edu.cn 8
www.university.edu.cn 9
acm.university.edu.cn 10
www.youtube.com 1
www.google.com 2
www.google.com.hk 3
www.alibaba.com 11
www.taobao.com 5
www.bad.com 10
www.good.com 7
www.fudan.edu.cn 8
acm.university.edu.cn 9
acm.university.edu.cn 10
*/
