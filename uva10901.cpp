#include <iostream>
#include <queue>
using namespace std;
int ans[10005];
struct XD{
    int id,t;
    XD(int _id,int _t){
        id = _id;
        t = _t;
    }
};
queue<XD> q[2];
int t,N;
int go(int side,int now){
    if(!q[0].empty() && !q[1].empty() && now < q[side].front().t && q[side].front().t > q[1 - side].front().t){
        now = max(q[1 - side].front().t + t,now+t);
    }else if(q[side].empty() && !q[1-side].empty()){
        now = max(q[1 - side].front().t + t,now+t);
    }else{
        int nowN;
        if(now < q[side].front().t){
            now = q[side].front().t;
        }
        nowN = 0;
        while(!q[side].empty() && nowN < N && q[side].front().t <= now){
            ans[q[side].front().id] = now + t;
            q[side].pop();
            nowN++;
        }
        now = now + t;
    }
    return now;
}
int main (){
    int now,Z,M,tmp,side;
    string str;
    cin >> Z;
    while(Z--){
        cin >> N >> t >> M;
        for(int i=0;i<M;i++){
            cin >> tmp >> str;
            if(str == "left"){
                q[0].push(XD(i,tmp));
            }else{
                q[1].push(XD(i,tmp));
            }
        }
        now = 0;side = 0;
        while(!q[0].empty() || !q[1].empty()){
            now = go(side,now);
            side = 1-side;
        }
        for(int i=0;i<M;i++)cout << ans[i] << "\n";
        if(Z)cout << "\n";
    }
    return 0;
}
