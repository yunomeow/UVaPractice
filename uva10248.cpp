#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<string.h>
#include<iostream>
using namespace std;
vector<int> v[10];
int indegree[20],stack[100],top,use[20];
void find_circuit(int pos){
    int i,tmp,flag=0;
    printf("%d",pos);
    use[pos] = 1;
    for(i=0;i<v[pos].size();i++){
        
        tmp = v[pos][i];
        if(tmp != pos)continue;
        use[tmp] = 1;
        //printf("from %d to %d\n",pos,tmp);
        v[pos].erase(v[pos].begin()+i);
        indegree[tmp]--;
        find_circuit(tmp);
        //stack[top] = tmp;
        flag = 1;
        //top++;
    }
    for(i=0;i<v[pos].size();i++){
        tmp = v[pos][i];
        use[tmp] = 1;
        v[pos].erase(v[pos].begin()+i);
        //printf("from %d to %d\n",pos,tmp);
        indegree[tmp]--;
        find_circuit(tmp);
        //stack[top] = tmp;
        flag = 1;
        //top++;
    }
    if(flag == 0){
        for(i=0;i<10;i++){
            if(v[i].size() > 0 && v[i].size() > indegree[i]){
                find_circuit(i);
                return;
            }
        }
        for(i=0;i<10;i++){
            if(v[i].size() > 0 && v[i].size() == indegree[i]){
                find_circuit(i);
                return;
            }
        }        
    }
}
int main (){
    int n,m,i,j,a,b,flag,f2;
    while(scanf("%d%d",&n,&m)!=EOF){
        for(i=0;i<10;i++)v[i].clear();
        for(i=m;i>=n;i--){
            if(i < 10)continue;
            v[i/10].push_back(i%10);
        }
        memset(indegree,0,sizeof(indegree));
        memset(use,0,sizeof(use));
        for(i=0;i<10;i++){
            for(j=0;j<v[i].size();j++){
                indegree[v[i][j]]++;
            }  
        }
        while(1){
            flag = 0;
            for(i=0;i<10;i++){
                if(v[i].size() > 0)flag = 1;
            }
            f2 = 1;
            for(i=0;i<10;i++){
                if(v[i].size() > 0 && v[i].size() > indegree[i]){
                    //printf("%d",i);
                    find_circuit(i);
                  //  for(j=top-1;j>=0;j--){
                  //      printf("%d",stack[j]);
                  //  }
                    f2 = 0;
                    break;
                }
            }
            if(f2 == 1){
                for(i=0;i<10;i++){
                    if(v[i].size() > 0 && v[i].size() == indegree[i]){
                       find_circuit(i);
                        f2 = 0;
                        break;
                    }
                }                
            }
           // printf("\n");
            if(flag == 0)break;
        }
      //  for(i=0;i<10;i++)
      //      printf("%d ",v[i].size());
      //  printf("\n");
        for(i=n;i<10 && n < 10 && i <= m;i++){
            if(use[i] == 0)printf("%d",i);
        }
        printf("\n");
    }
    return 0;
}
