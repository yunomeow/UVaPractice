#include <iostream>
#include <cctype>
using namespace std;
int use[10][10];
char MAP[10][10];
int dir[16][2] = {1,0 ,0,1 ,-1,0 ,0,-1,
1,1,1,-1  ,-1,-1 ,-1,1,
1,2 ,-1,2 ,1,-2 ,-1,-2,
2,1 ,-2,1 ,2,-1 ,-2,-1
};
int ok(int x,int y){
    if(x >= 0 && y >= 0 && x < 8 && y < 8)return 1;
    return 0;
}
void print(){
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            cout << use[i][j];
        }
        cout <<"\n";
    }
    cout <<"\n";
}
void move(int x,int y){
    int nx,ny;
    if(MAP[x][y] == 0)return;
    use[x][y] = 1;
    if(MAP[x][y] == 'k' || MAP[x][y] == 'K'){
        for(int i=0;i<8;i++){
            nx = x + dir[i][0];
            ny = y + dir[i][1];
            if(ok(nx,ny))use[nx][ny] = 1;
        }
    }else if(MAP[x][y] == 'r' || MAP[x][y] == 'R'){
        for(int i=0;i<4;i++){
            nx = x + dir[i][0];
            ny = y + dir[i][1];
            while(ok(nx,ny) && MAP[nx][ny] == 0){
                use[nx][ny] = 1;
                nx = nx + dir[i][0];
                ny = ny + dir[i][1];
            }
        }
    }else if(MAP[x][y] == 'n' || MAP[x][y] == 'N'){
        for(int i=8;i<16;i++){
            nx = x + dir[i][0];
            ny = y + dir[i][1];
            if(ok(nx,ny))use[nx][ny] = 1;
        }
    }else if(MAP[x][y] == 'b' || MAP[x][y] == 'B'){
        for(int i=4;i<8;i++){
            nx = x + dir[i][0];
            ny = y + dir[i][1];
            while(ok(nx,ny) && MAP[nx][ny] == 0){
                use[nx][ny] = 1;
                nx = nx + dir[i][0];
                ny = ny + dir[i][1];
            }
        }
    }else if(MAP[x][y] == 'q' || MAP[x][y] == 'Q'){
        for(int i=0;i<8;i++){
            nx = x + dir[i][0];
            ny = y + dir[i][1];
            while(ok(nx,ny) && MAP[nx][ny] == 0){
                use[nx][ny] = 1;
                nx = nx + dir[i][0];
                ny = ny + dir[i][1];
            }
        }

    }else if(MAP[x][y] == 'p'){
        nx = x + dir[4][0];
        ny = y + dir[4][1];
        //cout << "nx : " << nx << " ny: " << ny << "\n";
        if(ok(nx,ny))use[nx][ny] = 1;

        nx = x + dir[5][0];
        ny = y + dir[5][1];
        //cout << "nx : " << nx << " ny: " << ny << "\n";
        if(ok(nx,ny))use[nx][ny] = 1;
    }else if(MAP[x][y] == 'P'){
        nx = x + dir[6][0];
        ny = y + dir[6][1];
        if(ok(nx,ny))use[nx][ny] = 1;
        nx = x + dir[7][0];
        ny = y + dir[7][1];
        if(ok(nx,ny))use[nx][ny] = 1;
    }
  //  cout << "x: " << x << " y: " << y << " "<< MAP[x][y]<<"\n";
   // print();
}

int main (){
    string str;
    while(cin >> str){
        int x=0,y=0;
        fill(&use[0][0],&use[9][0],0);
        fill(&MAP[0][0],&MAP[9][0],0);
        for(int i=0;i<str.size();i++){
            if(str[i] == '/')continue;
            if(isdigit(str[i])){
                y+=str[i]-'0';
            }else{
                MAP[x][y] = str[i];
                y++;
            }
            if(y == 8){
                x++;
                y = 0;
            }
        }
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                move(i,j);
            }
        }
        int ans = 0;
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                if(use[i][j] == 0)ans++;
            }
        }

        cout << ans << "\n";
    }
    return 0;
}
