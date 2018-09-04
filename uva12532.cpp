#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
struct XD{
    int zcnt;
    int mcnt;
}data[100005];
int num[100005];
int N,K,sq;
void prep(){
    sq = sqrt(N);
    for(int i=0;i<N;i++){
        if(num[i] == 0)
            data[i / sq].zcnt++;
        if(num[i] < 0)
            data[i / sq].mcnt++;
    }
}
void change(int k,int n){
    if(num[k] < 0)data[k / sq].mcnt--;
    if(num[k] == 0)data[k / sq].zcnt--;
    if(n < 0)data[k / sq].mcnt++;
    if(n == 0)data[k / sq].zcnt++;
    num[k] = n;
}
int query(int a,int b){
    int res=1,zc=0,mc=0,st,ed;
    st = sq * (a / sq);
    ed = sq * (b / sq);
    //cout << "st: " << st << " ed: " << ed <<"\n";
    for(int i=a;i<st+sq && i <= b;i++){
        if(num[i] < 0)mc++;
        if(num[i] == 0)zc++;
    }
    for(int i= (a / sq) + 1;i<(b / sq);i++){
        zc += data[i].zcnt;
        mc += data[i].mcnt;
    }
    if(st != ed){
        for(int i=ed;i<=b;i++){
            if(num[i] < 0)mc++;
            if(num[i] == 0)zc++;
        }
    }
    if(zc > 0)res = 0;
    else if(mc % 2 == 1)res = -1;
    //cout << "zc: " << zc << " mc: " << mc << "\n";
    return res;
}
int main (){
    string op;
    while(cin >> N >> K){
        for(int i=0;i<N;i++){
            scanf("%d",&num[i]);
            data[i].zcnt = 0;
            data[i].mcnt = 0;
        }
        int a,b;
        prep();
       // cout << "sq: " << sq << "\n";
        while(K--){
            cin >> op >> a >> b;
            if(op == "C")change(a-1,b);
            else{
                int res = query(a-1,b-1);
                if(res == 0)cout << "0";
                else if(res == -1)cout <<"-";
                else cout << "+";
            }
        }
        cout <<"\n";
    }
    return 0;
}
