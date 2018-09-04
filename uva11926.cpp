#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <queue>
using namespace std;
struct Event{
    int t;
    int type;
    int c;
    Event(){
    }
    Event(int _t,int _ty,int _c){
        t = _t;
        type = _ty;
        c = _c;
    }
    bool operator < (const Event &a)const{
        if(t != a.t) return t > a.t;
        return type < a.type;
    }
};
bool cmp(Event a,Event b){
    if(a.t != b.t)return a.t < b.t;
    return a.type > b.type;
}
int main (){
    int N,M,a,b,c;
    vector<Event> ev;
    while(cin >> N >> M, N+M){
        ev.clear();
        for(int i=0;i<N;i++){
            scanf("%d%d",&a,&b);
            ev.push_back(Event(a,0,0));
            ev.push_back(Event(b,1,0));
        }

        int cnt = 0,flag = 1;
        sort(ev.begin(),ev.end(),cmp);
        priority_queue<Event> pq;
        for(int i=0;i<M;i++){
            //cin >> a >> b >> c;
            scanf("%d%d%d",&a,&b,&c);
            pq.push(Event(a,0,c));
            pq.push(Event(b,1,c));
        }
        Event e;
        for(int i=0;i<ev.size();i++){
            if(flag == 0)break;
            while(!pq.empty()){
                e = pq.top();
                //cout << "e: "<< e.t << " " << ev[i].t <<" " << cnt<<"\n";
                if(e.t < ev[i].t){
                    if(e.type == 0){
                        cnt++;
                    }else{
                        cnt--;
                    }
                }else if(e.t == ev[i].t){
                    if(e.type == 1){
                        cnt--;
                    }else break;
                }else{
                    break;
                }
                if(cnt > 1){flag = 0;break;}
                e.t += e.c;
                pq.pop();
                pq.push(e);
            }
            if(ev[i].type == 0){
                cnt++;
            }else{
                cnt--;
             }
            if(cnt > 1){flag = 0;break;}
        }

        while(!pq.empty()){
            e = pq.top();
            if(e.t > 1000000)break;
            if(e.type == 0){
                cnt++;
            }else{
                cnt--;
            }
            if(cnt > 1){flag = 0;break;}
            e.t += e.c;
            pq.pop();
            pq.push(e);
        }
        if(flag)cout << "NO CONFLICT\n";
        else cout << "CONFLICT\n";
    }
    return 0;
}
