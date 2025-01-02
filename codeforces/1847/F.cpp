#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve() {
    int n, q;
    cin >> n >> q;
    vector < int > a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    const int LOGA = 40;
    vector < pair < int , int > > ve = {{a[0], 1}};
    vector < int > p(LOGA, -1e9);
    for (int i = 0; i <= n; i++) for (int j = 0; j < LOGA; j++) if ((a[i % n] >> j) & 1) p[j] = i - n;
    vector < int > ps;
    for (int i = 1; i < n; i++) {
        ps.clear();
        for (int j = 0; j < LOGA; j++) if ((a[i] >> j) & 1) p[j] = i;
        for (int j = 0; j < LOGA; j++) if (p[j] > -1e9) ps.push_back(p[j]);
        sort(begin(ps), end(ps)); ps.erase(unique(begin(ps), end(ps)), end(ps));
        reverse(begin(ps), end(ps));
        int x = 0;
        for (auto j : ps) {
            x |= a[(j + n) % n];
            ve.push_back({x, (i - j) * (n - 1) + i + 1});
        }
    }
    sort(begin(ve), end(ve));
    vector < pair < int , int > > vv;
    for (auto u : ve) {
        while (vv.size() > 0 && vv.back().second >= u.second) vv.pop_back();
        vv.push_back(u);
    }
    while (q--) {
        int v;
        cin >> v;
        auto it = lower_bound(begin(vv), end(vv), make_pair(v, (int)1e18));
        cout << (it == vv.end() ? (int)-1 : it -> second) << '\n';
    }
}
main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n = 1;
    cin >> n;
    while (n--) solve();
}
