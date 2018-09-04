#include <iostream>
using namespace std;
string str[] = {"","Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
int mon[15] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
int ans[15][35];
void prep(){
    int m = 1,d = 1,w = 6;
    ans[1][1] = 6;
    while(m<=12){
        d++;
        w++;
        if(w == 8)w = 1;
        if(d == mon[m]+1){
            m++;
            d = 1;
        }
        ans[m][d] = w;
        //cout << m << " " << d <<"\n";
    }
}
int main (){
    int Z,m,d;
    prep();
    cin >> Z;
    while(Z--){
        cin >> m >> d;
        cout << str[ans[m][d]]  <<"\n";
    }
    return 0;
}
