#include <iostream>
#include <queue>
using namespace std;
int main (){
    int Z;
    cin >> Z;
    while(Z--){
        int l,m,a,ans,now;
        string str;
        cin >> l >> m;
        l *= 100;
        queue<int> q1,q2;
        while(m--){
            cin >> a >> str;
            if(str == "left")q1.push(a);
            else q2.push(a);
        }
        ans = 0;
        while(!q1.empty() || !q2.empty()){
            now = 0;
            while(!q1.empty() && now + q1.front() <= l){
                now += q1.front();
                q1.pop();
            }

            ans++;
            now = 0;
            while(!q2.empty() && now + q2.front() <= l){
                now += q2.front();
                q2.pop();
            }
            if(!q1.empty() || !q2.empty() || now > 0)
                ans++;
        }
        cout << ans << "\n";
    }
    return 0;
}
/*
15 4
380 left
720 left
1340 left
1040 left
*/
