#include<bits/stdc++.h>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
#define lowbit(x) x & -x
#define int long long
typedef long long ll;
typedef unsigned long long ULL;
#define PII pair<int,int>
#define PIII pair<int,PII>
#define PDD PII
#define endl '\n'
#define x first
#define y second
#define rep(i,a,b) for(int i = a;i <= b;i++)
#define per(i,a,b) for(int i = a;i >= b;i--)
#define debug(a) for(int i:(a)) cout<<i<<'|';cout<<endl
#define all(n) (n).begin() + 1,(n).end()
#define double long double
const int mod = 998244353;
const int N = 1e5 + 5;
int n;
int stk[N], top, used[N];
int fa[N][21], depth[N];
vector<PDD> a;
vector<vector<int>> g;
double cross(PDD a, PDD b) {
    return a.x * b.y - a.y * b.x;
}
PDD operator-(PDD a, PDD b) {
    return { a.x - b.x,a.y - b.y };
}
double area(PDD a, PDD b, PDD c) {
    return cross(b - a, c - a);
}
void andrew() {
    sort(all(a));
    stk[++top] = n;
    per(i, n - 1, 1) {
        while (top >= 2 && area(a[stk[top - 1]], a[stk[top]], a[i]) < 0) top--;
        stk[++top] = i;
        g[stk[top - 1]].push_back(stk[top]);
    }
}
void dfs(int u, int f) {
    fa[u][0] = f;
    depth[u] = depth[f] + 1;
    for (int i = 1; i <= 20; i++) {
        if (fa[u][i - 1] != -1) fa[u][i] = fa[fa[u][i - 1]][i - 1];
        else fa[u][i] = -1;
    }
    for (int son : g[u]) {
        if (son == f) continue;
        dfs(son, u);
    }
}
int lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    int gap = depth[u] - depth[v];
    for (int i = 0; i <= 20; i++) {
        if (gap >> i & 1) u = fa[u][i];
    }
    if (u == v) return v;
    for (int i = 20; i >= 0; i--) {
        if (fa[u][i] != fa[v][i]) {
            u = fa[u][i];
            v = fa[v][i];
        }
    }
    return fa[u][0];
}
void solve()
{
    cin >> n;
    g.assign(n + 1, vector<int>());
    a.assign(n + 1, { 0,0 });
    int root = 0, h = 0;
    rep(i, 1, n) cin >> a[i].x >> a[i].y;
    andrew();
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= 20; j++)
        {
            fa[i][j] = -1;
        }
    }
    dfs(n, 0);
    int m; cin >> m;
    while (m--) {
        int x, y; cin >> x >> y;
        cout << lca(x, y) << endl;
    }
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int _ = 1; //cin >> _;
    while (_--) solve();
}