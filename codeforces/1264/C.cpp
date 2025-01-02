// LUOGU_RID: 159720664
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

const int mod = 998244353, N = 2e5 + 5;

int a[N], type[N], inv[N], pre[N], sum[N];

int qpow(int x, int y) {
    int a = 1;
    while (y) {
        if (y & 1) a = a * x % mod;
        x = x * x % mod;
        y /= 2;
    }
    return a;
}

set<int> s;

int getans(int l, int r) {
    int Inv = inv[r - 1] * pre[l - 1] % mod;
    int res = (sum[r - 2] + mod - ((l > 1) ? sum[l - 2] : 0)) % mod * inv[l - 1] % mod;
    return res * Inv % mod;
}

signed main() {
    int n = read(), q = read(), Inv = qpow(100, mod - 2);

    pre[0] = 1;
    sum[0] = 1;
    for (int i = 1; i <= n; i++) {
        a[i] = read() * Inv % mod;
        pre[i] = pre[i - 1] * a[i] % mod;
        sum[i] = (sum[i - 1] + pre[i]) % mod;
        type[i] = 0;
    }

    inv[n] = qpow(pre[n], mod - 2);
    for (int i = n - 1; i >= 1; i--) inv[i] = inv[i + 1] * a[i + 1] % mod;
    inv[0] = 1;

    type[1] = 1;
    s.insert(1);
    s.insert(n + 1);

    int ans = getans(1, n + 1);

    while (q--) {
        int x = read();
        if (type[x]) {
            s.erase(x);
            auto it = s.lower_bound(x);
            int r = *it;
            it--;
            int l = *it;
            ans += mod - getans(l, x) + mod - getans(x, r);
            ans += getans(l, r);
            ans %= mod;
        }
        else {
            auto it = s.lower_bound(x);
            int r = *it;
            it--;
            int l = *it;
            ans += mod - getans(l, r);
            ans += getans(l, x) + getans(x, r);
            ans %= mod;
            s.insert(x);
        }
        type[x] ^= 1;
        write(ans);
        putchar('\n');
    }
}