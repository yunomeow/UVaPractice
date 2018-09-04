#include <iostream>
using namespace std;
typedef long long int64;
int main (){
    int64 N,P,now,sum,pos,offset,x,y,t,len;
    int64 idx;
    while(cin >> N >> P, N+P){

        for(int64 i=1;i<100000;i+=2){
            if(i*i < P && (i+2)*(i+2) >= P){
                now = i;
                break;
            }
        }
        if(P != 1){
            pos = P - now * now;
            t = (pos-1) / (now+2 - 1);
            pos = pos % (now+2 - 1);
            if(pos == 0)pos = (now+2-1);
            offset = (N - now - 2)/2;
            len = now+2-1;
            idx = (pos) % len;
            if(idx == 0)idx = len;
            switch(t){
                case 0:
                    x = now+2;
                    y = len - idx + 1;
                    break;
                case 1:
                    x = len - idx + 1;
                    y = 1;
                    break;
                case 2:
                    x = 1;
                    y = idx+1;
                    break;
                case 3:
                    x = idx+1;
                    y = now+2;
                    break;
            }
        }else {
            x = 1;
            y = 1;
            offset = (N/2);
        }

        x = x+offset;
        y = y+offset;
        cout << "Line = " << x << ", column = " << y << ".\n";
    }
    return 0;
}
