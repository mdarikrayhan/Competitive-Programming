#include "bits/stdc++.h"
const long long MOD = 1e13 + 93;
const int mod = 998244353;
using namespace std;
#define trace(x) cout << #x << " = " << x << endl
#define all(x) x.begin(), x.end()
#define ld long double
#define ll long long
#define pb push_back
#define mp make_pair
#define S second
#define F first
const ll base = 7001;
set<ll> hashes;

void solve() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        ll ha = 0;

        for (auto c : s) {
            ha = (ha * base + c) % MOD;
        }
        hashes.insert(ha);
    }

    for (int i = 0; i < m; i++) {
        string s;
        cin >> s;
        ll ha = 0;

        for (auto c : s) {
            ha = (ha * base + c) % MOD;
        }
        bool ans = 0;
        ll x = 1;

        for (int j = s.size() - 1; j >= 0; j--) {
            for (char c : {'a', 'b', 'c'}) {
                if (s[j] == c) continue;
                ll h = (ha - s[j] * x) % MOD;
                if (h < 0) h += MOD;
                h = (h + x * c) % MOD;
                if (hashes.count(h)) ans = 1;
            }
            x = (x * base) % MOD;
        }
        if (ans) cout << "YES\n";
        else cout << "NO\n";
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    signed t = 1;
    // cin >> t;
    while (t--) solve();
}
