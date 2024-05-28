#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 1e9 + 7;

ll exp(ll n, ll e) {
    ll res = 1;
    while (e) {
        if (e & 1) res = res * n % mod;
        n = n * n % mod;
        e >>= 1;
    }
    return res;
}

void solve() {
    int k, n; cin >> k >> n;
    ll bnd = (1ll << k) - 1;
    map<ll, vector<ll>> tree;
    set<ll> qu;
    while (n--) {
        ll x; cin >> x;
        string s; cin >> s;
        qu.insert(x);
        if (s == "white" || s == "yellow") tree[x] = {1, 0, 0};
        else if (s == "green" || s == "blue") tree[x] = {0, 1, 0};
        else tree[x] = {0, 0, 1};
    }
    while (!qu.empty()) {
        ll x = *qu.rbegin();
        qu.erase(x);
        if (x == 1) break;
        ll t = x >> 1;
        qu.insert(t);
        if (tree.find(t) == tree.end())
            tree[t] = {2, 2, 2};
        for (int i = 0; i < 3; i++) {
            tree[t][i] = tree[t][i] * (tree[x][(i + 1) % 3] + tree[x][(i + 2) % 3]) % mod;
        }
    }
    ll ans = exp(4, bnd - tree.size());
    ll t = (tree[1][0] + tree[1][1] + tree[1][2]) % mod;
    ans = ans * t % mod;
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int T = 1; // cin >> T;
    while (T--) { solve(); }
    return 0;
}