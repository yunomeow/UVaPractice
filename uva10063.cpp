#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
using namespace std;
char s[100],tmp[100];
int len;
struct Node{
    char ch;
    Node* next;
}data[100];
Node* head;
void dfs(int pos){
    int i,cnt;
    Node *tmp,*tmp2;
    if(pos == len){
        tmp = head;
        while(tmp != NULL){
            printf("%c",tmp->ch);
            tmp = tmp->next;
        }
        printf("\n");
        return;
    }
   // printf("pos %d\n",pos);
    for(i=0;i<=pos;i++){
        cnt = 1;
        tmp = head;
        while(cnt < i){
            tmp = tmp->next;
            cnt++;
        }
       // printf("tmp %d\n",tmp);
        if(i == 0){
            tmp2 = head;
            head = &data[pos];
            data[pos].next = tmp2;
            dfs(pos+1);
            head = data[pos].next;
        }else{
            //system("pause");
            tmp2 = tmp->next;
            tmp->next = &data[pos];
            data[pos].next = tmp2;
            dfs(pos+1);
            tmp->next = tmp2;            
        }

    }
}
int main (){
    int flag=0,i;
    while(scanf("%s",s) != EOF){
        len = strlen(s);
        if(flag == 1)printf("\n");
        flag = 1;
        for(i=0;i<len;i++){
            data[i].ch = s[i];
        }
        dfs(0);
    }
    return 0;
}
