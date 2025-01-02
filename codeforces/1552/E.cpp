#ifdef LOCAL
    #define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>

#ifndef LOCAL
    // #pragma GCC optimize("O3")
    // #pragma GCC optimize("Ofast")
    // #pragma GCC optimize("unroll-loops")
    // #pragma GCC target("avx,avx2,bmi,bmi2,popcnt,lzcnt")
#endif
using namespace std;
using ll = long long;
using ld = long double;
#define x first
#define y second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

mt19937_64 mt(time(0));

void solve();
void init();

int32_t main() {
#ifndef LOCAL
    cin.tie(nullptr)->sync_with_stdio(false);
#endif
    cout << fixed << setprecision(30);
    init();
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}

void init() {}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> free(n, 1), a(n * k);
    for (int i = 0; i < n * k; i++) {
        cin >> a[i]; a[i]--;
    }
    vector<pair<int, int>> ans;
    vector<pair<int, int>> nans(n);
    while (ans.size() != n) {
        vector<int> pr(n, -1);
        int nw = 0;
        for (int i = 0; i < n * k; i++) {
            if (pr[a[i]] >= nw && free[a[i]]) {
                nans[a[i]] = {pr[a[i]] + 1, i + 1};
                ans.emplace_back(pr[a[i]] + 1, i + 1);
                nw = i + 1;
                free[a[i]] = 0;
            } else {
                pr[a[i]] = i;
            }
        }
    }
    for (auto [l, r] : nans) {
        cout << l << ' ' << r << '\n';
    }
}
