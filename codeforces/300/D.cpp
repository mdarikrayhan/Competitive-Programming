// LUOGU_RID: 160008303
#include <cstdio>
#include <cstring>
#include <algorithm>
#define int long long
#define G 3
#define _G 2446678
#define M 7340033
using namespace std;
int T, n, l, k, a[5050], r[5050], g[50][5050];
int P(int x, int y)
{
    int q = 1;
    for (; y; y >>= 1, x = x * x % M)
        if (y & 1)
            q = q * x % M;
    return q;
}
void F(int *f, int n, int v)
{
    for (int i = 0; i < n; ++i)
        if (i < r[i])
            swap(f[i], f[r[i]]);
    for (int L = 2, m; L <= n; L <<= 1)
    {
        m = L >> 1;
        int W = P(v == 1 ? G : _G, (M - 1) / L);
        for (int l = 0, r = L - 1; r <= n; l += L, r += L)
        {
            int o = 1;
            for (int p = l; p < l + m; ++p)
            {
                int x = f[p], y = f[p + m];
                f[p] = (x + o * y) % M, f[p + m] = (x + M - o * y % M) % M;
                o = o * W % M;
            }
        }
    }
}
signed main()
{
    g[0][0] = 1;
    n = 4096;
    l = __lg(n);
    for (int i = 0; i < n; ++i)
        r[i] = r[i >> 1] >> 1 | (i & 1) << l - 1;
    for (int i = 1; i <= 30; ++i)
    {
        memcpy(g[i], g[i - 1], 1 << 13);
        F(g[i], n, 1);
        for (int j = 0; j < n; ++j)
            g[i][j] = P(g[i][j], 4);
        F(g[i], n, -1);
        int _ = P(n, M - 2);
        for (int j = 0; j < n; ++j)
            g[i][j] = g[i][j] * _ % M;
        for (int j = n - 1; j >= 1; --j)
            g[i][j] = g[i][j - 1];
        g[i][0] = 1;
        memset(g[i] + (1 << 10), 0, n - (1 << 10) << 3);
    }
    scanf("%lld", &T);
    while (T--)
    {
        scanf("%lld%lld", &n, &k);
        int o = 0;
        while (n & 1 && n > 1)
            n = n - 1 >> 1, ++o;
        printf("%lld\n", g[o][k]);
    }
    return 0;
}