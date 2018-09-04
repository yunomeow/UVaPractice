#include <iostream>
using namespace std;
struct XD{int x,w;}data[1005];
int main (){
    int Z,W,N,now,ans,load;
    cin >> Z;
    while(Z--){
        cin >> W >> N;
        for(int i=1;i<=N;i++){
            cin >> data[i].x >> data[i].w;
        }
        data[0].x = 0;data[0].w = 0;
        now = 1;
        ans = 0;
        while(now <= N){
            //cout << "now " << now <<"\n";
            load = data[now].w;
            ans += data[now].x;
            if(load == W || now+1 > N){
                ans += data[now].x;
                now++;
                continue;
            }
            while(now+1 <= N && load < W){
                ans += data[now+1].x - data[now].x;
                if(load + data[now+1].w > W){
                    ans += data[now+1].x;
                    now++;
                    break;
                }else if(load + data[now+1].w  == W || now+1 == N){
                    ans += data[now+1].x;
                    now=now+2;
                    break;
                }
                load += data[now+1].w;
                now++;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
/*
3
2 2
1 1
2 2
6 3
1 1
2 2
3 3
3 3
1 2
2 2
3 1

*/
