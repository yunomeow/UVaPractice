#include <iostream>
using namespace std;
int main (){
    int N,a,b,cnt,now;
    while(cin >> N, N){
        now = cnt = a = b = 0;
        while(N > 0){
            if(N % 2 == 1){
                if(now == 0)a = a | (1 << cnt);
                else b = b | (1 << cnt);
                now = 1 - now;
            }
            cnt++;
            N /= 2;
        }
        cout << a <<" " << b <<"\n";
    }
    return 0;
}
