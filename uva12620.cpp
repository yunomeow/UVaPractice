#include <iostream>
using namespace std;
typedef long long int64;
const int MOD = 100;
int use[105][105];
int64 sum[305];
int64 cal(int64 m){
    int64 res=0;
    res = (m / 300) * sum[300] + sum[m % 300];
    return res;
}
int main (){
    int64 a,b,cnt = 0,c;
    a = b = 1;
    sum[0] = 0;
    while(use[a][b] == 0){
        use[a][b] = 1;
        c = (a + b) % MOD;
        sum[cnt+1] = sum[cnt] + a;
        a = b;
        b = c;
        cnt++;
    }
    int Z;
    cin >> Z;
    while(Z--){
        cin >> a >> b;
        cout << (cal(b) - cal(a-1)) << "\n";
    }
    return 0;
}
