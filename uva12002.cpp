#include <iostream>
using namespace std;
int LIS[505],LDS[505],num[505];
int main (){
    int N;
    while(cin >> N , N){
        for(int i=0;i<N;i++){
            cin >> num[i];
        }
        fill(&LIS[0],&LIS[N+1],1);
        fill(&LDS[0],&LDS[N+1],1);
        for(int i=N-2;i>=0;i--){
            for(int j=i+1;j<N;j++){
                if(num[i] >= num[j])
                    LDS[i] = max(LDS[i],LDS[j]+1);
            }
        }
        for(int i=N-2;i>=0;i--){
            for(int j=i+1;j<N;j++){
                if(num[i] <= num[j])
                    LIS[i] = max(LIS[i],LIS[j]+1);
            }
        }
        int ans = 1,cnt,ni,nd;
        for(int i=N-2;i>=0;i--){
            ans = max(ans , max(LIS[i],LDS[i]));
            for(int j=i+1;j<N;j++){
                if(num[i] == num[j])continue;
                else if(num[i] > num[j]){
                    ans = max(ans,LIS[i] + LDS[j]);
                }else{
                    ans = max(ans,LIS[j] + LDS[i]);
                }

            }
        }
        cout << ans <<"\n";
    }
    return 0;
}
