#include <iostream>
#include <vector>
using namespace std;
vector<int> v[30];
int wake[2][30];
int main (){
    int N,M,now,a,b;
    string str;
    while(cin >> N >> M){
        cin >> str;
        fill(&wake[0][0],&wake[3][0],0);
        for(int i=0;i<str.size();i++){
            wake[0][str[i]-'A'] = 1;
        }
        for(int i=0;i<27;i++)v[i].clear();
        for(int i=0;i<M;i++){
            cin >> str;
            a = str[0]-'A';
            b = str[1]-'A';
            v[a].push_back(b);
            v[b].push_back(a);
        }
        now = 0;
        int flag = 1,ans = -1,cnt;
        while(flag == 1){
            flag = 0;
            for(int i=0;i<26;i++){
                cnt = 0;
                wake[1 - now][i] = wake[now][i];
                for(int j=0;j<v[i].size();j++){
                    if(wake[now][v[i][j]] == 1)cnt++;
                }
                if(cnt >= 3){

                    if(wake[1 - now][i] == 0){
                   // cout << (char)(i+'A')<< " wake\n";
                        wake[1 - now][i] = 1;
                        flag = 1;
                    }
                }
            }
            ans++;
            now = 1- now;
        }
        cnt = 0;
        for(int i=0;i<26;i++){
            cnt += wake[now][i];
        }
        if(cnt != N)cout << "THIS BRAIN NEVER WAKES UP\n";
        else cout << "WAKE UP IN, " << ans << ", YEARS\n";
    }
    return 0;
}
