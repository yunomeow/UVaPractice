#include <iostream>
using namespace std;
typedef long long int64;
int64 num[15];
int64 gcd(int64 a,int64 b){
    while((a%=b) &&(b%=a));
    return a+b;
}
int main (){
    int Z,N;
    int64 U,D,g;
    cin >> Z;
    for(int zi=1;zi<=Z;zi++){
        cin >> N;
        U = 1;
        for(int i=0;i<N;i++){
            cin >> num[i];
            U = U * num[i];
        }
        D = 0;
        for(int i=0;i<N;i++){
            D += U / num[i];
        }
        U = U * N;
        g = gcd(U,D);
        U = U / g;
        D = D / g;
        cout << "Case " << zi << ": " << U << "/"  << D << "\n";
    }
    return 0;
}
