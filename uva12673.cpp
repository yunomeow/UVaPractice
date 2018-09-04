#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
struct XD{
    int a,b;
}data[100005];
bool cmp(XD a,XD b){
    return a.a-a.b > b.a - b.b;
}
int main(){
    int N,G,ans;
    while(cin >> N >> G){
        for(int i=0;i<N;i++)scanf("%d%d",&data[i].a,&data[i].b);
        ans = 0;
        sort(data,data+N,cmp);
        for(int i=0;i<N;i++){
           // cout << "G: " << G <<"\n";
           // cout << data[i].a<<" "<<data[i].b << "\n";
            if(data[i].a > data[i].b){
                ans+=3;
            }else if(data[i].a == data[i].b){
                if(G > 0){
                    G--;
                    ans += 3;
                }else{
                    ans += 1;
                }
            }else{
                if(G - (data[i].b - data[i].a) - 1>= 0){
                    G = G - (data[i].b - data[i].a) - 1;
                    ans += 3;
                }else if(G - (data[i].b - data[i].a) >= 0){
                    G = G - (data[i].b - data[i].a);
                    ans += 1;
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
