#include <bits/stdc++.h>

#define int long long
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using ql = __int128_t;

void solve() {
    int n;
    cin >> n;
    int x1, x2;
    cin >> x1 >> x2;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        int k, b;
        cin >> k >> b;
        a[i] = {k * x1 + b, k * x2 + b};
    }
    sort(a.begin(), a.end());
    set<int> e;
    e.insert(a[0].second);
    for (int i = 1; i < n; i++) {
        if (*--e.end() > a[i].second) {
            cout << "YES";
            return;
        }
        e.insert(a[i].second);
    }
    cout << "NO";
}

signed main() {
    //freopen("D:\\Downloads(chrome)\\26_16271.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;
    //cin >> tt;
    while (tt--) solve();
}
