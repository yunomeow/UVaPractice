#include <iostream>
#include <queue>
using namespace std;
string MAP[35];
int dir[4][2] = {1,0,0,1,-1,0,0,-1};
int main (){
    int Z,n;
    cin >> Z;
    cin.get();
    while(Z--){
        n = 0;
        while(getline(cin,MAP[n++]), MAP[n-1] != "_____");
        n--;
        queue<int> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<MAP[i].size();j++){
                if(MAP[i][j] == '*'){
                    q.push(i);
                    q.push(j);
                    MAP[i][j] = '#';
                }
            }
        }
        int x,y,nx,ny;
        while(!q.empty()){
            x = q.front();q.pop();
            y = q.front();q.pop();
            for(int i=0;i<4;i++){
                nx = x + dir[i][0];
                ny = y + dir[i][1];
                if(MAP[nx][ny] == ' '){
                    q.push(nx);q.push(ny);
                    MAP[nx][ny] = '#';
                }
            }
        }
        for(int i=0;i<n;i++)cout << MAP[i] << "\n";
        cout << "_____\n";
    }
    return 0;
}
