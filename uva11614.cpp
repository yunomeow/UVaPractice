#include <iostream>
using namespace std;
typedef long long int64 ;
int main (){
    int Z;
    int64 N,l,r,m;
    cin >> Z;
    while(Z--){
        cin >> N;
        l = 0ll;
        r = 2000000000ll;
        while(r > l){
            m = (l + r) / 2;
            if(m*(m+1)/2  > N)r = m-1;
            else l = m+1;
        }
        //cout <<"l: "<< l << "\n";
        for(int64 i=l-2;i<l+2;i++){
            if(i < 0)continue;
            if((i+1)*(i+2)/2 > N){
                cout << i << "\n";
                break;
            }
        }
    }
    return 0;
}
