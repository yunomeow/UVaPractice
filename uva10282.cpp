#include <iostream>
#include <map>
#include <sstream>
using namespace std;
int main (){
    string str,s1,s2;
    map<string,string> m;
    map<string,string>::iterator it;
    ios::sync_with_stdio(false);
    while(getline(cin,str) , str != ""){
        istringstream iss(str);
        iss >> s1 >> s2;
        m[s2] = s1;
    }
    while(cin >> s1){
        it = m.find(s1);
        if(it != m.end())cout << m[s1] <<"\n";
        else cout << "eh\n";
    }
    return 0;
}
