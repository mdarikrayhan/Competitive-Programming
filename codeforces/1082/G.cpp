// LUOGU_RID: 160472101
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
constexpr i64 inf = 0x3f3f3f3f3f3f3f3f;
constexpr int maxn = 1000 + 10;
constexpr int maxm = 1100000;
struct edge
{
    int v; i64 f;
    edge(int _v=0, i64 _f=0) : v(_v), f(_f) {}
} e[maxm << 1];
int cnt = 1;
vector<int> G[maxn];
void addedge(int u, int v, i64 f)
{
    e[++cnt] = edge(v, f); G[u].emplace_back(cnt);
    e[++cnt] = edge(u, 0); G[v].emplace_back(cnt);
}
int dep[maxn], cur[maxn];
int s, t;
i64 dfs(int u, i64 flow)
{
    if (u == t || !flow) return flow;
    i64 ans = 0, f;
    for (int& i=cur[u];i<G[u].size();++i)
    {
        auto& ed = e[G[u][i]];
        if (dep[ed.v] == dep[u] + 1 && (f = dfs(ed.v, min(flow, ed.f))))
        {
            ed.f -= f;
            e[G[u][i] ^ 1].f += f;
            ans += f;
            flow -= f;
            if (!flow) break;
        }
    }
    return ans;
}
bool bfs()
{
    memset(dep, 0, sizeof(dep));
    dep[s] = 1;
    queue<int> q;
    q.push(s);
    while (q.size())
    {
        int u = q.front(); q.pop();
        for (int i : G[u])
            if (!dep[e[i].v] && e[i].f)
                dep[e[i].v] = dep[u] + 1, q.push(e[i].v);
    }
    return dep[t];
}
i64 dinic()
{
    i64 ans = 0;
    while (bfs())
    {
        memset(cur, 0, sizeof(cur));
        ans += dfs(s, inf);
    }
    return ans;
}
i64 a[maxn];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    s = n + 1; t = s + 1;
    for (int i=1;i<=n;++i) cin >> a[i], a[i] = -a[i];
    while (m--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        addedge(u, v, w);
        a[u] += w;
    }
    i64 ans = 0;
    for (int i=1;i<=n;++i)
        if (a[i] > 0) ans += a[i], addedge(s, i, a[i]);
        else if (a[i] < 0) addedge(i, t, -a[i]);
    cout << ans - dinic() << '\n';
    return 0;
}