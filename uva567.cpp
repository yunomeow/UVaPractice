#include <iostream>
#include <iomanip>
using namespace std;
int dis[25][25];
const int kInf = 100000000;
int main (){
    int N,tmp,zi=1;
    while(cin >> N){
        fill(&dis[0][0],&dis[21][0],kInf);
        for(int i=1;i<=20;i++)dis[i][i] = 0;
        for(int i=0;i<N;i++){
            cin >> tmp;
            dis[1][tmp] = 1;
            dis[tmp][1] = 1;
        }
        for(int i=2;i<=19;i++){
            cin >>N;
            while(N--){
                cin >> tmp;
                dis[i][tmp] = 1;
                dis[tmp][i] = 1;
            }
        }
        for(int k=1;k<=20;k++){
            for(int i=1;i<=20;i++){
                for(int j=1;j<=20;j++){
                    dis[i][j] = min(dis[i][j],dis[i][k] + dis[k][j]);
                }
            }
        }
        cin >> N;
        int a,b;
        cout <<"Test Set #" << zi++ << "\n";
        while(N--){
            cin >> a >> b;
            cout << setw(2) << a <<" to " << setw(2)<< b << ": " << dis[a][b] << "\n";
        }
        cout << "\n";
    }
    return 0;
}
