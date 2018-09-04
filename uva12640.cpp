#include <iostream>
#include <sstream>
using namespace std;
int num[100005];
string str;
int main (){
    int tmp,N,ans;
    while(getline(cin,str)){
        istringstream iss(str);
        N = 0;
        while(iss >> tmp){
            num[N] = tmp;
            N++;
        }
        ans = 0;
        tmp = 0;
        for(int i=0;i<N;i++){
            tmp = tmp + num[i];
            if(tmp < 0)tmp = 0;
            ans = max(ans,tmp);
        }
        cout << ans << "\n";
    }
    return 0;
}
