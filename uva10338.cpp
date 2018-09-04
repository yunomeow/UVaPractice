#include <iostream>
#define MAX 50
using namespace std;
struct BigInt{
    int len;
    int num[MAX];
    BigInt(){
        len = 1;
        fill(&num[0],&num[MAX],0);
    }
    BigInt(int x){
        if(x == 0){
            fill(&num[0],&num[MAX],0);
            len = 1;
        }else{
            len = 0;
            fill(&num[0],&num[MAX],0);
            while(x > 0){
                num[len] = x % 10;
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
        for(int i=b.len-1;i>=0;i--)
            o << b.num[i];
        return o;
    }
    BigInt operator *(const BigInt &b)const{
        BigInt res;
        for(int i=0;i<len;i++){
            for(int j=0;j<b.len;j++){
                res.num[i+j] += num[i] * b.num[j];
            }
        }
        int carry = 0;
        for(int i=0;i<len+b.len;i++){
            res.num[i] += carry;
            carry = res.num[i] / 10;
            res.num[i] %= 10;
        }
        for(int i=len+b.len;i>=0;i--){
            if(res.num[i] != 0){
                res.len = i+1;
                break;
            }
        }
        res.len = max(res.len,1);
        return res;
    }
    BigInt operator +(const BigInt &b)const{
        BigInt res;
        int mlen = max(len,b.len);
        for(int i=0;i<mlen;i++){
            res.num[i] += num[i] + b.num[i];
        }
        int carry = 0;
        for(int i=0;i<mlen+1;i++){
            res.num[i] += carry;
            carry = res.num[i] / 10;
            res.num[i] %= 10;
        }
        for(int i=mlen+1;i>=0;i--){
            if(res.num[i] != 0){
                res.len = i+1;
                break;
            }
        }
        res.len = max(res.len,1);
        return res;
    }
    bool operator < (const BigInt &b)const{

        if(len != b.len)return len < b.len;

        for(int i=len-1;i>=0;i--){
            if(num[i] != b.num[i])return num[i] < b.num[i];
        }
        return num[0] < b.num[0];
    }
    bool operator > (const BigInt &b)const{

        if(len != b.len)return len > b.len;

        for(int i=len-1;i>=0;i--){
            if(num[i] != b.num[i])return num[i] > b.num[i];
        }

        return num[0] > b.num[0];
    }
    BigInt operator -(const BigInt &b)const{
        BigInt res;
        int mlen = max(len,b.len);
        if(*this < b){
            for(int i=0;i<mlen;i++){
                res.num[i] = b.num[i] - num[i];
            }
        }else{
            for(int i=0;i<mlen;i++){
                res.num[i] = num[i] - b.num[i];
            }
        }
        int carry = 0;
        for(int i=0;i<mlen+1;i++){
            if(res.num[i] < 0){
                res.num[i] += 10;
                res.num[i+1]--;
            }
        }
        for(int i=mlen+1;i>=0;i--){
            if(res.num[i] != 0){
                res.len = i+1;
                break;
            }
        }
        res.len = max(res.len,1);
        return res;
    }
    BigInt operator / (const BigInt &b)const{
        BigInt res,ten(10),tmp,now,c;
        int flag;
        now = *this;
        for(int i=len-1;i>=0;i--){
            tmp = BigInt(1);
            //cout << now << "\n";
            for(int j=0;j<i;j++)tmp = tmp * ten;
            res.num[i] = 0;
            for(int j=1;j<=10;j++){
                c = tmp * BigInt(j) * b;
                //cout << "c: "<< c << "\n";
                if(c > now){

                    c = tmp * b * BigInt(j-1);

                    res.num[i] = j-1;
                    now = now - c;
                    break;
                }
            }
        }
        for(int i=len+1;i>=0;i--){
            if(res.num[i] != 0){
                res.len = i+1;
                break;
            }
        }
        res.len = max(res.len,1);
        return res;
    }
};
BigInt fact[25];
int main(){
    int Z;
    string str;
    int cnt[30];
    //BigInt ss(181440),two(2),a;
    //a =(ss/two);
    //cout << a << "\n";
    fact[1] = BigInt(1);
    for(int i=2;i<=20;i++){
        fact[i] = fact[i-1] * BigInt(i);
    }
    cin >> Z;
    for(int zi=1;zi<=Z;zi++){
        cin >> str;
        BigInt ans = fact[str.size()];
        fill(&cnt[0],&cnt[28],0);
        for(int i=0;i<str.size();i++){
            cnt[str[i] - 'A'] ++;
        }

        for(int i=0;i<26;i++){
            if(cnt[i] >= 2){
                //cout << "cnt: " << cnt[i] << "\n";
                ans = ans / fact[cnt[i]];
            }
            //cout << ans <<"\n";
        }
        cout << "Data set " << zi << ": " << ans << "\n";
    }
    return 0;
}
