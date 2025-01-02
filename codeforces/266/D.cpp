#include <bits/stdc++.h>
using namespace std;
using LL = long long;

const int N = 205;
const LL INF = 1e18;
int n, m, val[N], rk[N][N];
LL d[N][N];
struct Edge {
    int u, v, w;
} a[N * N];


bool cmp(int a, int b) { return val[a] < val[b]; }

void Floyd() {
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
}

void solve() {
    Floyd();
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            rk[i][j] = j;
            val[j] = d[i][j];
        }
        sort(rk[i] + 1, rk[i] + 1 + n, cmp);
    }
    LL ans = INF;
    // 图的绝对中心可能在结点上
    for (int i = 1; i <= n; i++)
        ans = min(ans, d[i][rk[i][n]] * 2);
    // 图的绝对中心可能在边上
    for (int i = 1; i <= m; i++) {
        int u = a[i].u, v = a[i].v, w = a[i].w;
        for (int p = n, i = n - 1; i >= 1; i--) {
            if (d[v][rk[u][i]] > d[v][rk[u][p]]) {
                ans = min(ans, d[u][rk[u][i]] + d[v][rk[u][p]] + w);
                p = i;
            }
        }
    }
    cout << 1.L * ans / 2 << '\n';
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cout << fixed << setprecision(8);    

    cin >> n >> m;
    memset(d, 0x3f, sizeof(d));
    for (int i = 1; i <= n; ++i) {
        d[i][i] = 0;
    }
    for (int i = 1; i <= m; ++i) {
        int u, v; LL w;
        cin >> u >> v >> w;
        a[i] = {u, v, w};
        d[u][v] = d[v][u] = min(d[u][v], w);
    }
    solve();
    return 0;
}