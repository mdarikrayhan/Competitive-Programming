// LUOGU_RID: 160380684
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5, mod = 998244353;
typedef long long ll;

int Pow(int a, int b) {
    int ret = 1;
    for (; b; b >>= 1) {
        if (b & 1) ret = (ll)ret * a % mod;
        a = (ll)a * a % mod;
    }
    return ret;
}

int T, n;
int a[MAXN], fac[MAXN], inv[MAXN];
ll sum[MAXN];
map<ll, int> cnt;

void init() {
    fac[0] = inv[0] = 1;
    int N = 1e5;
    for (int i = 1; i <= N; i++) {
        fac[i] = (ll)i * fac[i - 1] % mod;
    }
    inv[N] = Pow(fac[N], mod - 2);
    for (int i = N - 1; i >= 1; i--) {
        inv[i] = (ll)inv[i + 1] * (i + 1) % mod;
    }
}

int C(int x, int y) {
    if (y > x) return 0;
    return (ll)fac[x] * inv[y] % mod * inv[x - y] % mod;
}

void solve() {
    scanf("%d", &n);
    cnt.clear();
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        sum[i] = sum[i - 1] + a[i];
        if (i < n) cnt[sum[i]]++;
    }
    ll S = sum[n];
    int ans = 1;
    for (int i = 1; i <= n; i++) {
        if (sum[i] == sum[i + 1]) continue;
        ll x = sum[i];
        if (x * 2 < S) ans = (ll)ans * C(cnt[x] + cnt[S - x], cnt[x]) % mod;
    }
    if (S % 2 == 0)
        ans = (ll)ans * Pow(2, cnt[S / 2]) % mod;
    printf("%d\n", ans);
}

int main() {
    // freopen("input.txt", "r", stdin);
    scanf("%d", &T);
    init();
    while (T--) solve();
}