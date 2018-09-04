#include <iostream>
#include <vector>
#define MAX 10000005
#define sz(x) (int)x.size()
using namespace std;
int use[MAX];
vector<int> prime;
void solve(int n){
    for(int i = 0;i <sz(prime);i++){
        if(use[n - prime[i]] == 0){
            cout << " " << prime[i] << " " << (n-prime[i]) ;
            return ;
        }
    }
}
int main (){
    int N;
    use[0] = use[1] = 1;
    for(int i=2;i<MAX;i++){
        if(use[i] == 0){
            prime.push_back(i);
            for(int j=i+i;j<MAX;j+=i){
                use[j] = 1;
            }
        }
    }
    while(cin >> N){
        if(N >= 8){
            if(N % 2){
                cout << "2 3";
                solve(N-5);
                cout << "\n";
            }else{
                cout << "2 2";
                solve(N-4);
                cout << "\n";
            }
        }else cout <<"Impossible.\n";
    }
    return 0;
}
