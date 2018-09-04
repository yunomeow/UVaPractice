#include <iostream>
using namespace std;
int main (){
    int ans,Z,tmp,N;
    cin >> Z;
    for(int zi=1;zi<=Z;zi++){
        cin >> N;
        ans = 0;
        while(N--){
            cin >> tmp;
            ans = max(ans,tmp);
        }
        cout << "Case " << zi << ": " << ans <<"\n";
    }
    return 0;
}
