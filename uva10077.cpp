#include <iostream>
using namespace std;
int main (){
    long long N,M;
    long long LU,LD,RU,RD,MU,MD;
    while(cin >> N >> M){
        if(N == 1 && M == 1)break;
        LU = 0;LD = 1;
        MU = 1;MD = 1;
        RU = 1;RD = 0;
        while(MU != N || MD != M){
            if(MD * N >  MU * M){
                LD = MD;LU = MU;
                cout << "R";
            }else{
                RD = MD;RU = MU;
                cout << "L";
            }
            MU = LU+RU;
            MD = LD+RD;
        }
        cout << "\n";
    }
    return 0;
}
/*
5 7
878 323
1 1
*/
