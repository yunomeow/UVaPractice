#include <iostream>
using namespace std;
int c1[3],c2[3];
int use[56];
int per[6][3]={0,1,2,0,2,1,1,0,2,1,2,0,2,0,1,2,1,0};
int check(int n){
    int cnt = 3,t;
    c2[2] = n;
    for(int i=0;i<6;i++){
        t = 0;
        for(int j=0;j<3;j++){
            if(c1[per[i][j]] < c2[j]){
                t++;
            }
        }
        cnt = min(cnt,t);
    }
    if(cnt >= 2)
        return 1;
    else
        return 0;
}
int main (){
    while(cin >> c1[0] >> c1[1] >> c1[2] >> c2[0] >> c2[1],c1[0]+c1[1]+c1[2]+c2[0]+c2[1]){
        fill(&use[0],&use[53],0);
        use[c1[0]] = 1;
        use[c1[1]] = 1;
        use[c1[2]] = 1;
        use[c2[0]] = 1;
        use[c2[1]] = 1;
        int flag =0;
        for(int i=1;i<=52;i++){
            if(use[i] == 1)continue;
            if(check(i)){
                cout << i << "\n";
                flag = 1;
                break;
            }
        }
        if(flag == 0)cout << "-1\n";
    }
    return 0;
}
