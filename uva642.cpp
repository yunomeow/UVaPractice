#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;
map< string , int > m;
map< string , int >::iterator it;
vector<string> v[105];
int main (){
    string str,sortstr;
    int idx;
    while(cin >> str){
        for(int i=0;i<105;i++)v[i].clear();
        m.clear();
        idx = 0;
        if(str != "XXXXXX"){
            sortstr = str;
            sort(sortstr.begin(),sortstr.end());
            it = m.find(sortstr);
            if(it == m.end())m[sortstr] = idx++;
            v[m[sortstr]].push_back(str);
            while(cin >> str, str != "XXXXXX"){
                sortstr = str;
                sort(sortstr.begin(),sortstr.end());
                it = m.find(sortstr);
                if(it == m.end())m[sortstr] = idx++;
                v[m[sortstr]].push_back(str);
            }
        }
        for(int i=0;i<idx;i++)sort(v[i].begin(),v[i].end());
        while(cin >> str, str != "XXXXXX"){
            sortstr = str;
            sort(sortstr.begin(),sortstr.end());
            it = m.find(sortstr);
            if(it == m.end())cout << "NOT A VALID WORD\n";
            else{
                for(int i=0;i<v[it->second].size();i++){
                    cout << v[it->second][i] << "\n";
                }
            }
            cout << "******\n";
        }


    }
    return 0;
}
