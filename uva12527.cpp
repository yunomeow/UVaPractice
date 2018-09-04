#include <iostream>
using namespace std;
int ok[5005],sum[5005];
int check(int n){
    int cnt[10]={};
    while(n > 0){cnt[n % 10]++;n/=10;}
    for(int i=0;i<10;i++)
        if(cnt[i] > 1)return 0;
    return 1;
}
int main (){
    sum[0] = 0;
    for(int i=1;i<5002;i++){
        ok[i] = check(i);
        sum[i] = sum[i-1] + ok[i];
    }
    int a,b;
    while(cin >> a >> b){
        cout << (sum[b] - sum[a-1])  << "\n";
    }
    return 0;
}
