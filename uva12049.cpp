#include <iostream>
#include <map>
using namespace std;
int main (){
    int Z,tmp,N,M;
    map<int,int> m1,m2;
    map<int,int>::iterator it;
    cin >> Z;
    while(Z--){
        int ans = 0;
        cin >> N >> M;
        m1.clear();
        m2.clear();
        for(int i=0;i<N;i++){
            cin >> tmp;
            m1[tmp]++;
        }
        for(int i=0;i<M;i++){
            cin >> tmp;
            m2[tmp]++;
        }
        int c1,c2;
        for(it=m1.begin();it!=m1.end();it++){
            c1 = it->second;
            c2 = m2[it->first];
            if(c1 >= c2){
                m2[it->first] = 0;
                ans += c1-c2;
            }else{
                c2 -= c1;
                m2[it->first] = c2;
            }
        }
        for(it=m2.begin();it!=m2.end();it++){
            ans += it->second;
        }
        cout << ans <<"\n";
    }
    return 0;
}
