#include <iostream>
#include <sstream>
using namespace std;
int C[50][50]; //S = 26+10+1 = 37 E = 38
int S = 36,E = 37;
const int kInf = 2100000000;
int total,flag;
void make_edge(string str,string str2){
    int a,n,b;
    a = str[0] - 'A';
    n = str[1] - '0';
    C[S][a] = n;
    //cout << "n = " << n << "\n";
    total += n;
    for(int i=0;i<str2.size()-1;i++){
        b = str2[i] - '0' + 26;
        C[a][b] = 1;
       // cout << "a = " << a << " b = " << b << "\n";
    }
    //cout << "make " << str <<" " << str2;
}
int vis[50];
int make_flow(int v,int f){
    if(v == E){
        flag = 1;
        //cout << "ret f " << f << "\n";
        return f;
    }
   // cout << "inf = " << f << "\n";
    vis[v] = 1;
    for(int i=0;i<=E;i++){
        if(vis[i] == 1)continue;
        if(C[v][i] > 0){
            int tf = make_flow(i,min(f,C[v][i]));
            if(flag == 1){
                C[v][i] -= tf;
                C[i][v] += tf;
                vis[v] = 0;
                return tf;
            }
        }
    }
    vis[v] = 0;
}
int main (){
    int N;
    int a,n;
    string str,str2,in;
    while(getline(cin,in)){
        fill(&C[0][0],&C[50][0],0);
        total = 0;
        istringstream iss(in);
        iss >> str >> str2;
        //cout << "OAO\n";
        for(int i=0;i<10;i++)C[i+26][E] = 1;
        make_edge(str,str2);
        while(getline(cin,in) && in != ""){
            istringstream iss2(in);
            iss2 >> str >> str2;
            make_edge(str,str2);
        }
        //cout << "over\n";
        int sum = 0;
        flag = 0;
        while(1){
            flag = 0;
            int f;
            f = make_flow(S,kInf);
            if(flag == 1){
                sum += f;
                //cout  << "f " << f << " sum "<< sum << "\n";
            }
            if(flag == 0)break;
        }
        if(sum == total){
            for(int i=0;i<10;i++){
                flag = 0;
                for(int j=0;j<26;j++){
                    if(C[i+26][j] > 0){
                        flag = 1;
                        cout << (char) (j + 'A');
                    }
                }
                if(flag == 0)cout << "_";
            }
            //cout << "end\n";
        }else cout << "!";
        cout << "\n";

    }
    return 0;
}
