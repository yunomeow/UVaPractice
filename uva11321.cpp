#include <iostream>
#include <algorithm>
using namespace std;
int M;
int num[10005];
bool cmp(int a,int b){
    if((a % M) != (b % M)){
        return (a % M) < (b % M);
    }
    if((abs(a) % 2) != (abs(b) % 2))return (abs(a) % 2) > (abs(b) % 2);
    if((abs(a) % 2) == 1)return a > b;
    return a < b;
}
int main (){
    int N;
    while(cin >> N >> M){
        cout << N << " "  << M << "\n";
        if(N == 0 && M == 0)break;
        for(int i=0;i<N;i++)cin >> num[i];
        sort(num,num+N,cmp);
        for(int i=0;i<N;i++)cout << num[i] << "\n";
    }
    return 0;
}
