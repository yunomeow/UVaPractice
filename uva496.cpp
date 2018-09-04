#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <set>
using namespace std;
int main (){
    string str;
    vector<int> A,B;
    int tmp;
    while(getline(cin,str)){
        istringstream iss(str);
        A.clear();
        B.clear();
        while(iss >> tmp){
            A.push_back(tmp);
        }
        getline(cin,str);
        istringstream iss2(str);
        while(iss2 >> tmp){
            B.push_back(tmp);
        }
        sort(A.begin(),A.end());
        sort(B.begin(),B.end());
        int flag;
        //equals
        flag = 1;
        if(A.size() != B.size())flag = 0;
        else{
            for(int i=0;i<A.size();i++){
                if(A[i] != B[i])flag = 0;
            }
        }
        if(flag == 1){cout << "A equals B\n";continue;}

        //B in A
        int now = 0;
        if(A.size() > B.size()){
            for(int i=0;i<A.size();i++){
                if(A[i] == B[now])now++;
            }
            if(now == B.size()){cout << "B is a proper subset of A\n";continue;}
        }
        //A in B
        now = 0;
        if(B.size() > A.size()){
            for(int i=0;i<B.size();i++){
                if(B[i] == A[now])now++;
            }
            if(now == A.size()){cout << "A is a proper subset of B\n";continue;}
        }
        set<int> s;
        for(int i=0;i<B.size();i++){
            s.insert(B[i]);
        }
        for(int i=0;i<A.size();i++){
            s.insert(A[i]);
        }
        if(s.size() == A.size() + B.size()){cout << "A and B are disjoint\n";continue;}

        cout << "I'm confused!\n";
    }
    return 0;
}
