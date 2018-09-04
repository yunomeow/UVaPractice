#include <iostream>
using namespace std;
typedef long long int64;
const int64 MOD  = 1000000007ll;
int64 solve(int64 n){
    if(n == 0)return 1ll;
    int64 tmp = solve(n/2);
    tmp = tmp * tmp;
    tmp %= MOD;
    if(n % 2 == 1)tmp = tmp * 2;
    tmp %= MOD;
    return tmp;
}
int main (){
    int64 N;
    int Z;
    cin >> Z;
    for(int zi=1;zi<=Z;zi++){
        cin >> N;
        cout << "Case #" << zi << ": " << (solve(N-1) * N) % MOD << "\n";
    }
    return 0;
}
