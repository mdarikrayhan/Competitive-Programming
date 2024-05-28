#include <bits/stdc++.h>
#pragma GCC optimize("-O3")
using namespace std;
typedef long long ll;
vector<vector<vector<ll>>> g;
vector<ll> p, z, a, c, ans;
vector<priority_queue<vector<ll>>> s;
void dfs(ll v) {
    for (auto to : g[v]) {
        if (to[0] != p[v]) p[to[0]] = v, z[to[0]] = to[1], dfs(to[0]);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n;
    cin >> n;
    a.resize(n);
    vector<pair<ll, ll>> x;
    for (ll i = 0; i < n; ++i) cin >> a[i];
    g.resize(n);
    for (ll i = 0; i < n - 1; ++i) {
        ll u, v, w;
        cin >> u >> v >> w;
        g[--u].push_back({--v, w});
        g[v].push_back({u, w});
    }
    p.resize(n);
    z.resize(n);
    dfs(0);
    s.resize(n);
    c.resize(n);
    ans.assign(n, 1e18);
    for (ll i = 0; i < n; ++i) c[i] = i, x.push_back({a[i], i});
    sort(x.begin(), x.end());
    for (ll t = 0; ; ++t) {
        bool b = false;
        vector<ll> y(n, 0);
        for (ll i = 0; i < n; ++i) {
            if (c[x[i].second]) {
                b = true;
                if (y[c[x[i].second]] < z[c[x[i].second]]) ++y[c[x[i].second]], c[x[i].second] = p[c[x[i].second]];
            } else ans[x[i].second] = min(ans[x[i].second], t);
        }
        if (!b) break;
    }
    for (ll i = 0; i < n; ++i) cout << ans[i] << " ";
}