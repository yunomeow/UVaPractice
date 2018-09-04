#include <iostream>
#include <algorithm>
#include <vector>
#include <limits>
#include <cstdlib>
#include <cstdio>
using namespace std;

typedef long long ll;
const ll kInf = ll(numeric_limits< int >::max());

int N, C1, C2;
ll f[10010][3];
vector< int > graph[10010], order, chl[10010];
int visit[10010], vst_cnt;
bool is_leaf[10010];

void read();
void build();
void solve();
void dfs(int);

int main() {
    ios::sync_with_stdio(false);
    //freopen("in.txt","r",stdin);
    while (cin >> N >> C1 >> C2, N + C1 + C2) {
        read();
        solve();
    }

    return 0;
}

void read() {
    int u, v;

    for (int i = 1; i <= N; ++i)
        graph[i].clear(), chl[i].clear();

    for (int i = 0; i < N - 1; ++i) {
        cin >> u >> v;
        graph[u].push_back(v), graph[v].push_back(u);
    }
}

void build() {
    order.clear();
    fill(&is_leaf[0], &is_leaf[10010], true);
    visit[1] = ++vst_cnt, dfs(1);
}

void dfs(int u) {
    int v;

    for (int i = 0; i < int(graph[u].size()); ++i)
        if (visit[v = graph[u][i]] != vst_cnt)
            visit[v] = vst_cnt, is_leaf[u] = false, chl[u].push_back(v), dfs(v);
    order.push_back(u);
}

void solve() {
    build();

//    cout << "order.size() = " << int(order.size()) << "\n";
//    for (int i = 0; i < int(order.size()); ++i)
//        cout << " " << order[i];
//    cout << "\n";

    fill(&f[0][0], &f[10010][0], kInf);
    for (int i = 0; i < int(order.size()); ++i) {
        int u = order[i], v, w;
        ll sum, sum2, diff, tmp;
        bool slct_flg;

//        cout << "u = " << u << ", is_leaf[u] = " << is_leaf[u] << "\n";

        if (is_leaf[u]) {
            f[u][0] = 0, f[u][1] = C1, f[u][2] = C2;
//            cout << "  f[u][0] = " << f[u][0] << ", f[u][1] = " << f[u][1] << ", f[u][2] = " << f[u][2] << "\n";
            continue;
        }

        // Case 1
        // f(u, 0)
        sum = ll(0);
        for (int j = 0; j < int(chl[u].size()); ++j)
            v = chl[u][j], sum += min(f[v][1],f[v][2]);

        f[u][0] = min(f[u][0], sum);

        sum = ll(0);
        for (int j = 0; j < int(chl[u].size()); ++j) {
            v = chl[u][j];
            if(chl[v].size() > 0){
                sum2 = ll(0), diff = kInf, slct_flg = false;
                for (int k = 0; k < int(chl[v].size()); ++k) {
                    w = chl[v][k];
                    tmp = min(f[w][0], min(f[w][1], f[w][2]));
                    if (tmp == f[w][2])
                        slct_flg = true;
                    else
                        diff = min(diff, f[w][2] - tmp);
                    sum2 += tmp;
                }
                if (slct_flg)
                    sum += min(sum2,min(f[v][1],f[v][2]));
                else
                    sum += min(sum2 + diff,min(f[v][1],f[v][2]));
            }else{
                sum += min(f[v][1],f[v][2]);
            }
        }

        f[u][0] = min(f[u][0], sum);

        sum = ll(0), diff = kInf, slct_flg = false;
        for (int j = 0; j < int(chl[u].size()); ++j) {
            v = chl[u][j];
            tmp = min(f[v][0], min(f[v][1], f[v][2]));
            if (tmp == f[v][2])
                slct_flg = true;
            else
                diff = min(diff, f[v][2] - tmp);
            sum += tmp;
        }
        if (slct_flg)
            f[u][0] = min(f[u][0], sum);
        else
            f[u][0] = min(f[u][0], sum + diff);

        // Case 2
        // f(u, 1)
        sum = ll(0);

        for (int j = 0; j < int(chl[u].size()); ++j) {
            v = chl[u][j], tmp = min(f[v][0], min(f[v][1], f[v][2]));
            if(chl[v].size() > 0){
                ll ss=0;
                for (int k = 0; k < int(chl[v].size()); ++k){
                    w = chl[v][k], ss += min(f[w][1], f[w][2]);
                }
                tmp = min(ss,tmp);
            }
            if(chl[v].size() > 0){
                ll tmp2;
                tmp2 = ll(0);
                sum2 = ll(0), diff = kInf, slct_flg = false;
                for (int k = 0; k < int(chl[v].size()); ++k) {
                    w = chl[v][k];
                    tmp2 = min(f[w][0], min(f[w][1], f[w][2]));
                    if (tmp2 == f[w][2])
                        slct_flg = true;
                    else
                        diff = min(diff, f[w][2] - tmp2);
                    sum2 += tmp2;
                }
                if (slct_flg)
                    tmp = min(tmp, sum2);
                else
                    tmp = min(tmp, sum2+diff);
            }
            sum += tmp;
        }
        f[u][1] = min(f[u][1], sum + ll(C1));

        // Case 3
        //   f(u, 2)
        sum = ll(0);
        for (int j = 0; j < int(chl[u].size()); ++j) {
            v = chl[u][j], tmp = min(f[v][0], min(f[v][1], f[v][2]));
            if(chl[v].size() > 0){
                ll ss=0;
                for (int k = 0; k < int(chl[v].size()); ++k){
                    w = chl[v][k], ss += min(f[w][0], min(f[w][1], f[w][2]));
                }
                tmp = min(ss,tmp);
            }
            sum += tmp;
        }
        f[u][2] = min(f[u][2], sum + ll(C2));

//        cout << "  f[u][0] = " << f[u][0] << ", f[u][1] = " << f[u][1] << ", f[u][2] = " << f[u][2] << "\n";
    }

    ll res = min(f[1][0], min(f[1][1], f[1][2]));
    cout << res << "\n";
}
