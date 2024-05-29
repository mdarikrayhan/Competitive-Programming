// LUOGU_RID: 160004685
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define mp make_pair
#define db double
const int maxn = 1e6 + 10;
const int mod = 1e9 + 7;
const int inf = 0x3f3f3f3f;

namespace IO {
void openfile() {
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
#endif
}
void Min(int& x, int y) {
    x = (x < y) ? x : y;
}
void Max(int& x, int y) {
    x = (x > y) ? x : y;
}
int add(int x, int y) {
    return (x + y) >= mod ? (x + y - mod) : (x + y);
}
int sub(int x, int y) {
    return (x < y) ? (x + mod - y) : (x - y);
}
void Add(int& x, int y) {
    x = (x + y) >= mod ? (x + y - mod) : (x + y);
}
void Sub(int& x, int y) {
    x = (x < y) ? (x - y + mod) : (x - y);
}
int mul(int x, int y) {
    return 1ll * x * y % mod;
}
void Mul(int& x, int y) {
    x = 1ll * x * y % mod;
}
int qpow(int x, int y = mod - 2) {
    int ans = 1;
    while (y) {
        if (y & 1)
            ans = 1ll * x * ans % mod;
        x = 1ll * x * x % mod, y >>= 1;
    }
    return ans;
}
inline int read() {
    int x = 0, f = 0;
    char c = getchar();
    while (!isdigit(c))
        f |= c == '-', c = getchar();
    while (isdigit(c))
        x = x * 10 + c - '0', c = getchar();
    if (f)
        x = -x;
    return x;
}
}  // namespace IO
using namespace IO;

int n, a[maxn], h[maxn], w[maxn], p[maxn];
int b[maxn], f[110][110], C[110][110], dp[maxn], fac[maxn];

void init() {
    for (int i = 0; i <= n; i++) {
        C[i][0] = 1;
        for (int j = 1; j <= i; j++)
            C[i][j] = add(C[i - 1][j - 1], C[i - 1][j]);
    }
    fac[0] = 1;
    for (int i = 1; i <= n; i++)
        fac[i] = mul(fac[i - 1], i);
    for (int i = 0; i < n; i++) {
        f[i][0] = 1;
        for (int j = 0; j <= i; j++)
            Add(f[i][1], mul(C[i][j], mul(fac[j], fac[n - j - 1])));
        for (int j = 2; j <= n - i; j++)
            f[i][j] = mul(f[i][j - 1], f[i][1]);
    }
}

int vis[maxn], s[maxn], siz[maxn];

signed main() {
    openfile();
    n = read(), init();
    for (int i = 1; i <= n; i++)
        a[i] = read();
    for (int i = 1; i <= n; i++)
        if (!vis[i]) {
            int now = i, cnt = 0;
            while (!vis[now])
                cnt++, vis[now] = 1, now = a[now];
            b[cnt]++;
        }
    s[0] = dp[0] = 1;
    for (int i = 1; i <= n; i++)
        s[i] = s[i - 1] * (b[i] + 1);
    for (int x = 1; x < s[n]; x++) {
        int t = 1;
        p[1] = 0, w[1] = mod - 1;
        for (int i = 1; i <= n; i++) {
            int tmp = t, num = (x / s[i - 1]) % (b[i] + 1);
            siz[x] += i * num;
            for (int j = 1; j <= num; j++)
                for (int k = 1; k <= tmp; k++) {
                    p[++t] = p[k] + j * s[i - 1];
                    w[t] = 1ll * w[k] * ((j & 1) ? (mod - 1) : 1) % mod * C[num][j] % mod;
                }
        }
        // cout << x << ":\n";
        // for (int i = 2; i <= t; i++)
        //     cout << p[i] << ' ' << w[i] << endl;
        for (int i = 2; i <= t; i++) {
            Add(dp[x], 1ll * dp[x - p[i]] * f[siz[x] - siz[p[i]]][siz[p[i]]] % mod * w[i] % mod);
            // cout << x << ' ' << f[siz[x] - siz[p[i]]][siz[p[i]]] << ' ' << dp[x - p[i]] << endl;
        }
    }
    cout << dp[s[n] - 1] << endl;
    return 0;
}
