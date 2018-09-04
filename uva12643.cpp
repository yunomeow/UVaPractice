#include <iostream>
using namespace std;
int main (){
    int N,a,b,ans;
    while(cin >> N >> a >> b){
        ans = 0;
        while(a != b){
            a = (a+1)/2;
            b = (b+1)/2;
            ans++;
        }
        cout << ans << "\n";
    }
    return 0;
}
