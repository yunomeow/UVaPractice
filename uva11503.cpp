#include <iostream>
#include <map>
using namespace std;
int sum[200005];
int par[200005];
map<string,int> m;
map<string,int>::iterator it;
int find_par(int pos){
    if(par[pos]== pos)return pos;
    par[pos] = find_par(par[pos]);
    return par[pos];
}
void Union(int x,int y){
    int sx = find_par(x);
    int sy = find_par(y);
    sum[sx] = sum[sx] + sum[sy];
    par[sy] = sx;
}
int main (){
    int Z,M,id,a,b;
    string s1,s2;
    cin >> Z;
    while(Z--){
        cin >> M;
        id = 1;
        m.clear();
        while(M--){
            cin >> s1 >> s2;
            it = m.find(s1);
            if(it == m.end()){
                m[s1] = id;
                par[id] = id;
                sum[id] = 1;
                id++;
            }
            it = m.find(s2);
            if(it == m.end()){
                m[s2] = id;
                par[id] = id;
                sum[id] = 1;
                id++;
            }
            a = m[s1];
            b = m[s2];
            if(find_par(a) != find_par(b)){
                Union(a,b);
            }
            cout << sum[find_par(a)] << "\n";
        }
    }
    return 0;
}
/*
1
3
Fred Barney
Barney Betty
Betty Wilma
*/
