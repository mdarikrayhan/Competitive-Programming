// LUOGU_RID: 159769739
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
int n, m, K, a[MAXN], rem[MAXN];
bool vis[MAXN];
std::vector<int> e[MAXN];
bool chk(double lim)
{
    for (int i = 1; i <= n; i++)
    {
        int d = e[i].size();
        rem[i] = d - (int)ceil(d * lim);
    }
    memset(vis + 1, false, n);
    static int q[MAXN], fr, ba;
    memcpy(q + 1, a + 1, K << 2), fr = 1, ba = K;
    for (int i = 1; i <= K; i++) rem[a[i]] = -1;
    while (fr <= ba)
    {
        int x = q[fr++];
        vis[x] = true;
        for (int y : e[x])
            if ((--rem[y]) == -1) q[++ba] = y;
    }
    return ba < n;
}
int main()
{
    n = read(), m = read(), K = read();
    for (int i = 1; i <= K; i++) a[i] = read();
    for (int i = 1; i <= m; i++)
    {
        int u = read(), v = read();
        e[u].push_back(v), e[v].push_back(u);
    }
    double l = 0, r = 1;
    while (l + 1e-9 < r)
    {
        double mid = (l + r) / 2;
        if (chk(mid)) l = mid;
        else r = mid;
    }
    chk(l);
    int cnt = 0;
    for (int i = 1; i <= n; i++)
        if (!vis[i]) ++cnt;
    printf("%d\n", cnt);
    for (int i = 1; i <= n; i++)
        if (!vis[i]) printf("%d ", i);
    return 0;
}