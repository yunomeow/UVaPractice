#include <iostream>
using namespace std;
typedef long long int64;
int64 N,L,U;
int64 solve(int now,int64 l,int64 u){
    int64 tmp = (1ll << now),a1,a2;
    if(l == u)return l;
    if(now < 0)return 0;
    if((tmp & N) != 0){
        if((u & tmp) != 0 && (l & tmp) != 0){
            return (solve(now-1,(l ^ tmp) , (u ^ tmp)) | tmp);
        }else if((u & tmp) != 0 && (l & tmp) == 0){
            return (solve(now-1, l , (tmp-1)));
        }else{
            return solve(now-1, l , u);
        }
    }else{
        if((u & tmp) != 0 && (l & tmp) != 0){
            return (solve(now-1,(l ^ tmp) , (u ^ tmp)) | tmp);
        }else if((u & tmp) != 0 && (l & tmp) == 0){
            return (solve(now-1, 0 , (u ^ tmp)) | tmp);
        }else{
            return solve(now-1, l , u);
        }
    }

    return 0;
}
int main (){
    while(cin >> N >> L >> U){
        cout << solve(32,L,U) << "\n";
    }
    return 0;
}
