#include <iostream>
using namespace std;
int num[5][5];
int use[5][5];
int order[80];
void read();
void solve();
void putnum(int n){
    for(int i=0;i<5;i++)
        for(int j=0;j<5;j++)
            if(num[i][j] == n){
                use[i][j] = 1;
                return ;
            }
}
int check(){
    int cnt = 0,tmp;
    for(int i=0;i<5;i++){
        tmp = 0;
        for(int j=0;j<5;j++){
            tmp += use[i][j];
        }
        if(tmp == 5)cnt++;
    }
    for(int j=0;j<5;j++){
        tmp = 0;
        for(int i=0;i<5;i++){
            tmp += use[i][j];
        }
        if(tmp == 5)cnt++;
    }
    tmp = 0;
    for(int i=0;i<5;i++){
        tmp += use[i][i];
    }
    if(tmp == 5)cnt++;

    tmp = 0;
    for(int i=0;i<5;i++){
        tmp += use[i][4-i];
    }
    if(tmp == 5)cnt++;
    //cout << "cnt: " << cnt << "\n";
    if(cnt > 0)return 1;
    return 0;
}
int main (){
    int Z;
    cin >> Z;
    while(Z--){
        read(),solve();
    }
    return 0;
}
void read(){
    for(int i=0;i<2;i++)
        for(int j=0;j<5;j++)
            cin >> num[i][j];
    cin >> num[2][0] >> num[2][1] >> num[2][3] >> num[2][4];
    for(int i=3;i<5;i++)
        for(int j=0;j<5;j++)
            cin >> num[i][j];
    for(int i=0;i<75;i++)cin >> order[i];
}
void solve(){
    fill(&use[0][0],&use[5][0],0);
    use[2][2] = 1;
    for(int i = 0;i < 75;i++){
        putnum(order[i]);
        if(check()){
            cout << "BINGO after " << (i+1) << " numbers announced\n";
            return;
        }
    }
}
/*
1
10 17 39 49 64
12 21 36 55 62
14 25 52 70
7 19 32 56 68
5 24 34 54 71
1 2 3 4 5 6 7 8 9 10
11 12 13 14 15 16 17 18 19 20
21 22 23 24 25 26 27 28 29 30
31 32 33 34 35 36 37 38 39 40
41 42 43 44 45 46 47 48 49 50
51 52 53 54 55 56 57 58 59 60
61 62 63 64 65 66 67 68 69 70
71 72 73 74 75
*/
