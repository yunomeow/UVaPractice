#include <iostream>
using namespace std;
int num[105][105];
int dis[105][105];
int dir[4][2] = {1,0,0,1,-1,0,0,-1};
int main (){
    int R,C,Z,x,y,ans;
    string str;
    cin >> Z;
    while(Z--){
        cin >> str >> R >> C;
        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++)
                cin >> num[i][j];
        }
        fill(&dis[0][0],&dis[R+1][0],1);
        ans = 0;
        for(int k= 100;k>=0;k--){
            for(int i=0;i<R;i++){
                for(int j=0;j<C;j++){
                    if(num[i][j] == k){
                        for(int d=0;d<4;d++){
                            x = i + dir[d][0];
                            y = j + dir[d][1];
                            if(x >= 0 && y >= 0 && x < R && y < C){
                                if(num[x][y] > num[i][j])
                                    dis[i][j] = max(dis[i][j],1+dis[x][y]);
                            }
                        }
                        ans = max(ans,dis[i][j]);
                    }
                }
            }
        }
        cout << str << ": " << ans <<"\n";
    }
    return 0;
}
