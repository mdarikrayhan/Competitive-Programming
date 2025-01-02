// LUOGU_RID: 159125867
#include <bits/stdc++.h>
#define int long long

#define F(i, a, b) for (int i = (a); i <= (b); i++)
#define dF(i, a, b) for (int i = (a); i >= (b); i--)
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int N = 500005, M = (N << 1), inf = 1e16, mod = 1e9 + 7;
int n, m, k, ga[N], gb[N], f[N], a[N], ans;
struct edge {
    int u, v, w, vis;
} e[N];
int find(int x) {return f[x] == x ? x : f[x] = find(f[x]);}
void merge(int x, int y) { f[find(x)] = find(y); }
vector<pii> G[N];
int dep[N], sz[N], h[N], dfn[N], rdfn[N], top[N], anc[N], cnt;
void dfs(int u, int fa) {
    anc[u] = fa;
    dep[u] = dep[fa] + 1;
    sz[u] = 1;
    for (auto [v, w] : G[u]) {
        if (v == fa) continue ;
        dfs(v, u);
        sz[u] += sz[v];
        if (sz[v] > sz[h[u]])
            h[u] = v;
    }
}
void dfs2(int u, int t) {
    top[u] = t;
    dfn[u] = ++cnt;
    rdfn[cnt] = u;
    for (auto [v, w] : G[u])
        if (v == h[u])
            a[v] = w, dfs2(v, t);
    for (auto [v, w] : G[u])
        if (v != anc[u] && v != h[u])
            a[v] = w, dfs2(v, v);
}
struct SGT {
    int t[N << 2], tg[N << 2];
    void build(int p, int l, int r) {
        t[p] = inf;
        if (l == r) {
            t[p] = a[rdfn[l]];
            return ;
        }
        int mid = l + r >> 1;
        build(p * 2, l, mid);
        build(p * 2 + 1, mid + 1, r);
    }
    void change(int p, int x, int y, int v, int l, int r) {
        if (x <= l && r <= y) {
            t[p] = min(t[p], v);
            return ;
        }
        int mid = l + r >> 1;
        if (x <= mid) change(p * 2, x, y, v, l, mid);
        if (y > mid) change(p * 2 + 1, x, y, v, mid + 1, r);
    }
    void getan(int p, int l, int r, int now) {
        now = min(now, t[p]);
        if (l == r) {
            if (now == inf)
                cout << "-1", exit(0);
            ans += now;
            return;
        }
        int mid = l + r >> 1;
        getan(p * 2, l, mid, now);
        getan(p * 2 + 1, mid + 1, r, now);
    }
} tr;
void update(int u, int v, int w) {
    while (top[u] != top[v]) {
        if (dep[top[u]] < dep[top[v]])
            swap(u, v);
        tr.change(1, dfn[top[u]], dfn[u], w, 1, n);
        u = anc[top[u]];
    }
    if (dep[u] < dep[v]) swap(u, v);
    if (dfn[v] < dfn[u])
        tr.change(1, dfn[v] + 1, dfn[u], w, 1, n);
}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> k >> m;
    F(i, 1, n) f[i] = i;
    F(i, 1, k) {
        cin >> ga[i] >> gb[i];
        merge(ga[i], gb[i]);
        G[ga[i]].emplace_back(gb[i], inf);
        G[gb[i]].emplace_back(ga[i], inf);
    }
    F(i, 1, m) {
        int u, v, w;
        cin >> u >> v >> w;
        e[i] = {u, v, w, 0};
    }
    sort(e + 1, e + m + 1, [](edge a, edge b) {
        return a.w < b.w;
    });
    F(i, 1, m) {
        if (find(e[i].u) == find(e[i].v)) continue;
        merge(e[i].u, e[i].v);
        G[e[i].u].emplace_back(e[i].v, 0);
        G[e[i].v].emplace_back(e[i].u, 0);
        e[i].vis = 1;
    }
    dfs(1, 0);
    dfs2(1, 1);
    tr.build(1, 1, n);
    F(i, 1, m) {
        if (e[i].vis) continue ;
        update(e[i].u, e[i].v, e[i].w);
    }
    tr.getan(1, 1, n, inf);
    cout << ans << '\n';
    return 0;
}