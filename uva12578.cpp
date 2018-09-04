#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main (){
    int Z;
    double a1,a2,N;
    cin >> Z;
    cout << fixed << setprecision(2);
    while(Z--){
        cin >> N;
        a1 = (N / 5.0)*(N / 5.0) * acos(-1);
        a2 = N * 3.0/5.0 * N - a1;
        cout << a1 << " " << a2 << "\n";
    }
    return 0;
}
