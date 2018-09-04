#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;
int sum,N;
int gcd(int a,int b){
    while((a%=b) && (b%=a));
    return a+b;
}
void solve(int zi){
    cout << "Case " << zi << ":\n";
    if(sum % N == 0){
        if(sum < 0)cout << "- " << abs(sum) / N << "\n";
        else cout << sum / N << "\n";
        return ;
    }
    int offset = 0,aoffset = 0;
    int a,b,c,g,cnt,tmp;
    a = abs(sum / N);
    b = abs(sum) % N;
    c = N;
    g = gcd(b,c);
    b /= g;
    c /= g;
    tmp = a;
    while(tmp > 0){
        offset++;
        tmp /= 10;
        aoffset++;
    }
    tmp = c;
    while(tmp > 0){
        offset++;
        tmp /= 10;
    }
    if(sum < 0)cout << "  ";
    cout << setw(offset) << b << "\n";
    if(sum < 0)cout << "- ";
    if(a > 0)cout << a ;
    for(int i=0;i<offset-aoffset;i++)cout <<"-";
    cout << "\n";
    if(sum < 0)cout << "  ";
    cout << setw(offset) << c << "\n";
}
int main (){
    int tmp,zi=1;
    while(cin >> N,N){
        sum = 0;
        for(int i=0;i<N;i++){
            cin >> tmp;
            sum += tmp;
        }
        solve(zi++);
    }
    return 0;
}
