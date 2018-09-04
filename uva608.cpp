#include <iostream>
using namespace std;
int isTrue[13];
string a[3],b[3],c[3];
int check(int flag,char ch){
    for(int i=0;i<3;i++){
        if(c[i] == "even"){
            for(int j=0;j<a[i].size();j++){
                if(a[i][j] == ch)return 0;
            }
            for(int j=0;j<b[i].size();j++){
                if(b[i][j] == ch)return 0;
            }
        }else if(c[i] == "up"){
            if(flag == 1){
                for(int j=0;j<a[i].size();j++){
                    if(a[i][j] == ch)return 0;
                }
                int appear = 0;
                for(int j=0;j<b[i].size();j++){
                    if(b[i][j] == ch)appear = 1;
                }
                if(appear == 0)return 0;
            }else{
                int appear = 0;
                for(int j=0;j<a[i].size();j++){
                    if(a[i][j] == ch)appear = 1;
                }
                if(appear == 0)return 0;

                for(int j=0;j<b[i].size();j++){
                    if(b[i][j] == ch)return 0;
                }
            }
        }else{
            if(flag == 1){
                int appear = 0;
                for(int j=0;j<a[i].size();j++){
                    if(a[i][j] == ch)appear = 1;
                }
                if(appear == 0)return 0;

                for(int j=0;j<b[i].size();j++){
                    if(b[i][j] == ch)return 0;
                }
            }else{
                for(int j=0;j<a[i].size();j++){
                    if(a[i][j] == ch)return 0;
                }
                int appear = 0;
                for(int j=0;j<b[i].size();j++){
                    if(b[i][j] == ch)appear = 1;
                }
                if(appear == 0)return 0;
            }
        }
    }
    return 1;
}
void solve(){
    for(char i='A';i<='L';i++){
        for(int j=1;j<=2;j++){
            if(check(j,i)){
                cout << i << " is the counterfeit coin and it is ";
                if(j == 1)cout <<"light.\n";
                else cout << "heavy.\n";
                return ;
            }
        }
    }
}
int main (){
    int Z;
    cin >> Z;
    while(Z--){
        int even_num = 0;
        fill(&isTrue[0],&isTrue[13],0);
        for(int i=0;i<3;i++){
            cin >> a[i] >> b[i] >> c[i];
        }
        solve();
    }
    return 0;
}
