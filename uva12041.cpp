#include <iostream>
using namespace std;
typedef long long int64;
int64 f[105];
int solve(int64 n,int64 k){
    if(n == 0 && k == 0)return 0;
    if(n == 1 && k == 0)return 1;
    if(n > 50){
        int64 nn,tmp;
        tmp = (n - 50) / 2 + 1;
        nn = n - 2 * tmp;
        //cout << nn << "\n";
        return solve(nn,k);
    }
    if(k >= f[n-2])return solve(n-1,k-f[n-2]);
    else return solve(n-2,k);
}
int main (){
    int Z;
    int64 N,a,b;
    f[0] = 1;
    f[1] = 1;
    for(int i=2;i<=100;i++){
        f[i] = f[i-1] + f[i-2];
    }
    cin >> Z;
    while(Z--){
        cin >> N >> a >> b;
        for(int64 i=a;i<=b;i++){
            cout << solve(N,i);
        }
        cout << "\n";
    }
    return 0;
}
