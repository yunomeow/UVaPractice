#include <iostream>
#include <sstream>
using namespace std;
int use[100005];
int main (){
    string str,ss;
    use[0] = use[1] = 1;
    for(int i=2;i<100005;i++){
        if(use[i] == 0){
            for(int j=i+i;j<100005;j+=i){
                use[j] = 1;
            }
        }
    }
    while(cin >> str, str != "0"){
        int ans = 0,tmp;
        for(int i=0;i<str.size();i++){
            for(int j=1;j<=5 && i+j <= str.size();j++){
                ss = str.substr(i,j);
                //cout << ss << "\n";
                istringstream iss(ss);
                iss >> tmp;
                if(use[tmp] == 0){
                    ans = max(ans,tmp);
                }
            }
        }
        cout << ans <<"\n";
    }
    return 0;
}
