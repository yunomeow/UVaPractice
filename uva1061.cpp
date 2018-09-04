#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
struct XD{
    char t[4];
    XD(){
    }
    XD(char a,char b,char c,char d){
        t[0] = a;t[1] = b;t[2] = c;t[3] = d;
        sort(t,t+4);
    }
};
map<string,int> m;
string name[16]={
"A+","A-","AB+","AB-","B+","B-","O+","O-"
};
int ok[17];
int check(XD a,XD b,XD c){

    XD n[16];
    n[0] = XD(a.t[0],b.t[0],a.t[2],b.t[2]);
    n[1] = XD(a.t[0],b.t[1],a.t[2],b.t[2]);
    n[2] = XD(a.t[1],b.t[0],a.t[2],b.t[2]);
    n[3] = XD(a.t[1],b.t[1],a.t[2],b.t[2]);

    n[4] = XD(a.t[0],b.t[0],a.t[2],b.t[3]);
    n[5] = XD(a.t[0],b.t[1],a.t[2],b.t[3]);
    n[6] = XD(a.t[1],b.t[0],a.t[2],b.t[3]);
    n[7] = XD(a.t[1],b.t[1],a.t[2],b.t[3]);

    n[8] = XD(a.t[0],b.t[0],a.t[3],b.t[2]);
    n[9] = XD(a.t[0],b.t[1],a.t[3],b.t[2]);
    n[10] = XD(a.t[1],b.t[0],a.t[3],b.t[2]);
    n[11] = XD(a.t[1],b.t[1],a.t[3],b.t[2]);

    n[12] = XD(a.t[0],b.t[0],a.t[3],b.t[3]);
    n[13] = XD(a.t[0],b.t[1],a.t[3],b.t[3]);
    n[14] = XD(a.t[1],b.t[0],a.t[3],b.t[3]);
    n[15] = XD(a.t[1],b.t[1],a.t[3],b.t[3]);

    for(int i=0;i<16;i++){
        int flag = 1;
        for(int j=0;j<4;j++){
            if(j < 3){
                if(n[i].t[j] != c.t[j] ){
                    flag = 0;
                }
            }else{
                if(n[i].t[j] != c.t[j]){
                    if(!(c.t[j] == 'i' && (n[i].t[j] == 'A' || n[i].t[j] == 'B')))flag = 0;
                   //if(c.t[j] == 'B' && n[i].t[j] == 'A')flag = 0;
                   // if(c.t[j] == 'A' && n[i].t[j] == 'B')flag = 0;
                }
            }
        }
        if(flag == 1)return 1;
    }
    return 0;
}
int main (){
    XD blood[15];
    blood[0] = XD('A','i','+','-');
    blood[1] = XD('A','i','-','-');
    blood[4] = XD('B','i','+','-');
    blood[5] = XD('B','i','-','-');
    blood[6] = XD('i','i','+','-');
    blood[7] = XD('i','i','-','-');
    blood[2] = XD('A','B','+','-');
    blood[3] = XD('A','B','-','-');
    m["A+"] = 0;
    m["A-"] = 1;
    m["B+"] = 4;
    m["B-"] = 5;
    m["O+"] = 6;
    m["O-"] = 7;
    m["AB+"] = 2;
    m["AB-"] = 3;
    string s1,s2,s3;
    int zi = 1;
    XD b1,b2;
    while(cin >> s1 >> s2 >> s3){
        fill(&ok[0],&ok[13],0);
        if(s1 == "E" && s2 == "N" && s3 == "D") break;
        cout << "Case "<< zi++ << ": ";
        if(s1 == "?"){
            b1 = blood[m[s2]];
            b2 = blood[m[s3]];
            int sum = 0;
            for(int i=0;i<8;i++){
                ok[i] = check(blood[i],b1,b2);
                sum += ok[i];
            }
            if(sum == 0)cout << "IMPOSSIBLE";
            else if(sum == 1){
                for(int i=0;i<8;i++){
                    if(ok[i])
                    cout << name[i] << "\n";
                }
            }else{
                cout << "{";
                int isF=1;
                for(int i=0;i<8;i++){
                    if(ok[i]){
                        if(!isF)cout << ", ";
                        isF = 0;
                        cout << name[i] ;
                    }
                }
                cout << "}";
            }
            cout << " " << s2 << " " << s3 << "\n";
        }else if(s2 == "?"){
            cout << s1 << " ";
            b1 = blood[m[s1]];
            b2 = blood[m[s3]];
            int sum = 0;
            for(int i=0;i<8;i++){
                ok[i] = check(blood[i],b1,b2);
                sum += ok[i];
            }
            if(sum == 0)cout << "IMPOSSIBLE";
            else if(sum == 1){
                for(int i=0;i<8;i++){
                    if(ok[i])
                    cout << name[i] << "\n";
                }
            }else{
                cout << "{";
                int isF=1;
                for(int i=0;i<8;i++){
                    if(ok[i]){
                        if(!isF)cout << ", ";
                        isF = 0;
                        cout << name[i] ;
                    }
                }
                cout << "}";
            }
            cout << " " << s3 << "\n";
        }else{

            cout << s1 << " " << s2 <<" ";
            b1 = blood[m[s1]];
            b2 = blood[m[s2]];
            int sum = 0;
            for(int i=0;i<8;i++){
                ok[i] = check(b1,b2,blood[i]);
                sum += ok[i];
            }
            if(sum == 0)cout << "IMPOSSIBLE";
            else if(sum == 1){
                for(int i=0;i<8;i++){
                    if(ok[i])
                    cout << name[i] << "\n";
                }
            }else{
                cout << "{";
                int isF=1;
                for(int i=0;i<8;i++){

                    if(ok[i]){
                        if(!isF)cout << ", ";
                        isF = 0;
                        cout << name[i];
                    }
                }
                cout << "}\n";
            }
        }

    }
    return 0;
}

