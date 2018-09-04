#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;
vector<int> v;
int main (){
    int N,tmp,Q,pos;
    while(scanf("%d",&N) != EOF){
        v.clear();
        for(int i=0;i<N;i++){
            scanf("%d",&tmp);
            v.push_back(tmp);
        }
        scanf("%d",&Q);
        for(int i=0;i<Q;i++){
            scanf("%d",&tmp);
            pos = lower_bound(v.begin(),v.end(),tmp) - v.begin();
            //printf("lower pos %d\n",pos);
            pos--;
            if(pos >= 0 && v[pos] < tmp)printf("%d ",v[pos]);
            else printf("X ");
            pos = upper_bound(v.begin(),v.end(),tmp) - v.begin();
            //printf("upper pos %d\n",pos);
            if(pos < (int)v.size() && v[pos] == tmp)
            pos++;
            if(pos < (int)v.size() && v[pos] > tmp)printf("%d\n",v[pos]);
            else printf("X\n");
        }
    }
    return 0;
}
