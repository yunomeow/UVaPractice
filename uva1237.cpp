#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
struct Event{
    string name;
    int val;
    int type;
    int id;
    Event(string _s,int _t,int _id,int _v){
        name = _s;
        type = _t;  // 1 in 2 query 3 out
        id = _id;
        val = _v;
    }
};
string ans[1005];
vector<Event> ev;
bool cmp(Event a,Event b){
    if(a.val != b.val)return a.val < b.val;
    return a.type < b.type;
}
void solve(){
    set<string> s;
    for(int i=0;i<(int)ev.size();i++){
        if(ev[i].type == 1){
            s.insert(ev[i].name);
        }else if(ev[i].type == 2){
            if(s.size() != 1)ans[ev[i].id] = "UNDETERMINED";
            else ans[ev[i].id] = *s.begin();
        }else{
            s.erase(ev[i].name);
        }
    }
}
int main (){
    int Z,N,Q,qid;
    string str;
    int a,b;
    cin >> Z;
    while(Z--){
        cin >> N;
        ev.clear();
        while(N--){
            cin >> str >> a >> b;
            ev.push_back(Event(str,1,0,a));
            ev.push_back(Event(str,3,0,b));
        }
        cin >> Q;
        qid = 0;
        while(Q--){
            cin >> a;
            ev.push_back(Event(str,2,qid++,a));
        }
        sort(ev.begin(),ev.end(),cmp);
        solve();
        for(int i=0;i<qid;i++){
            cout << ans[i] << "\n";
        }
        if(Z)cout << "\n";
    }
    return 0;
}
