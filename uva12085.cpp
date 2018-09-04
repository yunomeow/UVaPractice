#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<string.h>
using namespace std;
char name[100005][20];
int main (){
    int n;
    long long st,ed,now;
    int i,ca=0,p1,p2,k;
    while(1){
        scanf("%d",&n);
        if(n == 0)break;
        for(i=0;i<n;i++){
            scanf("%s",name[i]);
        }
        st = -1;
        ca++;
        printf("Case %d:\n",ca);
        for(k=0;k<=n;k++){
            //printf("n %d\n",n);
            if(k < n){
                sscanf(name[k],"%lld",&now);
            }else
            {
                now = 0;
            }
            //printf("now %lld\n",now);
            if(st == -1){
                st = now;
                ed = st;
                p1 = k;
                p2 = k;
            }else if(now == ed + 1){
                ed++;
                p2 = k;
            }else{
                printf("%s",name[p1]);
                if(p1 != p2){
                    printf("-");
                    int len = strlen(name[p2]);
                    int j;
                    for(i=0;i<=len;i++){
                        if(name[p1][i] == name[p2][i]){
                            continue;
                        }else{
                            j = i;
                            break;
                        }
                    }
                    for(i=j;i<len;i++)printf("%c",name[p2][i]);

                }
                printf("\n");
                st = now;
                ed = st;
                p1 = k;
                p2 = k;
            }
        }
        printf("\n");
    }
    return 0;
}
/*
3
01711322396
01711322397
01711322398
7
01187239192
01711322396
01711322397
01711322398
01711322399
01711322400
01711389821
*/
