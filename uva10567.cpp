#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v[55];
int conv(char ch){
    if(ch >= 'a' && ch <= 'z')return ch - 'a';
    if(ch >= 'A' && ch <= 'Z')return ch - 'A' + 26;
    return -1;
}
int main (){
    string str;
    cin >> str;
    for(int i=0;i<str.size();i++){
        v[conv(str[i])].push_back(i);
    }
    int Q,now,c,st,ed,flag,p;
    cin >> Q;
    while(Q--){
        cin >> str;
        now = -1;
        st = -1;
        flag = 1;
        for(int i=0;i<str.size();i++){
            c = conv(str[i]);
            p = lower_bound(v[c].begin(),v[c].end(),now+1) - v[c].begin();
            if(p == v[c].size()){flag = 0;break;}
            else now = v[c][p];
            if(st == -1)st = now;
            //cout << "now " << now << "\n";
        }
        if(flag == 0)cout << "Not matched\n";
        else cout << "Matched " << st << " " << now << "\n";
    }
    return 0;
}
