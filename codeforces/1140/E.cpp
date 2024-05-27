// LUOGU_RID: 159903145
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
constexpr int maxn = 200000 + 10;
constexpr int mod = 998244353;
int a[maxn];
int f[maxn][2];
i64 qp(i64 a, i64 b)
{
    i64 c = 1;
    for (; b; b>>=1, a=a*a%mod)
        if (b & 1) c=c*a%mod;
    return c;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    for (int i=1;i<=n;++i) cin >> a[i];
    f[0][0] = 1; f[0][1] = 0;
    for (int i=1;i<=n;++i) // f[i][0] 不相同，f[i][1] 相同
    {
        f[i][0] = (f[i - 1][1] + (k - 2ll) * f[i - 1][0]) % mod;
        f[i][1] = (k - 1ll) * f[i - 1][0] % mod;
    }
    vector<int> v[2];
    for (int i=1;i<=n;++i) v[i & 1].emplace_back(a[i]);
    i64 ans = 1;
    for (int i=0;i<2;++i)
    {
        vector<int> x;
        for (int j=0;j<v[i].size();++j) if (v[i][j] != -1) x.emplace_back(j);
        if (!x.size()) ans = ans * k % mod * qp(k - 1, v[i].size() - 1) % mod;
        else
        {
            ans = ans * qp(k - 1, x[0] + v[i].size() - x.back() - 1) % mod;
            for (int j=1;j<x.size();++j) ans = ans * f[x[j] - x[j - 1] - 1][v[i][x[j - 1]] == v[i][x[j]]] % mod;
        }
    }
    cout << ans << '\n';
    return 0;
}