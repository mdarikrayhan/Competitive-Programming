// LUOGU_RID: 160639913
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
constexpr int maxn = 1000000 + 10;
constexpr int mod = 1000000000 + 7;
i64 fac[maxn], inv[maxn];
i64 qp(i64 a, i64 b)
{
    i64 c = 1;
    for (; b; b>>=1, a=a*a%mod)
        if (b & 1) c=c*a%mod;
    return c;
}
i64 C(int n, int m)
{
    if (n < m) return 0;
    return fac[n] * inv[m] % mod * inv[n - m] % mod;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    fac[0] = 1;
    for (int i=1;i<maxn;++i) fac[i] = fac[i - 1] * i % mod;
    inv[maxn - 1] = qp(fac[maxn - 1], mod - 2);
    for (int i=maxn-2;i>=0;--i) inv[i] = inv[i + 1] * (i + 1) % mod;
    int n, m;
    cin >> n >> m;
    i64 ans = 0;
    for (int i=0;i<n;++i) ans = (ans + qp(m, i + 1) * qp(m + m - 1, n - i - 1) % mod) % mod;
    cout << (ans + qp(m, n)) % mod << '\n';
    return 0;
}