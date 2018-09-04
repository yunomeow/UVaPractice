#include <iostream>
using namespace std;
int num[100005];
int main (){
    int N,M,tmp;
    while(cin >> N >> M){
        fill(&num[0],&num[N+1],0);
        for(int i=0;i<M;i++){
            cin >> tmp;
            num[tmp] = 1;
        }
        int isFirst = 1;
        for(int i=1;i<=N;i++){
            if(num[i] == 0){

                cout << i << " ";
                isFirst = 0;
            }
        }
        if(isFirst)cout << "*";
        cout << "\n";
    }
    return 0;
}
