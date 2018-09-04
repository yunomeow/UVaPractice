#include <iostream>
using namespace std;
int use[5][5];
int put[5][5];
int dir[8][2]={1,2,-1,2,1,-2,-1,-2,2,1,-2,1,2,-1,-2,-1};
void print(){
    int cnt = 0;
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            cnt += put[i][j];
        }
    }
    if(cnt < 12)return ;
    cout <<"----------------------\n";
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            cout << put[i][j];
        }
        cout << "\n";
    }
    cout << "cnt = " << cnt <<"\n";
}
void dfs(int x,int y){
    int nx,ny;
    if(x == 5){
        print();
        return ;
    }
    if(y == 5){
        dfs(x+1,0);
        return ;
    }
    if(use[x][y] == 0){
        put[x][y] = 1;
        use[x][y] ++;
        for(int i=0;i<8;i++){
            nx = x + dir[i][0];
            ny = y + dir[i][1];
            if(nx >= 0 && ny >= 0 && nx < 5 && ny < 5){
                use[nx][ny]++;
            }
        }
        dfs(x,y+1);
        put[x][y] = 0;
        use[x][y] --;
        for(int i=0;i<8;i++){
            nx = x + dir[i][0];
            ny = y + dir[i][1];
            if(nx >= 0 && ny >= 0 && nx < 5 && ny < 5){
                use[nx][ny]--;
            }
        }
    }
    dfs(x,y+1);
}
int main (){
    int N,M,ans;
    while(cin >> N >> M , N+M){
        if(N == 1 || M == 1)ans = N*M;
        else if(N == 2 || M == 2){
            if(N == 2)ans = N * ((M+3)/ 4) + N * ((M+2) / 4);
            else ans = M * ((N+3)/ 4) + M * ((N+2) / 4);
        }else{
            ans = ((N+1)/2) * ((M+1)/2) + (N/2) * (M/2);
        }
        cout << ans << " knights may be placed on a " << N << " row " << M << " column board.\n";
    }
    return 0;
}
/*
2 3
5 5
4 7
0 0
*/
