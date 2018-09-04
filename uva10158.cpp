#include<stdio.h>
#include<stdlib.h>
int n,par[20055];
int other(int i){
    if(i >= n)return i-n;
    else return i+n;
}
int find_par(int x){
    if(par[x] == x)return x;
    par[x] = find_par(par[x]);
    return par[x];
}
void Union(int x,int y){
    int sx = find_par(x);
    int sy = find_par(y);
    par[sx] = sy;
}
int main (){
    int i,j,type,a,b;
    scanf("%d",&n);
    for(i=0;i<2*n+5;i++)par[i] = i;
    while(1){
        scanf("%d%d%d",&type,&a,&b);
        if(type == 0 && a == 0 && b == 0)break;
        switch(type){
            case 1:
                if(find_par(a) == find_par(other(b)) || find_par(other(a)) == find_par(b))
                    printf("-1\n");
                else{
                    Union(a,b);
                    Union(other(a),other(b));
                }
                break;
            case 2:
                if(find_par(a) == find_par(b) || find_par(other(a)) == find_par(other(b)))
                    printf("-1\n");
                else{
                    Union(a,other(b));
                    Union(other(a),b);
                }
                break;
            case 3:
                if(find_par(a) == find_par(b) || find_par(other(a)) == find_par(other(b)))
                    printf("1\n");
                else
                    printf("0\n");
                break;
            case 4:
                if(find_par(a) == find_par(other(b)) || find_par(other(a)) == find_par(b))
                    printf("1\n");
                else
                    printf("0\n");
                break;            
        }
    }
    return 0;
}
