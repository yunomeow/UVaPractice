#include <iostream>
using namespace std;
struct Rect{
    int x1,y1,x2,y2;
}r[2];
int main (){
    int Z,a1,a2,a3;
    int w,h;
    cin >> Z;
    for(int zi=1;zi<=Z;zi++){
        for(int i=0;i<2;i++){
            cin >> r[i].x1 >> r[i].y1 >> r[i].x2 >> r[i].y2;
        }
        w = h = 0;
        if(r[0].y2 > r[1].y1 && r[1].y2 > r[0].y1){
            if(r[0].y1 > r[1].y1 && r[0].y2 < r[1].y2)
                h = r[0].y2 - r[0].y1;
            else if(r[1].y1 > r[0].y1 && r[1].y2 < r[0].y2){
                h = r[1].y2 - r[1].y1;
            }else{
                h = min(r[0].y2 - r[1].y1,r[1].y2 - r[0].y1);
            }
        }
        if(r[0].x2 > r[1].x1 && r[1].x2 > r[0].x1){
            if(r[0].x1 > r[1].x1 && r[0].x2 < r[1].x2)
                w = r[0].x2 - r[0].x1;
            else if(r[1].x1 > r[0].x1 && r[1].x2 < r[0].x2){
                w = r[1].x2 - r[1].x1;
            }else{
                w = min(r[0].x2 - r[1].x1,r[1].x2 - r[0].x1);
            }
        }
        a1 = w * h;
        a2 = (r[0].x2 - r[0].x1) * (r[0].y2 - r[0].y1) + (r[1].x2 - r[1].x1) * (r[1].y2 - r[1].y1) - 2 *a1;
        a3 = 10000 - a1 - a2;
        cout << "Night " << zi << ": " << a1 << " " << a2 << " " << a3 << "\n";
    }
    return 0;
}

