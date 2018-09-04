#include <iostream>
#include <algorithm>
using namespace std;
int main (){
    string s,s2;
    long long a,b;
    while(cin >> s){
        sort(s.begin(),s.end());
        s2 = s;
        reverse(s2.begin(),s2.end());
        for(int i=0;i<s.length();i++){
            if(s[i] != '0'){
                char tmp = s[i];
                s[i] = s[0];
                s[0] = tmp;
                //cout << "OAO";
                break;
            }
        }
        a = b = 0;
        for(int i=0;i<s.length();i++){
            a = a * 10 + s[i] - '0';
            b = b * 10 + s2[i] - '0';
        }
        cout << b << " - " << a << " = " << (b-a) << " = 9 * " << (b-a)/9 << "\n";
    }
    return 0;
}
