#include <algorithm>
#include <array>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
typedef long long ll;
const ll mod = 998244353;
const int N = 3e5 + 5;
ll fac[N], inv[N];
ll fpow(ll x, ll k) {
    ll ans = 1;
    while (k) {
        if (k & 1)
            ans = ans * x % mod;
        x = x * x % mod;
        k >>= 1;
    }
    return (ans + mod) % mod;
}
void init(int n = N - 5) {
    fac[0] = 1;
    for (int i = 1; i <= n; i++)
        fac[i] = fac[i - 1] * i % mod;
    inv[n] = fpow(fac[n], mod - 2);
    for (int i = n - 1; i >= 0; i--)
        inv[i] = inv[i + 1] * (i + 1ll) % mod;
}
ll C(int n, int m) {
    if (n < 0 || m < 0 || n < m)
        return 0;
    return fac[n] * inv[m] % mod * inv[n - m] % mod;
}
array<int, 2> inter(array<int, 2> x, array<int, 2> y) {
    if (x[0] > y[0])
        swap(x, y);
    if (x[1] < y[0])
        return {0, 0};
    return {y[0], min(x[1], y[1])};
}
void solve() {
    int n, m;
    cin >> n >> m;
    init();
    vector<array<int, 2>> seg(n + 1), edge;
    vector<ll> cnt(n + 2);
    for (int i = 1; i <= n; i++) {
        int u, v;
        cin >> u >> v;
        seg[i] = {u, v};
        cnt[u]++;
        cnt[v + 1]--;
    }
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        edge.push_back({u, v});
    }
    vector<vector<ll>> f(2 * m + 1, vector<ll>(n + 1, 0));
    vector<vector<ll>> pre(2 * m + 1, vector<ll>(n + 1, 0));
    for (int i = 1; i <= n; i++)
        cnt[i] += cnt[i - 1];
    for (int i = 0; i <= 2 * m; i++) {
        for (int j = 1; j <= n; j++) {
            f[i][j] = C(cnt[j] - i, j - i);
            pre[i][j] = (f[i][j] + pre[i][j - 1]) % mod;
        }
    }
    ll ans = 0;
    for (int s = 0; s < (1 << m); s++) {
        int cnt = 0, num;
        set<int> vis;
        array<int, 2> l = {1, n};
        for (int i = 0; i < m; i++) {
            if (!((s >> i) & 1))
                continue;
            cnt++;
            auto [a, b] = edge[i];
            vis.insert(a);
            vis.insert(b);
            l = inter(l, seg[a]);
            l = inter(l, seg[b]);
        }
        if (l[0] == 0 && l[1] == 0)
            continue;
        num = vis.size();
        ans = (ans + fpow(-1, cnt & 1) * (pre[num][l[1]] - pre[num][l[0] - 1]) % mod + mod) % mod;
    }
    cout << ans << "\n";
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}