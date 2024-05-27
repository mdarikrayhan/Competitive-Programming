// LUOGU_RID: 160137940
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3e5 + 5, mod = 998244353;
typedef long long ll;

int Pow(int a, int b) {
    int ret = 1;
    for (; b; b >>= 1) {
        if (b & 1) ret = (ll)ret * a % mod;
        a = (ll)a * a % mod;
    }
    return ret;
}

int n, m;
int fac[MAXN], inv[MAXN];
ll a[MAXN], sum[MAXN];
map<ll, int> mp;

void init(int x) {
    fac[0] = inv[0] = 1;
    for (int i = 1; i <= x; i++) {
        fac[i] = (ll)i * fac[i - 1] % mod;
    }
    inv[x] = Pow(fac[x], mod - 2);
    for (int i = x - 1; i >= 0; i--) {
        inv[i] = (ll)inv[i + 1] * (i + 1) % mod;
    }
}

int C(int x, int y) {
    if (y > x) return 0;
    return (ll)fac[x] * inv[y] % mod * inv[x - y] % mod;
}

int main() {
    // freopen("input.txt", "r", stdin);
    scanf("%d%d", &n, &m);
    init(max(n, m));
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        sum[i] = sum[i - 1] + a[i];
        mp[sum[i]]++;
    }
    if (sum[n] & 1) {
        printf("%d\n", Pow(m, n));
        return 0;
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (mp[sum[n] / 2 + sum[i]])
            cnt++;
    }
    int ans = 0;
    for (int i = 0; i <= min(cnt, m); i++) {
        int coef1 = (ll)C(cnt, i) * C(m, i) % mod * fac[i] % mod;
        int coef2 = Pow(C(m - i, 2) * 2ll % mod, cnt - i);
        ans = (ans + (ll)coef1 * coef2 % mod * Pow(m - i, n - 2 * cnt) % mod) % mod;
    }
    printf("%d\n", ans);
}