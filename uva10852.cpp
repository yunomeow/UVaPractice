#include <iostream>
#include <vector>
using namespace std;
vector<int> prime;
int use[10005];
int main (){
    int Z,N,p;
    for(int i=2;i<10005;i++){
        if(use[i] == 0){
            prime.push_back(i);
            for(int j=i+i;j<10005;j+=i)use[j] = 1;
        }
    }
    cin >> Z;
    while(Z--){
        cin >> N;
        for(int i=0;i<prime.size();i++){
            p = 1;
            if(p * prime[i] <= N && (p+1) * prime[i] > N){
                cout << prime[i] << "\n";
                break;
            }
        }
    }
    return 0;
}
