#include <iostream>
using namespace std;
struct Card{
    char val,type;
}card[55];
int cal(char ch){
    if(ch >= '2' && ch <= '9')return ch-'0';
    return 10;
}
int main (){
    int Z,X,Y,now,pos;
    string str;
    cin >>Z;
    for(int zi=1;zi<=Z;zi++){
        for(int i=0;i<52;i++){
            cin >> str;
            card[i].val = str[0];
            card[i].type = str[1];
        }
        now = 26;
        Y = 0;
        for(int i=0;i<3;i++){
            X = cal(card[now].val);
            //cout << card[now].val << card[now].type << "\n";
            //cout << "X = "<< X << "\n";
            Y += X;
            now = now - 11 + X;
        }
        if(Y-1 < now){
            pos = Y-1;
        }else{
            Y -= now;
            pos = 26 + Y - 1;
        }
       // cout << "Y = " << Y <<"\n";
        cout << "Case " << zi << ": " << card[pos].val << card[pos].type << "\n";
    }
    return 0;
}
