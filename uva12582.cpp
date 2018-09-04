#include <iostream>
#include <stack>
using namespace std;
int main (){
    int Z;
    string str;
    int cnt[30];
    cin >> Z;
    for(int zi=1;zi<=Z;zi++){
        cin >> str;
        fill(&cnt[0],&cnt[30],0);
        stack<char> s;
        for(int i=0;i<str.size();i++){
            if(!s.empty() && s.top() == str[i])s.pop();
            else{
                s.push(str[i]);
            }
            if(!s.empty())
            cnt[s.top()-'A']++;
        }
        cnt[str[0]-'A']--;
        cout << "Case " << zi << "\n";
        for(int i=0;i<26;i++){
            if(cnt[i] > 0){
                cout << (char)(i+'A') << " = " << cnt[i] << "\n";
            }
        }
    }
    return 0;
}
