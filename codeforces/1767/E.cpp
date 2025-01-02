#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
constexpr int maxn = 300000 + 10;
constexpr int maxm = 45;
constexpr int maxk = 20;
int e[maxm][maxm];
int a[maxn], x[maxm];
int f[1 << maxk];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i=1;i<=n;++i) cin >> a[i], --a[i];
    e[a[1]][a[1]] = e[a[n]][a[n]] = 1;
    for (int i=1;i<n;++i) e[a[i]][a[i + 1]] = e[a[i + 1]][a[i]] = 1;
    for (int i=0;i<m;++i) cin >> x[i];
    int lim = 1 << maxk;
    for (int i=0;i<lim;++i)
    {
        int ok = 1, s = 0;
        for (int j=0;j<maxk;++j)
            if (~i >> j & 1)
                for (int k=j;k<maxk;++k)
                    if (~i >> k & 1)
                        if (e[j][k]) ok = 0;
        for (int j=0;j<maxk;++j)
            if (i >> j & 1) s += x[j];
        f[i] = ok ? s : 0x3f3f3f3f;
    }
    for (int i=1;i<lim;i<<=1)
        for (int j=0;j<lim;++j)
            if (j & i) f[i ^ j] = min(f[i ^ j], f[j]);
    int ans = 0x3f3f3f3f;
    for (int i=0;i<lim;++i)
    {
        int ok = 1, s = 0;
        for (int j=0;j<maxk;++j)
            if (~i >> j & 1)
                for (int k=j;k<maxk;++k)
                    if (~i >> k & 1)
                        if (e[j + maxk][k + maxk]) ok = 0;
        for (int j=0;j<maxk;++j)
            if (i >> j & 1) s += x[j + maxk];
        int msk = 0;
        for (int j=0;j<maxk;++j)
            if (~i >> j & 1)
                for (int k=0;k<maxk;++k)
                    if (e[j + maxk][k]) msk |= 1 << k;
        if (ok) ans = min(ans, s + f[msk]);
    }
    cout << ans << '\n';
    return 0;
}