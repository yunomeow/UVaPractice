#include <iostream>
using namespace std;
int use[1005];
int main (){
    int zi = 1;
    string s;
    while(cin >> s, s != "end"){
        int flag=1,ans = -1,now;
        fill(&use[0],&use[1001],0);
        while(flag == 1){
            ans++;
            now = 300;
            flag = 0;
            for(int i=0;i<s.length();i++){
                if(use[i] == 0 && s[i] <= now){
                    now = s[i];
                    use[i] = 1;
                    flag = 1;
                }
            }
        }
        cout << "Case " << zi++ << ": " << ans << "\n";
    }
    return 0;
}
/*
A
CBACBACBACBACBA
CCCCBBBBAAAA
ACMICPC
end
*/
