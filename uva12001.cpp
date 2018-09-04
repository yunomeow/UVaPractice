#include <iostream>
#include <cstdio>
using namespace std;
int main (){
    int N,M;
    long long ans1,ans2;
    long long num[100],sum[100];
    while(cin >> N >> M , N+M){
        int tmp;
        fill(&num[0],&num[M],0);
        for(int i=0;i<N;i++){
            //cin >> tmp;
            scanf("%d",&tmp);
            tmp--;
            num[tmp]++;
        }
        ans1 = 0;ans2 = 0;
        sum[M] = 0;
        for(int i=M-1;i>=0;i--)sum[i] = sum[i+1] + num[i];
        for(int i=0;i<M;i++){
            if(num[i] >= 3){
                ans1 += num[i] * (num[i]-1) * (num[i]-2) / 6;
                for(int j=0;j<M;j++){
                    if(i == j){
                        if(num[j] >= 4)
                            ans2 += num[i] * (num[i]-1) * (num[i]-2) * (num[i]-3)/ 24;
                    }else{
                        ans2 += num[i] * (num[i]-1) * (num[i]-2) / 6 * num[j];
                    }
                }
            }
        }
        for(int i=0;i<M;i++){
            if(num[i] == 0)continue;
            for(int j=i+1;j<M;j++){
                if(num[j] == 0)continue;
                for(int k=j+1;k<M;k++){
                    if(num[k] == 0)continue;
                    ans1 += num[i] * num[j] * num[k];
                    if(num[i] >= 2)
                        ans2 += num[i] * num[j] * num[k] * (num[i]-1) / 2;
                    if(num[j] >= 2)
                        ans2 += num[i] * num[j] * num[k] * (num[j]-1) / 2;
                    if(num[k] >= 2)
                        ans2 += num[i] * num[j] * num[k] * (num[k]-1) / 2;
                    ans2 += num[i] * num[j] * num[k] * sum[k+1];
                }
            }
        }
        cout << ans1 <<" " << ans2 <<"\n";
    }
    return 0;
}
