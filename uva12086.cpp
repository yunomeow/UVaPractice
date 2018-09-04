#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int node[800005];
int num[200005];
void modify(int l,int r,int x,int k,int n){
    int m = (l+r) / 2;
    node[n] += k;
    if(l == r)return;
    if(x > m)
        modify(m+1,r,x,k,2*n+1);
    else
        modify(l,m,x,k,2*n);
}
int query(int l,int r,int a,int b,int n){
    if(l == a && r == b)return node[n];
    //printf("l = %d r = %d a = %d b = %d\n",l,r,a,b) ;
    int m = (l+r)/2;
    if(b <= m){
        return query(l,m,a,b,2*n);
    }else if(a > m){
        return query(m+1,r,a,b,2*n+1);
    }else{
        return query(l,m,a,m,2*n) + query(m+1,r,m+1,b,2*n+1);
    }
}
int main (){
    int Z,N,a,b,zi=1,isFirst = 1;
    char op[5];

    while(scanf("%d",&N), N != 0){
        if(!isFirst)printf("\n");
        isFirst = 0;
        fill(&node[0],&node[800005],0);
        for(int i=0;i<N;i++){
            scanf("%d",&num[i]);
            modify(0,N-1,i,num[i],1);
        }
        printf("Case %d:\n",zi++);
        while(1){
            scanf("%s",op);
            if(strcmp(op,"S") == 0){
                scanf("%d%d",&a,&b);
                a--;
                modify(0,N-1,a,-num[a],1);
                num[a] = b;
                modify(0,N-1,a,num[a],1);
            }else if(strcmp(op,"M") == 0){
                scanf("%d%d",&a,&b);
                a--;b--;
                printf("%d\n",query(0,N-1,a,b,1));
            }else if(strcmp(op,"END") == 0){
                break;
            }
        }
    }
    return 0;
}
