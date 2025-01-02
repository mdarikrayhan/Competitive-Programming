#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
constexpr int maxn = 1000 + 10;
constexpr int maxm = 12;
constexpr int mod = 1000000000 + 7;
int f[maxn][maxm][1 << maxm], t[maxm][1 << maxm];
vector<int> g[maxn];
int n, m;
int lim;
int e[maxm][maxm], s[maxm][maxm];
int get(int u, int fa)
{
    int msk = 1 << u;
    for (int v=0;v<m;++v)
        if (v != fa && e[u][v]) msk |= get(v, u);
    return msk;
}
i64 qp(i64 a, i64 b)
{
    i64 c = 1;
    for (; b; b>>=1, a=a*a%mod)
        if (b & 1) c=c*a%mod;
    return c;
}
int ans;
void upd(int& a, int b)
{
    a += b;
    if (a >= mod) a -= mod;
}
void dfs(int u, int fa)
{
    for (int i=0;i<m;++i) f[u][i][1 << i] = 1;
    for (int v : g[u])
    {
        if (v == fa) continue;
        dfs(v, u);
        memcpy(t, f[u], sizeof(t));
        for (int i=0;i<m;++i)
            for (int k=0;k<m;++k)
                if (e[i][k])
                    for (int j=0;j<lim;++j)
                        if ((j >> i & 1) && !(j & s[k][i]))
                            upd(f[u][i][j | s[k][i]], (i64) t[i][j] * f[v][k][s[k][i]] % mod);
    }
    for (int i=0;i<m;++i) upd(ans, f[u][i][lim - 1]);
}
i64 calc()
{
    ans = 0;
    dfs(0, 0);
    return ans;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i=1;i<n;++i)
    {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    cin >> m;
    lim = 1 << m;
    for (int i=1;i<m;++i)
    {
        int u, v;
        cin >> u >> v;
        --u; --v;
        e[u][v] = e[v][u] = 1;
    }
    for (int i=0;i<m;++i)
        for (int j=0;j<m;++j)
            if (e[i][j]) s[i][j] = get(i, j);
    i64 ans = calc();
    for (int i=0;i<n;++i) g[i].clear();
    n = m;
    for (int i=0;i<m;++i)
        for (int j=0;j<m;++j)
            if (e[i][j]) g[i].emplace_back(j);
    memset(f, 0, sizeof(f));
    ans = ans * qp(calc(), mod - 2) % mod;
    cout << ans << '\n';
    return 0;
}