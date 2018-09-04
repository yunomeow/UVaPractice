#include <iostream>
using namespace std;
int main (){
    int Z,N;
    cin >> Z;
    int num[1005],ans;
    while(Z--){
        cin >> N;
        for(int i=0;i<N;i++)cin >> num[i];
        ans = 0;
        for(int i=0;i<N;i++){
            for(int j=0;j<i;j++){
                if(num[j] <= num[i])ans++;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
