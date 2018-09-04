#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main (){
    double a,b,c,S,x,y,z,ans;
    cout << fixed << setprecision(3);
    while(cin >> a >> b >> c){
        if(a+b <= c || b+c <= a || c+a <= b) {
            cout << "-1.000\n";
            continue;
        }
        x = 2 * a / 3.0;
        y = 2 * b / 3.0;
        z = 2 * c / 3.0;
        S = (x+y+z) / 2;
        ans = sqrt(S * (S - x) * (S - y) * (S - z)) * 3;
        cout << ans << "\n";
    }
    return 0;
}
