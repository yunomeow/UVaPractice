#include <iostream>
using namespace std;
const int MOD = 1000000009;
typedef long long int64;
struct Matrix{
    int64 m[3][3];
    Matrix(){
        fill(&m[0][0],&m[3][0],0);
    }
    Matrix operator *(const Matrix &b)const{
        Matrix res;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                for(int k=0;k<3;k++){
                    res.m[i][j] += m[i][k] * b.m[k][j];
                    res.m[i][j] %= MOD;
                }
            }
        }
        return res;
    }
}unit,one,fir;
Matrix cal(int64 n){
    if(n == 0)return unit;
    Matrix tmp = cal(n/2);
    tmp = tmp * tmp;
    if(n % 2 == 1)tmp = tmp * one;
    return tmp;
}
int main (){
    one.m[0][0] = 0;one.m[0][1] = 0;one.m[0][2] = 1;
    one.m[1][0] = 1;one.m[1][1] = 0;one.m[1][2] = 1;
    one.m[2][0] = 0;one.m[2][1] = 1;one.m[2][2] = 1;

    fir.m[0][0] = 0;fir.m[0][1] = 1;fir.m[0][2] = 2;
    fir.m[1][0] = 0;fir.m[1][1] = 0;fir.m[1][2] = 0;
    fir.m[2][0] = 0;fir.m[2][1] = 0;fir.m[2][2] = 0;

    unit.m[0][0] = 1;unit.m[0][1] = 0;unit.m[0][2] = 0;
    unit.m[1][0] = 0;unit.m[1][1] = 1;unit.m[1][2] = 0;
    unit.m[2][0] = 0;unit.m[2][1] = 0;unit.m[2][2] = 1;

    int64 N;
    Matrix ans;
    ans = one * one;

    while(cin >> N, N){
        ans = fir * cal(N-1);
        cout << ans.m[0][0] << "\n";
    }
    return 0;
}
