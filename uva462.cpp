#include <iostream>
using namespace std;
struct Hand{
    int c[4] ; //number of S,H,D,C
    int p[4][4] ; //has A,K,Q,J
    Hand(){
        fill(&c[0],&c[4],0);
        fill(&p[0][0],&p[4][0],0);
    }
};
int isStop(Hand &h){
    int cnt = 0;
    for(int i=0;i<4;i++){
        int flag = 0;
        if(h.p[i][0] == 1)flag = 1;
        if(h.p[i][1] == 1 && h.c[i] > 1)flag = 1;
        if(h.p[i][2] == 1 && h.c[i] > 2)flag = 1;
        cnt += flag;
    }
    return cnt;
}
int calPoint(Hand &h){
    int cnt = 0;
    for(int i=0;i<4;i++){
        cnt += h.p[i][0] * 4 + h.p[i][1] * 3 + h.p[i][2] * 2 + h.p[i][3];
    }
    for(int i=0;i<4;i++){   //one king
        if(h.p[i][1] == 1 && h.c[i] == 1)cnt--;
    }
    for(int i=0;i<4;i++){   //two queen
        if(h.p[i][2] == 1 && h.c[i] <= 2)cnt--;
    }
    for(int i=0;i<4;i++){   //three jack
        if(h.p[i][3] == 1 && h.c[i] <= 3)cnt--;
    }
    for(int i=0;i<4;i++){   //add for two
        if(h.c[i] == 2)cnt++;
    }
    for(int i=0;i<4;i++){   //add for one
        if(h.c[i] == 1)cnt+=2;
    }
    for(int i=0;i<4;i++){   //add for no
        if(h.c[i] == 0)cnt+=2;
    }
    return cnt;
}
int calNoTrumpPoint(Hand &h){
    int cnt = 0;
    for(int i=0;i<4;i++){
        cnt += h.p[i][0] * 4 + h.p[i][1] * 3 + h.p[i][2] * 2 + h.p[i][3];
    }
    for(int i=0;i<4;i++){   //one king
        if(h.p[i][1] == 1 && h.c[i] == 1)cnt--;
    }
    for(int i=0;i<4;i++){   //two queen
        if(h.p[i][2] == 1 && h.c[i] <= 2)cnt--;
    }
    for(int i=0;i<4;i++){   //three jack
        if(h.p[i][3] == 1 && h.c[i] <= 3)cnt--;
    }
    return cnt;
}
void add(Hand &h,string str){
    int color;
    if(str[1] == 'S')color = 0;
    else if(str[1] == 'H')color = 1;
    else if(str[1] == 'D')color = 2;
    else if(str[1] == 'C')color = 3;
    h.c[color]++;
    if(str[0] == 'A')h.p[color][0]++;
    else if(str[0] == 'K')h.p[color][1]++;
    else if(str[0] == 'Q')h.p[color][2]++;
    else if(str[0] == 'J')h.p[color][3]++;

}
int main (){
    string str;
    while(cin >> str){
        Hand h;
        add(h,str);
        for(int i=0;i<12;i++){
            cin >> str;
            add(h,str);
        }
        if(calNoTrumpPoint(h) >= 16 && isStop(h) == 4){
            cout << "BID NO-TRUMP\n";
            continue;
        }

        //cout << "Point: " << calPoint(h) << "\n";
        if(calPoint(h) >= 14){
            cout << "BID ";
            int MAX=0,pos;
            for(int i=0;i<4;i++){
                if(h.c[i] > MAX){
                    MAX = h.c[i];
                    pos = i;
                }
            }
            switch(pos){
                case 0:cout <<"S\n";break;
                case 1:cout <<"H\n";break;
                case 2:cout <<"D\n";break;
                case 3:cout <<"C\n";break;
            }
            continue;
        }
        cout << "PASS\n";
    }
    return 0;
}
/*
KS QS TH 8H 4H AC QC TC 5C KD QD JD 8D
*/
