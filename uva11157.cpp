#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;
struct XD{
    int type;
    int d;
    XD(int _t,int _d):type(_t),d(_d){}
    bool operator < (const XD &b)const{
        return d < b.d;
    }
};
vector<XD> v,v1,v2;
int main (){
    int Z,ans,N,D,d;
    string str;
    char ch;
    cin >> Z;
    for(int zi=1;zi<=Z;zi++){
        ans = 0;
        cin >> N >> D;
        v.clear();
        v1.clear();
        v2.clear();
        v.push_back(XD(0,0));
        for(int i=0;i<N;i++){
            cin >> str;
            istringstream iss(str);
            ch = iss.get();
            iss.get();
            iss >> d;
            if(ch == 'B'){
                v.push_back(XD(0,d));
            }else{
                v.push_back(XD(1,d));
            }
        }

        v.push_back(XD(0,D));
        int cnt = 0;
        for(int i=0;i<(int)v.size();i++){
            if(v[i].type == 0){
                v1.push_back(v[i]);
                v2.push_back(v[i]);
                cnt = 0;
            }else{
                if(cnt % 2 == 0)v1.push_back(v[i]);
                else v2.push_back(v[i]);
                cnt++;
            }
        }
        for(int i=0;i<(int)v1.size()-1;i++){
            ans = max(ans , v1[i+1].d - v1[i].d);
        }
        for(int i=0;i<(int)v2.size()-1;i++){
            ans = max(ans , v2[i+1].d - v2[i].d);
        }
        cout << "Case " << zi << ": " << ans << "\n";
    }
    return 0;
}
