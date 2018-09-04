#include <iostream>
using namespace std;
int cnt[105];
int main (){
    int Z,N;
    cin >> Z;
    for(int zi=1;zi<=Z;zi++){
        cout << "Case " << zi << ": ";
        cin >> N;
        int tmp;
        fill(&cnt[0],&cnt[N+1],0);
        for(int i=1;i<=N*N;i++){
            cin >> tmp;
            cnt[tmp]++;
        }
        int flag=1;
        for(int i=0;i<=N;i++){
            if(cnt[i] > N)flag = 0;
        }
        if(flag)cout << "yes\n";
        else cout <<"no\n";
    }
    return 0;
}
