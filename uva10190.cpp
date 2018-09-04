#include <iostream>
#include <cstdio>
using namespace std;
int main (){

    int N,M,tn;
    while(scanf("%d%d",&N,&M) != EOF){
        tn = N;
        if(M <= 1 || N <= 1){
            cout << "Boring!\n";
            continue;
        }
        while(tn % M == 0)tn /= M;
        if(tn != 1)cout << "Boring!\n";
        else{
            while(N >= 1){
                if(N == 1)
                cout << "1\n";
                else cout << N <<" " ;
                N /= M;
            }
        }
    }
    return 0;
}
/*
125 5
30 3
80 2
81 3
*/
