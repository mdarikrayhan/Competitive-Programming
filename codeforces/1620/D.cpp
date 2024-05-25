#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define X first
#define Y second
#define umap unordered_map
using ll = long long;
typedef pair<int, int> pii;
const int maxn = 5e5 + 5, mod = 998244353, maxp = 25, inf = 1e9;
const ll INF = 1e18;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int ans = inf;
	for (int ct1 = 0; ct1 <= 5; ct1++) {
		for (int ct2 = 0; ct2 <= 5; ct2++) {
			vector<int> dp(105);
			dp[0] = 1;
			for (int i = 1; i <= ct1; i++) {
				for (int j = 100; j >= 1; j--) {
					dp[j] |= dp[j - 1];
				}
			}
			for (int i = 1; i <= ct2; i++) {
				for (int j = 100; j >= 2; j--) {
					dp[j] |= dp[j - 2];
				}
			}
			bool f = 1;
			for (int i = 1; i <= n && f; i++) {
				int x = a[i];
				f = 0;
				for (int j = 0; j <= min(100, x) && f == 0; j++) {
					if (dp[j] && (x - j) % 3 == 0) f = 1;
				}
			}
			if (f == 0) continue;
			int ct3 = 0;
			for (int i = 1; i <= n; i++) {
				int x = a[i];
				int min_ = inf;
				for (int j = min(100, x); j >= 0 && min_ == inf; j--) {
					if (dp[j] == 0) continue;
					if ((x - j) % 3) continue;
					min_ = (x - j) / 3;
				}
				ct3 = max(ct3, min_);
			}
			ans = min(ans, ct1 + ct2 + ct3);
		}
	}
	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int tt = 1;
	cin >> tt;
	while (tt--) solve();
	return 0;
}