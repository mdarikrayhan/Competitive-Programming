#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n; cin >> n;
    vector<vector<ll>> cs(n, vector<ll>(3));
    for (ll i = 0; i < n; ++i) {
        cin >> cs[i][0] >> cs[i][1] >> cs[i][2];
    }
    vector<ll> co(3);
    bool works = 1;
    vector<ll> visited(n);
    auto dfs = [&](auto& self, ll node, ll color) {
        if (visited[node]) {
            if (visited[node] != color) works = 0;
            return;
        }
        ++co[color];
        visited[node] = color;
        for (ll nn = 0; nn < n; ++nn) {
            ll r = cs[node][2] + cs[nn][2];
            ll xd = abs(cs[node][0] - cs[nn][0]);
            ll yd = abs(cs[node][1] - cs[nn][1]);
            if (r * r == xd * xd + yd * yd) {
                self(self, nn, ((color == 1) ? 2 : 1));
            }
        }
    };
    bool yes = 0;
    for (ll i = 0; i < n; ++i) {
        if (!visited[i]) {
            fill(co.begin(), co.end(), 0);
            works = 1;
            dfs(dfs, i, 1);
            if (works && co[1] != co[2]) yes = 1;
        }
    }
    cout << (yes ? "YES\n" : "NO\n");
    return 0;
}
