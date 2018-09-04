#include <iostream>
using namespace std;
struct Matrix{
    int n,m;
}mat[30];
struct Result{
    int val;
    int n,m;
};
int pos;
string str;
Result getMatrix(){
    Result res;
    if(str[pos] >= 'A' && str[pos] <= 'Z'){
        res.n = mat[str[pos]-'A'].n;
        res.m = mat[str[pos]-'A'].m;
        res.val = 0;
        pos++;
        return res;
    }
    res.val = -1;
    return res;
}
Result getExpr(){
    Result lhs = getMatrix(),rhs,res;
    if(lhs.val != -1)return lhs;
    if(str[pos] == '(')pos++;
    lhs = getExpr();
    rhs = getExpr();
    if(str[pos] == ')')pos++;
    if(lhs.m != rhs.n){
        res.val = -1;
        res.n = 0;
        res.m = 0;
    }else{
        res.val = lhs.m * lhs.n * rhs.m + lhs.val + rhs.val;
        res.n = lhs.n;
        res.m = rhs.m;
    }
    return res;
}
int main (){
    int N,n,m;
    string s;
    while(cin >> N){
        for(int i=0;i<N;i++){
            cin >> s >> n >> m;
            mat[s[0]-'A'].n = n;
            mat[s[0]-'A'].m = m;

        }
        Result res;
        while(cin >> str){
            pos = 0;
            res = getExpr();
            if(res.val == -1)cout << "error\n";
            else cout << res.val << "\n";
        }
    }
    return 0;
}
/*
9
A 50 10
B 10 20
C 20 5
D 30 35
E 35 15
F 15 5
G 5 10
H 10 20
I 20 25
A
B
C
(AA)
(AB)
(AC)
(A(BC))
((AB)C)
(((((DE)F)G)H)I)
(D(E(F(G(HI)))))
((D(EF))((GH)I))
*/
