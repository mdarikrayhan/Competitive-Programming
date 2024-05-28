// LUOGU_RID: 160427838
#pragma GCC optimize("Ofast", "inline", "-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")

#include <bits/stdc++.h>
#define int long long

#define F(i, a, b) for (int i = (a); i <= (b); i++)
#define dF(i, a, b) for (int i = (a); i >= (b); i--)
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int N = 5005, M = (N << 1), mod = 1e9 + 7, inv2 = mod + 1 >> 1;
int n, a[N], an[M], g[M * 2], iv[M * 2];
unsigned f[M][N];
int qpow(int a, int b = mod - 2) {
    int res = 1; 
    for (; b; b >>= 1, a = a * a % mod)
        if (b & 1) res = res * a % mod;
    return res;
}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n; g[0] = 1;
    F(i, 1, n - 1) cin >> a[i], g[i] = g[i - 1] * a[i] % mod, iv[i] = qpow(g[i]);
    for (int i = 1; i < n; i ++)
        for (int j = i + 1, mul = 1; j <= n; j ++)
            mul = mul * a[j - 1] % mod, (an[j - i] += mul * g[i - 1] % mod) %= mod;
    F(i, 1, n - 1) f[2][i] = g[i] * g[i] % mod;
    F(i, 3, n * 2 - 2) F(j, 1, n - 1)
        f[i][j] = (f[i - 2][j + 1] + 2ll * g[j] % mod * g[i + j - 2] % mod) % mod;
    F(i, 2, n * 2 - 2) F(j, 1, n - 1)
        (an[i] += iv[j] * (a[j] - 1) % mod * inv2 % mod * f[i][j] % mod) %= mod;
    F(i, 1, n * 2 - 2) cout << an[i] << ' ';
    return 0;
}
