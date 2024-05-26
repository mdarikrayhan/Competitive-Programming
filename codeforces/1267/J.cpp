#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> c(n + 1);
    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;
        c[a]++;
    }
    vector<int> ans(n + 10);
    auto calc = [&](int x) {
        // cerr << x << ":\n";
        for(int s = 1; s <= x + 1; ) {
            int t1 = (x + s - 1) / s;
            int r1 = t1 == 1 ? 1e9 : (x + t1 - 2) / (t1 - 1) - 1;
            int t2 = s == 1 ? 1e9 : x / (s - 1);
            int r2 = s == 1 ? 1e9 : x / t2 + 1;
            int r = min({r1, r2, x + 1});
            // cerr << x << ' ' << s << ' ' << t1 << ' ' << r1 << ' ' << t2 << ' ' << r2 << ' ' << r << '\n';
            if (t1 <= t2) {
                ans[s]++;
                ans[r + 1]--;
            }
            s = r + 1;
        }
        // cerr << "-------------------\n";
    };
    int cnt = 0;
    for(int i = 1; i <= n; i++) if(c[i]) {
        calc(c[i]);
        cnt++;
    }
    // cerr << "ok\n";
    int mxs = 0;
    for(int i = 1; i <= n + 1; i++) {
        ans[i] += ans[i - 1];
        if(ans[i] == cnt) {
            mxs = max(mxs, i);
        }
    }
    // cerr << mxs << '\n';
    // cerr << "ok\n";
    int res = 0;
    for(int i = 1; i <= n; i++) {
        res += (c[i] + mxs - 1) / mxs;
    }
    cout << res << '\n';
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}