#include <iostream>
#include <algorithm>
using namespace std;
int b[10005],s[10005];
int main(){
    int B,S,zi =1;
    while(cin >> B >>S ,B+S){
        for(int i=0;i<B;i++){
            cin >> b[i];
        }
        sort(b,b+B);
        for(int i=0;i<S;i++)
            cin >> s[i];
        if(B <= S){
            cout << "Case " << zi++ << ": 0\n";
        }else{
            cout << "Case " << zi++ << ": " << (B-S) << " "<< b[0] << "\n";
        }
    }
    return 0;
}
