#include <iostream>
using namespace std;
typedef long long int64;
int main (){
    int64 S,D,l,r,m,tmp,t2;
    while(cin >> S >> D){
        l = 0ll;r = 100000000ll;
        if(D <= S){cout << S << "\n";continue;}
        while(r > l){
            m = (l+r)/2;
            tmp = (S+S+m)*(m+1)/2;
            if(tmp > D)r = m-1;
            else l = l+1;
        }
        for(int64 i=l-2;i<l+2;i++){
            if(i < 0)continue;
            tmp = (S+S+i)*(i+1)/2;
            t2 = (S+S+i+1)*(i+2)/2;
            if(D > tmp && t2 >= D){
                cout << (S+i+1) << "\n";
                break;
            }
        }
    }
    return 0;
}
