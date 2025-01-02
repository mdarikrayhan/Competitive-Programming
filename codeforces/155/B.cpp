#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (auto &x: a) {
         cin >> x.second >> x.first;
    }
    sort(a.rbegin(), a.rend());
    ll ans = 0, c = 1;
    for (int i = 0; i < n && c > 0; ++i) {
         --c;
         c += a[i].first;
         ans += a[i].second;
    }
     cout << ans;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int test = 1;
    // cin >> t;
    while (test--) {
        solve();
    }
    return 0;
}