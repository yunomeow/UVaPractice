#include <iostream>
using namespace std;
int num[105];
struct BigInt{
    int len;
    int num[505];
    int msign;
    BigInt(){
        msign = 0;
        len = 1;
        fill(&num[0],&num[505],0);
    }
    BigInt(int x){
        if(x < 0){
            msign = 1;
            x = -x;
        }else msign = 0;
        if(x == 0){
            msign = 0;
            len = 1;
            fill(&num[0],&num[505],0);
        }else{
            len = 1;
            fill(&num[0],&num[505],0);
            while(x > 0){
                num[len-1] = x % 10;
                len++;
                x /= 10;
            }
        }
    }
    friend istream & operator >>(istream& is, BigInt &b){
        string s;
        is >> s;
        for(int i=s.length()-1,j=0;i >= 0;i--,j++){
            b.num[j] = s[i] - '0';
        }
        b.len = s.length();
        return is;
    }
    friend ostream & operator <<(ostream& o, BigInt &b){
        if(b.msign == 1)o << "-";
        for(int i=b.len-1;i>=0;i--)
            o << b.num[i];
        return o;
    }
    bool operator < (const BigInt &b)const{
        if(b.msign != msign)return msign > b.msign;
        if(msign == 0){
            if(len != b.len)return len < b.len;
            for(int i=len-1;i>=0;i--){
                if(num[i] != b.num[i])return num[i] < b.num[i];
            }
            return num[0] < b.num[0];
        }else{
            if(len != b.len)return len > b.len;
            for(int i=len-1;i>=0;i--){
                if(num[i] != b.num[i])return num[i] > b.num[i];
            }
            return num[0] > b.num[0];
        }
    }
};
void mul(BigInt &b,int k){
    if(k < 0){
        b.msign = (b.msign ^ 1);
        k = -k;
    }
    for(int i=0;i<b.len;i++){
        b.num[i] = b.num[i] * k;
    }
    int carry = 0;
    for(int i=0;i<b.len+10;i++){
        b.num[i] += carry;
        carry = b.num[i] / 10;
        b.num[i] %= 10;
    }
    int flag=0;
    for(int i=b.len+10;i>=0;i--){
        if(b.num[i] != 0){
            b.len = i+1;
            flag = 1;
            break;
        }
    }
    if(flag == 0)b.len = 1;
    else b.len = max(b.len,1);
}
int main (){
    int N=0;
    while(cin >> num[0]){
        N = 1;
        while(cin >> num[N++], num[N-1] != -999999);
        N--;
        BigInt ans(-100000);
        for(int i=0;i<N;i++){
            BigInt tmp(1);
            for(int j=i;j<N;j++){
                mul(tmp,num[j]);
                if(ans < tmp)ans = tmp;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
