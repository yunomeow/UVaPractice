#include <iostream>
#include <sstream>
using namespace std;
int reg[25],Ram[1005];
int main(){
    int Z,now,cnt,d,n,s,a;
    string ins;
    cin >> Z;
    cin.get();
    cin.get();
    while(Z--){
        fill(&Ram[0],&Ram[1002],0);
        fill(&reg[0],&reg[16],0);
        now = 0;
        while(getline(cin,ins) && ins != ""){
            istringstream iss(ins);
            iss >> Ram[now];
            now++;
        }
        now = 0;
        cnt = 0;
        while(1){
            //cout << now << " "  <<  Ram[now]<<"===\n";
            if(Ram[now] == 100){
                break;
            }else if(Ram[now] / 100 == 2){
                d = (Ram[now] % 100) / 10;
                n = Ram[now] % 10;
                reg[d] = n;
            }else if(Ram[now] / 100 == 3){
                d = (Ram[now] % 100) / 10;
                n = Ram[now] % 10;
                reg[d] += n;
                reg[d] %= 1000;
            }else if(Ram[now] / 100 == 4){
                d = (Ram[now] % 100) / 10;
                n = Ram[now] % 10;
                reg[d] *= n;
                reg[d] %= 1000;
            }else if(Ram[now] / 100 == 5){
                d = (Ram[now] % 100) / 10;
                s = Ram[now] % 10;
                reg[d] = reg[s];
            }else if(Ram[now] / 100 == 6){
                d = (Ram[now] % 100) / 10;
                s = Ram[now] % 10;
                reg[d] = reg[d] + reg[s];
                reg[d] %= 1000;
            }else if(Ram[now] / 100 == 7){
                d = (Ram[now] % 100) / 10;
                s = Ram[now] % 10;
                reg[d] = reg[d] * reg[s];
                reg[d] %= 1000;
            }else if(Ram[now] / 100 == 8){
                d = (Ram[now] % 100) / 10;
                a = Ram[now] % 10;
                reg[d] = Ram[reg[a]];
            }else if(Ram[now] / 100 == 9){
                s = (Ram[now] % 100) / 10;
                a = Ram[now] % 10;
                Ram[reg[a]] = reg[s];
            }else if(Ram[now] / 100 == 0){
                d = (Ram[now] % 100) / 10;
                s = Ram[now] % 10;
                if(reg[s] != 0){
                    now = reg[d]-1;
                }
            }
            now++;
            cnt++;
        }
        cout << (cnt+1) << "\n";
        if(Z)cout <<"\n";
    }
    return 0;
}
