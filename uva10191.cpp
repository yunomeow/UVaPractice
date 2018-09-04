#include <iostream>
#include <iomanip>
using namespace std;
int use[1440];
int main (){
    int N,st,ed,ans,len,pos,nlen,zi=1;
    string s1,s2,s3;
    while(cin >> N){
        fill(&use[0],&use[1440],0);
        //cout << "N = " << N <<"\n";
        while(N--){
            cin >> s1 >> s2 ;
            getline(cin,s3);
            //cout << s1 << " " << s2 << " " << s3 <<"\n";
            st = (s1[0]-'0')*600 + (s1[1]-'0')*60 + (s1[3]-'0')*10 + (s1[4]-'0');
            ed = (s2[0]-'0')*600 + (s2[1]-'0')*60 + (s2[3]-'0')*10 + (s2[4]-'0');
            for(int i=st;i<ed;i++){
                use[i] = 1;
            }
        }
        len = 0;ans = 600;nlen = 0;pos = 600;
        for(int i=600;i<18*60;i++){
            if(use[i] == 1){
                nlen = 0;
                pos = -1;
            }else{
                if(pos == -1)pos = i;
                nlen++;
                if(nlen > len){
                    len = nlen;
                    ans = pos;
                }
            }
        }
        cout << "Day #" << zi++ <<": the longest nap starts at ";
        cout << setfill('0') << setw(2) << (ans / 60) << ":";
        cout << setfill('0') << setw(2) << (ans % 60) ;
        if(len < 60){
            cout << " and will last for " << len << " minutes.\n";
        }else{
            cout << " and will last for " << (len/60) << " hours and "<< (len%60) << " minutes.\n";
        }
    }

    return 0;
}
