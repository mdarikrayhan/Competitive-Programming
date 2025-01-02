// LUOGU_RID: 160472674
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
constexpr int maxn = 300000 + 10;
int dfn[maxn], low[maxn], st[maxn], bel[maxn], top, idx, cnt;
struct edge
{
    int v, w;
    edge(int _v=0, int _w=0) : v(_v), w(_w) {}
};
vector<edge> g[maxn];
map<int, int> h[maxn];
int c[maxn];
void tar(int u, int fa)
{
    dfn[u] = low[u] = ++cnt;
    st[++top] = u;
    for (edge e : g[u])
        if (e.v != fa)
        {
            if (dfn[e.v]) low[u] = min(low[u], dfn[e.v]);
            else
            {
                tar(e.v, u);
                low[u] = min(low[u], low[e.v]);
            }
        }
    if (low[u] == dfn[u])
    {
        int v;
        ++idx;
        do
        {
            v = st[top--];
            bel[v] = idx;
        } while (v != u);
    }
}
int f[maxn];
void dfs(int u, int fa, int x)
{
    x |= c[u];
    f[u] = x;
    for (auto [v, w] : h[u])
        if (v != fa) dfs(v, u, x | w);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i=1;i<=m;++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].emplace_back(edge(v, w));
        g[v].emplace_back(edge(u, w));
    }
    int a, b;
    cin >> a >> b;
    tar(a, 0);
    for (int i=1;i<=n;++i)
        for (auto [v, w] : g[i])
            if (bel[i] == bel[v]) c[bel[i]] |= w;
            else h[bel[i]][bel[v]] |= w, h[bel[v]][bel[i]] |= w;
    dfs(bel[a], 0, 0);
    cout << (f[bel[b]] ? "YES" : "NO") << '\n';
    return 0;
}