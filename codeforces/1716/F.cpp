// LUOGU_RID: 159688213
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 998244353;
const int N = 2005;
const int INF = 0x3f3f3f3f;
ll powmod(ll x, ll y) {
    ll res = 1;
    while (y) {
        if (y & 1) res = res * x % mod;
        y >>= 1;
        x = x * x % mod;
    }
    return res;
}
ll s[N][N];
int main() {
    s[0][0] = 1;
    for (int i = 1; i <= 2000; i++) {
        for (int j = 1; j <= 2000; j++) {
            s[i][j] = s[i - 1][j - 1] + s[i - 1][j] * j;
            s[i][j] %= mod;
        }
    }
    int _;
    scanf("%d", &_);
    while (_--) {
        ll n, m, k;
        scanf("%lld%lld%lld", &n, &m, &k);
        ll now = powmod(m, n);
        ll ans = 0;
        ll x = (m + 1) / 2;
        for (int j = 1; j <= k; j++) {
            now = now * (n - j + 1) % mod * x % mod * powmod(m, mod - 2) % mod;
            ans = (ans + s[k][j] * now % mod) % mod;
        }
        printf("%lld\n", ans);
    }
    return 0;
}
