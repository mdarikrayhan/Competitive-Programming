#include <bits/stdc++.h>
using namespace std;

int32_t main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int n; cin >> n;
	vector<pair<int, int>> v(n);
	for (auto &[x, y] : v)cin >> x >> y;
	vector<int> dp(40, 0);
	for (int i = 0; i < 30; i++) {
		int ran = 1 << i;
		vector<pair<int, int>> c;
		for (auto [x, y] : v) {
			if (y - x + 1 >= ran) {
				c.push_back({0, 1});
				c.push_back({ran, -1});
			} else {
				x %= ran;
				y %= ran;
				if (x <= y) {
					c.push_back({x, 1});
					c.push_back({y + 1, -1});
				} else {
					c.push_back({x, 1});
					c.push_back({ran, -1});
					c.push_back({0, 1});
					c.push_back({y + 1, -1});
				}
			}
		}
		sort(c.begin(), c.end());
		int s = 0;
		for (auto [x, y] : c) {
			s += y;
			dp[i] = max(dp[i], s);
		}
	}
	int q; cin >> q; while (q--) {
		int w; cin >> w;
		int x = __builtin_ctz(w);
		cout << dp[x] << '\n';
	}
}