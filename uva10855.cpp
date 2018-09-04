#include <iostream>
#include <vector>
using namespace std;
struct XD{
    vector<string> v;
};
XD rotate(XD a){
    XD res = a;
    int R,C;
    R = (int)a.v.size();
    C = (int)a.v[0].size();
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            res.v[i][j] = a.v[R-j-1][i];
        }
    }
    return res;
}
int match(XD &a,XD &b){
    int R,C,r,c,res=0;
    R = (int)a.v.size();
    C = (int)a.v[0].size();
    r = (int)b.v.size();
    c = (int)b.v[0].size();
    for(int i=0;i+r<=R;i++){
        for(int j=0;j+c<=C;j++){
            int flag = 1;
            for(int k=0;k<r;k++){
                for(int l=0;l<c;l++){
                    if(a.v[i+k][j+l] != b.v[k][l]){flag = 0;break;}
                }
                if(flag == 0)break;
            }
            if(flag)res++;
        }
    }
    return res;
}
int main (){
    int N,M;
    while(cin >> N >> M, N+M){
        XD a,b;
        string str;
        for(int i=0;i<N;i++){
            cin >> str;
            a.v.push_back(str);
        }
        for(int i=0;i<M;i++){
            cin >> str;
            b.v.push_back(str);
        }
        for(int j=0;j<4;j++){

            if(j)cout<<" ";
            cout << match(a,b);
            b = rotate(b);
            //for(int i=0;i<M;i++)cout << b.v[i] << "\n";
        }
        cout << "\n";
    }
    return 0;
}
