#include <iostream>
#include <algorithm>
using namespace std;
int ok[200];
void solve(){
    int m,h,cnt=0;
    m = h = 0;
    for(int i=0;i<720;i++){
        m = (m + 12) % 720;
        h = (h + 1) % 720;
        cnt++;
        if(cnt == 12 && abs(m - h) % 2 == 0){
            ok[min((h-m+720)%720,(m-h+720)%720)/2] = 1;
            //cout << "h = " << h << " m = " << m << " ";
            //cout << min((h-m+720)%720,(m-h+720)%720)/2 << "\n";
        }
        if(cnt == 12)cnt = 0;
    }
}
int main (){
    solve();
    int N;
    while(cin >> N){
        if(ok[N])cout << "Y\n";
        else cout << "N\n";
    }
    return 0;
}
