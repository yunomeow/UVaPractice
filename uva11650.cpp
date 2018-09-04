#include <iostream>
#include <iomanip>
using namespace std;
int main (){
    int Z,h1,m1,h2,m2;
    char ch;
    cin >> Z;
    while(Z--){
        cin >> h1 >> ch >> m1 ;
        h2 = 12 - h1;
        m2 = 0 - m1;
        if(m2 < 0){m2+=60;h2--;}
        if(h2 < 0)h2 += 12;
        if(h2 == 0)h2 = 12;

        cout << setfill('0') << setw(2)<< h2 << ":" << setfill('0') << setw(2)<< m2 <<"\n";
    }
    return 0;
}
