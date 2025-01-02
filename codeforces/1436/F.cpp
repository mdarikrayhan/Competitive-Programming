// LUOGU_RID: 158928978
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define pr pair<int, int>
#define mid (l + r) / 2
#define ls num << 1
#define rs num << 1 | 1

inline int read() {
    int x = 0, mm = 1;
    char ch = getchar();

    while (!isdigit(ch)) {
        if (ch == '-') mm = -1;
        ch = getchar();
    }

    while (isdigit(ch)) {
        x = x * 10 + ch - 48;
        ch = getchar();
    }

    return x * mm;
}

inline void write(int x) {
    if (x < 0) {
        putchar('-');
        write(-x);
        return;
    }

    if (x >= 10) write(x / 10);
    putchar(x % 10 + '0');
}

const int N = 1e5 + 5, mod = 998244353;

int a[N], cnt[N], vis[N], mul[N];
vector<int> num[N], id[N];

int qpow(int x, int y) {
    x %= mod;
    int a = 1;

    while (y) {
        if (y & 1) a = a * x % mod;
        x = x * x % mod;
        y /= 2;
    }

    return a;
}

signed main() {
    int n = read(), m = 0;

    for (int i = 1; i <= n; i++) {
        m = max(m, a[i] = read());
        cnt[i] = read();
    }

    for (int i = 1; i <= m; i++) {
        for (int j = i; j <= m; j += i) {
            num[j].pb(i);
        }
        mul[i] = 1;
    }

    for (int i = 2; i <= m; i++) {
        if (!vis[i]) {
            mul[i] = mod - 1;
            for (int j = 2 * i; j <= m; j += i) {
                vis[j] = 1;
                (mul[j] *= (mod - 1)) %= mod;
                if ((j / i) % i == 0) mul[j] = 0;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (auto u : num[a[i]]) {
            id[u].pb(i);
        }
    }

    int ans = 0;

    for (int i = 1; i <= m; i++) {
        int sum = 0, Cnt = 0;
        for (auto u : id[i]) {
            (sum += cnt[u] * a[u]) %= mod;
            Cnt += cnt[u];
        }
        int res = 0;
        for (auto u : id[i]) {
            if (Cnt > 1) {
                (res += (sum + mod - a[u]) % mod * a[u] % mod * qpow(2, Cnt - 2) % mod * cnt[u] % mod) %= mod;
                (res += a[u] * a[u] % mod * qpow(2, Cnt - 2) % mod * ((Cnt - 1) % mod) % mod * cnt[u] % mod) %= mod;
            }
            if (Cnt > 2) (res += (sum + mod - a[u]) % mod * a[u] % mod * ((Cnt - 2) % mod) % mod * qpow(2, Cnt - 3) % mod * cnt[u] % mod) %= mod;
        }
        (ans += res * mul[i] % mod) %= mod;
    }

    write(ans);
    putchar('\n');
}