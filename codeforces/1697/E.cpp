// LUOGU_RID: 160081633
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
constexpr int maxn = 100 + 10;
constexpr int mod = 998244353;
int x[maxn], y[maxn];
int d(int a, int b)
{
    return abs(x[a] - x[b]) + abs(y[a] - y[b]);
}
int f[maxn];
int find(int x)
{
    return f[x] == x ? x : f[x] = find(f[x]);
}
int g[maxn], h[maxn];
int m[maxn], o[maxn];
i64 qp(i64 a, i64 b)
{
    i64 c = 1;
    for (; b; b>>=1, a=a*a%mod)
        if (b & 1) c=c*a%mod;
    return c;
}
i64 fac[maxn], inv[maxn];
i64 A(int n, int m)
{
    if (n < m) return 0;
    return fac[n] * inv[n - m] % mod;
}
vector<int> e[maxn];
int main()
{
    fac[0] = 1;
    for (int i=1;i<maxn;++i) fac[i] = fac[i - 1] * i % mod;
    inv[maxn - 1] = qp(fac[maxn - 1], mod - 2);
    for (int i=maxn-2;i>=0;--i) inv[i] = inv[i + 1] * (i + 1) % mod;
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i=1;i<=n;++i) cin >> x[i] >> y[i];
    iota(f + 1, f + n + 1, 1);
    for (int i=1;i<=n;++i)
    {
        m[i] = 0x3f3f3f3f;
        for (int j=1;j<=n;++j) if (i != j) m[i] = min(m[i], d(i, j));
        for (int j=1;j<=n;++j) if (i != j && d(i, j) == m[i]) e[i].emplace_back(j);
    }
    for (int i=1;i<=n;++i)
    {
        vector<int> v(n + 1);
        queue<int> q;
        q.push(i);
        v[i] = 1;
        while (q.size())
        {
            int u = q.front(); q.pop();
            for (int i : e[u]) if (!v[i]) q.push(i), v[i] = 1;
        }
        o[i] = 1;
        for (int j=1;j<=n;++j)
            for (int k=j+1;k<=n;++k)
                if (v[j] && v[k]) o[i] &= d(j, k) == m[i];
    }
    for (int i=1;i<=n;++i)
        if (o[i])
            for (int j=1;j<=n;++j)
                if (j != i && d(i, j) == m[i]) f[find(i)] = find(j);
    int s = 0;
    vector<int> w;
    for (int i=1;i<=n;++i)
    {
        vector<int> v;
        for (int j=1;j<=n;++j) if (find(j) == i) v.emplace_back(j);
        if (v.size() < 2) continue;
        int p = d(v[0], v[1]), o = 1;
        for (int i=0;i<v.size();++i)
            for (int j=i+1;j<v.size();++j)
                if (d(v[i], v[j]) != p) o = 0;
        if (o) s += v.size(), w.emplace_back(v.size());
    }
    g[0] = 1;
    for (int x : w)
    {
        memcpy(h, g, sizeof(g));
        memset(g, 0, sizeof(g));
        for (int i=1;i<=n;++i) g[i] = h[i - 1];
        for (int i=x;i<=n;++i) g[i] = (g[i] + h[i - x]) % mod;
    }
    i64 ans = 0;
    for (int i=0;i<=n;++i) ans = (ans + g[i] * A(n, i + n - s)) % mod;
    cout << ans << '\n';
    return 0;
}