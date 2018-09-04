#include <iostream>
#include <map>
using namespace std;
int main (){
    int Z,tmp,N;
    map<int,int> m;
    map<int,int>::iterator it;
    cin >> Z;
    while(Z--){
        cin >> N;
        m.clear();
        int ans = 0,now = -1;
        for(int i=0;i<N;i++){
            cin >> tmp;
            it = m.find(tmp);
            if(it != m.end()){
                now = max(m[tmp],now);
            }
            ans = max(ans,i-now);
            m[tmp] = i;
        }
        cout << ans << "\n";
    }
    return 0;
}
