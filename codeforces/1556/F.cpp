#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
const int N = 2e6 + 5;
ll inv[N];
void init(int n = N - 5) {
    inv[1] = 1;
    for (int i = 2; i <= n; i++)
        inv[i] = mod - (mod / i * inv[mod % i] % mod) % mod;
}
void solve() {
    int n;
    cin >> n;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    vector<vector<ll>> f(n + 1, vector<ll>(1 << n));
    vector<vector<ll>> g(n + 1, vector<ll>(1 << n));
    for (int i = 1; i <= n; i++) {
        for (int s = 0; s < (1 << n); s++) {
            if ((s >> (i - 1)) & 1)
                continue;
            ll res = 1;
            for (int j = 1; j <= n; j++)
                if ((s >> (j - 1)) & 1)
                    res = res * a[j] % mod * inv[a[i] + a[j]] % mod;
            g[i][s] = res;
        }
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int s = 0; s < (1 << n); s++) {
            if (!((s >> (i - 1)) & 1))
                continue;
            for (int t = s; t; t = (t - 1) & s) {
                if (!((t >> (i - 1)) & 1) || t == s)
                    continue;
                int r = s ^ t;
                ll res = 1;
                for (int j = 1; j <= n; j++) {
                    if ((t >> (j - 1)) & 1)
                        res = res * g[j][r] % mod;
                }
                res = res * f[i][t] % mod;
                f[i][s] = (f[i][s] + res) % mod;
            }
            f[i][s] = (1 - f[i][s] + mod) % mod;
        }
        ans = (ans + f[i][(1 << n) - 1]) % mod;
    }
    cout << ans << "\n";
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    // cin >> T;
    init();
    while (T--) {
        solve();
    }
    return 0;
}