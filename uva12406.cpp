#include <iostream>
using namespace std;
typedef long long int64;
int64 p,q,ans1,ans2;
int num[20];
int64 check(){
    int64 tmp = 0;
    for(int i=0;i<p;i++)tmp = tmp * 10 + num[i];
    if(tmp % (1 << q) == 0)return tmp;
    return 0;
}
void solve(int pos){
    int64 res;
    if(pos == p){
        res = check();
        if(res > 0){
            ans1 = min(ans1,res);
            ans2 = max(ans2,res);
        }
        return ;
    }
    num[pos] = 1;
    solve(pos+1);
    num[pos] = 2;
    solve(pos+1);
}
int main (){
    int Z;
    cin >> Z;
    for(int zi=1;zi<=Z;zi++){
        cin >> p >> q;
        cout << "Case " << zi << ": ";
        ans1 = 1e18;ans2 = 0;
        solve(0);
        if(ans1 == 1e18)cout << "impossible\n";
        else if(ans1 == ans2)cout << ans1 << "\n";
        else cout << ans1  << " " << ans2 << "\n";
    }
    return 0;
}
