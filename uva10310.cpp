#include <iostream>
#include <iomanip>
using namespace std;
typedef long long int64;
struct Point {
    double ox,oy;
    int64 x,y;
}p[1005];
int64 dis(Point a,Point b){
    return (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y);
}
int main (){
    int N,flag,pos;
    cout << fixed << setprecision(3);
    while(cin >> N){
        for(int i=0;i<N+2;i++){
            cin >> p[i].ox >> p[i].oy;
            p[i].x = p[i].ox * 1000;
            p[i].y = p[i].oy * 1000;
        }
        flag = 0;
        for(int i=2;i<N+2;i++){
            if(4ll * dis(p[0],p[i]) <= dis(p[1],p[i])){
                pos = i;
                flag = 1;
                break;
            }
        }
        if(flag == 0)cout <<"The gopher cannot escape.\n";
        else cout << "The gopher can escape through the hole at (" << p[pos].ox << "," << p[pos].oy << ").\n";
    }
    return 0;
}
/*
1 1.000 1.000 2.000 2.000
1.500 1.500

2 2.000 2.000 1.000 1.000
1.500 1.500
2.500 2.500
*/
