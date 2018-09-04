#include <iostream>
#include <algorithm>
using namespace std;
int num1[505],num2[505];
int main (){
    int ans,N,d,r;
    while(cin >> N >> d >> r , N+d+r){
        for(int i=0;i<N;i++)cin >> num1[i];
        for(int i=0;i<N;i++)cin >> num2[i];
        sort(num1,num1+N);
        sort(num2,num2+N);
        ans = 0;
        for(int i=0;i<N;i++){
            ans += max(0,(num1[i]+num2[N-i-1]-d)*r);
        }
        cout << ans << "\n";
    }
    return 0;
}
/*
2 20 5
10 15
10 15
2 20 5
10 10
10 10
0 0 0
*/
