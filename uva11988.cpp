#include <iostream>
using namespace std;
struct Node{
    char ch;
    Node *nxt;
    Node(char _c,Node* _n){
        nxt = _n;
        ch = _c;
    }
};
int main (){
    string str;
    while(cin >> str){
        Node *first = new Node(NULL,NULL),*now = first,*last = first;
        for(int i=0;i<str.length();i++){
            if(str[i] == '['){
                now = first;
            }else if(str[i] == ']'){
                now = last;
            }else if(now->ch == NULL){
                first->nxt = new Node(str[i],first->nxt);
                now = first->nxt;
            }else{
                now->nxt = new Node(str[i],now->nxt);
                now = now -> nxt;
            }
            if(now->nxt == NULL)last = now;
        }
        now = first->nxt;
        while(now != NULL){
            cout << now->ch ;
            now = now -> nxt;
        }
        cout << "\n";
    }
    return 0;
}
