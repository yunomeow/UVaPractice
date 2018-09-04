#include <iostream>
#define INF 2100000000
using namespace std;
char str[10000000];
int pos,len,isEmpty;
int getNum(){
    int tmp=0,neg = 1;

    while(pos < len && (str[pos] == ' ' || str[pos] == '\n'))pos++;
    if(pos == len)return INF;
    if(str[pos] == '-'){neg = -1;pos++;}
    if(!isdigit(str[pos]))return INF;
    while(isdigit(str[pos])){
        tmp = tmp * 10 + str[pos] - '0';
        pos++;
    }
    return tmp * neg;
}
int getTree(int val){
    int flag = 0,res1,num,res2;
    while(pos < len && str[pos] != '(')pos++;
    pos++;
    num = getNum();
    if(num != INF){
        res1 = getTree(val - num);
        if(res1 == 1)flag = 1;
        res2 = getTree(val - num);
        if(res2 == 1)flag = 1;
        if(res1 == 2 && res2 == 2){
            if(val == num)flag = 1;
        }
    }else flag = 2;
    while(pos < len && str[pos] != ')')pos++;
    pos++;
    return flag;
}
void solve(){
    int a;
    pos = 0;
    while(1){
        a = getNum();
        if(a == INF)return;
        if(getTree(a) == 1)
            cout << "yes\n";
        else
            cout << "no\n";
    }
}
void read(){
    char ch;
    len = 0;
    while(cin >> ch)str[len++] = ch;
}
int main (){
    read();
    solve();
    return 0;
}
