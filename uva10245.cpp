#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<iostream>
#include<algorithm>
using namespace std;
struct Point{
    int x;
    int y;
}p[10005], t[10005];
int n;
bool cmp(Point a,Point b){
    if(a.x == b.x)return a.y < b.y;
    return a.x < b.x;
}
bool cmp2(Point a,Point b){
    if(a.y == b.y)return a.x < b.x;
    return a.y < b.y;
}
double MIN(double a,double b){
    if(a < b)return a;
    return b;
}
double distance2(Point a,Point b){
    return sqrt((a.x-b.x)*(a.x-b.x) + (a.y -b.y)*(a.y - b.y) );
}
double DnC(int L, int R)
 {
     if (L >= R) return 1e9; // 沒有點、只有一個點。
  
     /* Divide：把所有點分成左右兩側，點數盡量一樣多。 */
  
     int M = (L + R) / 2;
  
     /* Conquer：左側、右側分別遞迴求解。 */
  
     double d = MIN(DnC(L,M), DnC(M+1,R));
 //  if (d == 0.0) return d; // 提早結束
  
     /* Merge：尋找靠近中線的點，並依Y座標排序。O(NlogN)。 */
  
     int N = 0;  // 靠近中線的點數目
     for (int i=M;   i>=L && p[M].x - p[i].x < d; --i) t[N++] = p[i];
     for (int i=M+1; i<=R && p[i].x - p[M].x < d; ++i) t[N++] = p[i];
     sort(t, t+N, cmp2); // Quicksort O(NlogN)
  
     /* Merge：尋找橫跨兩側的最近點對。O(N)。 */
  
     for (int i=0; i<N-1; ++i)
         for (int j=1; j<=2 && i+j<N; ++j)
             d = MIN(d,distance2(t[i],t[i+j]));
  
     return d;
 }
int main (){
    int i;
    double ans;
    while(1){
        scanf("%d",&n);
        if(n == 0)break;
        for(i=0;i<n;i++)
            scanf("%d%d",&p[i].x,&p[i].y);
        sort(p,p+n,cmp);
        ans = DnC(0,n-1);
        if(ans >= 10000)printf("INFINITY\n");
        else printf("%.4lf\n",ans);
    }
    return 0;
}
