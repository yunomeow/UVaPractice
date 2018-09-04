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
int isKing(int x,int y,int type){
    if(type == 0 && MAP[x][y] == 'K')return 1;
    if(type == 1 && MAP[x][y] == 'k')return 1;
    return 0;
}
int move(int x,int y,int type){
    int nx,ny;
    if(MAP[x][y] == '.')return 0;
    if(MAP[x][y] == 'k' || MAP[x][y] == 'K'){
        for(int i=0;i<8;i++){
            nx = x + dir[i][0];
            ny = y + dir[i][1];
            if(ok(nx,ny)){
                if(isKing(nx,ny,type))return 1;
            }
        }
    }else if(MAP[x][y] == 'r' || MAP[x][y] == 'R'){
        for(int i=0;i<4;i++){
            nx = x + dir[i][0];
            ny = y + dir[i][1];
            while(ok(nx,ny) && MAP[nx][ny] == '.'){
                use[nx][ny] = 1;
                nx = nx + dir[i][0];
                ny = ny + dir[i][1];
            }
            if(ok(nx,ny) && isKing(nx,ny,type))return 1;
        }
    }else if(MAP[x][y] == 'n' || MAP[x][y] == 'N'){
        for(int i=8;i<16;i++){
            nx = x + dir[i][0];
            ny = y + dir[i][1];
            if(ok(nx,ny) && isKing(nx,ny,type))return 1;
        }
    }else if(MAP[x][y] == 'b' || MAP[x][y] == 'B'){
        for(int i=4;i<8;i++){
            nx = x + dir[i][0];
            ny = y + dir[i][1];
            while(ok(nx,ny) && MAP[nx][ny] == '.'){
                use[nx][ny] = 1;
                nx = nx + dir[i][0];
                ny = ny + dir[i][1];
            }
            if(ok(nx,ny) && isKing(nx,ny,type))return 1;
        }
    }else if(MAP[x][y] == 'q' || MAP[x][y] == 'Q'){
        for(int i=0;i<8;i++){
            nx = x + dir[i][0];
            ny = y + dir[i][1];
            while(ok(nx,ny) && MAP[nx][ny] == '.'){
                use[nx][ny] = 1;
                nx = nx + dir[i][0];
                ny = ny + dir[i][1];
            }
            if(ok(nx,ny) && isKing(nx,ny,type))return 1;
        }

    }else if(MAP[x][y] == 'p'){
        nx = x + dir[4][0];
        ny = y + dir[4][1];
        //cout << "nx : " << nx << " ny: " << ny << "\n";
        if(ok(nx,ny) && isKing(nx,ny,type))return 1;

        nx = x + dir[5][0];
        ny = y + dir[5][1];
        //cout << "nx : " << nx << " ny: " << ny << "\n";
        if(ok(nx,ny) && isKing(nx,ny,type))return 1;
    }else if(MAP[x][y] == 'P'){
        nx = x + dir[6][0];
        ny = y + dir[6][1];
        if(ok(nx,ny) && isKing(nx,ny,type))return 1;
        nx = x + dir[7][0];
        ny = y + dir[7][1];
        if(ok(nx,ny) && isKing(nx,ny,type))return 1;
    }
  //  cout << "x: " << x << " y: " << y << " "<< MAP[x][y]<<"\n";
   // print();
   return 0;
}

int main (){
    string str;
    int isEnd,zi=1;
    while(1){
        int x=0,y=0;
        isEnd = 1;
        for(int i=0;i<8;i++)cin >> MAP[i];
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++)
                if(MAP[i][j] != '.')isEnd = 0;
        }
        if(isEnd)break;
        int flag = 0;
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                if(MAP[i][j] >= 'a' && MAP[i][j] <= 'z'){
                    if(move(i,j,0)){
                        flag = 1;
                        break;
                    }
                }
            }
            if(flag == 1)break;
        }
        if(flag == 1){
            cout << "Game #" << zi++ << ": white king is in check.\n";
            continue;
        }

        flag = 0;
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                if(MAP[i][j] >= 'A' && MAP[i][j] <= 'Z'){
                    if(move(i,j,1)){
                        flag = 1;
                        break;
                    }
                }
            }
            if(flag == 1)break;
        }
        if(flag == 1){
            cout << "Game #" << zi++ << ": black king is in check.\n";
            continue;
        }
        cout << "Game #" << zi++ << ": no king is in check.\n";
    }
    return 0;
}
