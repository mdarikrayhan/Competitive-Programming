#include <bits/stdc++.h>

using namespace std;
void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    int n, u, r, d, l;
    cin >> n >> u >> r >> d >> l;
    for (int i = 0; i < 16; i++) {
        int uu = u, rr = r, dd = d, ll = l;
        if (i & 1) uu--, ll--;
        if (i & 2) uu--, rr--;
        if (i & 4) rr--, dd--;
        if (i & 8) dd--, ll--;
        if (min({uu, rr, dd, ll}) >= 0 && max({uu, rr, dd, ll}) <= n - 2) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}
int main() {
    fast_io();
    int t;
    cin >> t;
    for (; t--;) {
        solve();
    }
}