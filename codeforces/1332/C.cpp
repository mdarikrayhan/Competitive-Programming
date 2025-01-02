#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

void solve() {
    int n, k; cin >> n >> k;
    string s; cin >> s;
    vector<map<char, int>> mp(k);
    for (int i = 0; i < n; ++i) {
        int tmp = i % k;
        if (tmp >= k / 2) {
            tmp = k - tmp - 1;
        }
        mp[tmp][s[i]]++;
    }

    int ans = 0;
    for (int i = 0; i < k / 2; ++i) {
        int mx = 0;
        for (auto [x, y] : mp[i]) {
            mx = max(mx, y);
        }
        ans += n / k * 2 - mx;
    }
    if (k % 2 != 0) {
        int mx = 0;
        for (auto [x, y] : mp[k / 2]) {
            mx = max(mx, y);
        }
        ans += n / k - mx;
    }

    cout << ans << '\n';
}


signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int t; cin >>t;
    while (t--) {
        solve();
    }
    return 0;
}