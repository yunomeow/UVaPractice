#include <iostream>
using namespace std;
typedef long long int64;
int x=0;
int main (){
    int Z;
    int64 N,U;
    cin >> Z;
    for(int zi=1;zi<=Z;zi++){
        cin >> N;
        U = N * (N-1) / 2;
        if(U % 2 == 0)cout << "Case " << zi << ": " << U/2 << "\n";
        else cout << "Case " << zi << ": " << U << "/2\n";
    }
    return 0;
}
