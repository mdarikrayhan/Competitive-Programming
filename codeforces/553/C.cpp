// LUOGU_RID: 159764294
#include <bits/stdc++.h>
typedef long long LL;
int read()
{
    int s = 0, f = 1;
    char c = getchar();
    while (!(c >= '0' && c <= '9'))
        f ^= (c == '-'), c = getchar();
    while (c >= '0' && c <= '9')
        s = s * 10 + (c ^ 48), c = getchar();
    return f ? s : -s;
}
const int MAXN = 100005, MOD = 1e9 + 7;
auto fplus = [](int x, int y){ return x + y >= MOD ? x + y - MOD : x + y; };
auto fminus = [](int x, int y){ return x >= y ? x - y : x + MOD - y; };
auto Fplus = [](int &x, int y){ return x = fplus(x, y); };
auto Fminus = [](int &x, int y){ return x = fminus(x, y); };
int fpow(int x, int y = MOD - 2)
{
    int res = 1;
    for (; y; y >>= 1, x = (LL)x * x % MOD)
        if (y & 1) res = (LL)res * x % MOD;
    return res;
}
namespace DSU
{
    int fa[MAXN], val[MAXN];
    void init(int n)
    {
        std::iota(fa + 1, fa + n + 1, 1);
        memset(val + 1, 0, n << 2);
    }
    int getFath(int x)
    {
        if (x == fa[x]) return x;
        int f = getFath(fa[x]);
        return val[x] ^= val[fa[x]], fa[x] = f;
    }
    bool merge(int x, int y, int v)
    {
        int fx = getFath(x), fy = getFath(y);
        if (fx  == fy && (v ^ val[x] ^ val[y])) return false;
        if (fx != fy) fa[fx] = fy, val[fx] = v ^ val[x] ^ val[y];
        return true;  
    }
}
int n, m;
int main()
{
    n = read(), m = read();
    DSU::init(n);
    for (int i = 1; i <= m; i++)
    {
        int u = read(), v = read(), w = read() ^ 1;
        if (!DSU::merge(u, v, w)) return printf("0\n"), 0;
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++)
        cnt += DSU::getFath(i) == i;
    printf("%d\n", fpow(2, cnt - 1));
    return 0;
}