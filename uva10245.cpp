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
     if (L >= R) return 1e9; // �S���I�B�u���@���I�C
  
     /* Divide�G��Ҧ��I�������k�ⰼ�A�I�ƺɶq�@�˦h�C */
  
     int M = (L + R) / 2;
  
     /* Conquer�G�����B�k�����O���j�D�ѡC */
  
     double d = MIN(DnC(L,M), DnC(M+1,R));
 //  if (d == 0.0) return d; // ��������
  
     /* Merge�G�M��a�񤤽u���I�A�è�Y�y�бƧǡCO(NlogN)�C */
  
     int N = 0;  // �a�񤤽u���I�ƥ�
     for (int i=M;   i>=L && p[M].x - p[i].x < d; --i) t[N++] = p[i];
     for (int i=M+1; i<=R && p[i].x - p[M].x < d; ++i) t[N++] = p[i];
     sort(t, t+N, cmp2); // Quicksort O(NlogN)
  
     /* Merge�G�M����ⰼ���̪��I��CO(N)�C */
  
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
