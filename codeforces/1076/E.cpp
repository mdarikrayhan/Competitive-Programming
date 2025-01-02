// LUOGU_RID: 159903011
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
constexpr int maxn = 600000 + 10;
vector<int> g[maxn];
using pii = pair<int, int>;
vector<pii> v[maxn];
i64 s[maxn];
i64 f[maxn];
i64 cnt;
int d[maxn];
void dfs(int u, int fa)
{
    d[u] = d[fa] + 1;
    for (auto [x, y] : v[u]) s[d[u]] += y, s[d[u] + x + 1] -= y;
    cnt += s[d[u]];
    f[u] = cnt;
    for (int v : g[u]) if (v != fa) dfs(v, u);
    cnt -= s[d[u]];
    for (auto [x, y] : v[u]) s[d[u]] -= y, s[d[u] + x + 1] += y;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i=1;i<n;++i)
    {
        int u, v;
        cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    int m;
    cin >> m;
    while (m--)
    {
        int u, d, x;
        cin >> u >> d >> x;
        d = min(d, n);
        v[u].emplace_back(pii(d, x));
    }
    dfs(1, 0);
    for (int i=1;i<=n;++i) cout << f[i] << ' ';
    cout << '\n';
    return 0;
}