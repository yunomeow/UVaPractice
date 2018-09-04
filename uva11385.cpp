#include <iostream>
using namespace std;
typedef long long int64;
int64 f[105],num[105];
int main (){
    char out[105];
    f[0] = f[1] = 1;
    for(int i=2;i<105;i++){
        f[i] = f[i-1] + f[i-2];
        //cout << f[i] << "\n";
    }
    int Z,now;
    string str;
    cin >> Z;
    while(Z--){
        int N;
        fill(&out[0],&out[102],' ');
        cin >> N;
        cin.get();
        for(int i=0;i<N;i++)cin >>num[i];
        cin.get();
        getline(cin,str);
        //cout << str << "\n";
        now = 0;
        for(int i=0;i<str.size();i++){
            if(str[i] >= 'A' && str[i] <= 'Z'){
                for(int j=1;j<50;j++){
                    if(f[j] == num[now] && now < N){
                        out[j-1] = str[i];
                        break;
                    }
                }
                now++;
            }
        }
        int pos = 0;
        for(int i=80;i>=0;i--){
            if(out[i] != ' '){
                pos = i+1;
                break;
            }
        }
        for(int i=0;i<pos;i++)
            cout << out[i];
        cout <<"\n";
    }
    return 0;
}
