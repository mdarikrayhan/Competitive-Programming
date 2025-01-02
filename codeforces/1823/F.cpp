#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const ll mod = 998244353;
ll fpow(ll x, ll k) {
    ll ans = 1;
    while (k) {
        if (k & 1)
            ans = ans * x % mod;
        x = x * x % mod;
        k >>= 1;
    }
    return ans;
}
void solve() {
    int n, S, T;
    cin >> n >> S >> T;
    vector<vector<int>> son(n + 1, vector<int>());
    vector<ll> deg(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        son[u].push_back(v);
        son[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }
    vector<ll> f(n + 1), g(n + 1), h(n + 1);
    auto dfs1 = [&](auto self, int x, int fa) -> void {
        ll res = 0, val = 0;
        for (auto y : son[x]) {
            if (y == fa)
                continue;
            self(self, y, x);
            if (y != T) {
                res = (res + g[y] * fpow(deg[y], mod - 2) % mod) % mod;
                val = (val + h[y] * fpow(deg[y], mod - 2) % mod) % mod;
            }
        }
        res = (1 - res + mod) % mod;
        g[x] = fpow(res * deg[fa] % mod, mod - 2);
        h[x] = ((x == S) + val) % mod * fpow(res, mod - 2) % mod;
    };
    auto dfs2 = [&](auto self, int x, int fa) -> void {
        // if (x != T)
        f[x] = (g[x] * f[fa] % mod + h[x]) % mod;
        for (auto y : son[x]) {
            if (y == fa)
                continue;
            self(self, y, x);
        }
    };
    dfs1(dfs1, T, 0);
    dfs2(dfs2, T, 0);
    f[T] = 1;
    for (int i = 1; i <= n; i++)
        cout << f[i] << " \n"[i == n];
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