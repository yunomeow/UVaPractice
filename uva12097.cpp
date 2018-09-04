#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
const double PI = acos(-1);
double cake[10005];
int N,M;
int check(double V){
    int cnt = 0;
    for(int i=0;i<M;i++){
        cnt += (int)(cake[i]/V);
    }
    if(cnt >= N)return 1;
    return 0;
}
int main (){
    int Z;
    double l,r,m;
    cin >> Z;
    cout << fixed << setprecision(4);
    while(Z--){
        cin >> M >> N;
        N++;
        for(int i=0;i<M;i++){
            cin >> cake[i];
            cake[i] = cake[i] * cake[i] * PI;
        }
        l = 0;r = 1e10;
        for(int i=0;i<300;i++){
            m = (l+r)/2;
            if(check(m))l = m;
            else r = m;
        }
        cout << l << "\n";
    }
    return 0;
}
