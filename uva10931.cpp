#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N,cnt;
    vector<int> ans ;
    while(cin >> N , N){
        ans.clear();
        cnt = 0;
        while(N > 0){
            ans.push_back(N % 2);
            if(N % 2 == 1)cnt++;
            N /= 2;
        }
        cout << "The parity of ";
        for(int i=ans.size()-1;i>=0;i--)cout << ans[i];
        cout << " is " << cnt << " (mod 2).\n";
    }
    return 0;
}
