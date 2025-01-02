#include <bits/stdc++.h>

using ll = signed long long int;

#define all(x) (x).begin(), (x).end()

using pii = std::pair<int, int>;
using pll = std::pair<ll, ll>;

using namespace std;

const int R = 12, INF = 2e9;

bool check(int x, int n) {
	return (0 <= x && x < n);
}

void solve() {
	int n, m, k;
	cin >> n >> m >> k;
	vector<string> gr(n);
	for (int i = 0; i < n; ++i) {
		cin >> gr[i];
	}
	vector<pii> cord(k);
	vector<int> p(k);
	for (int i = 0; i < k; ++i) {
		cin >> cord[i].first >> cord[i].second >> p[i];
		--cord[i].first;
		--cord[i].second;
	}
	vector<vector<int> > cover(k, vector<int>(R + 1));
	for (int i = 0; i < k; ++i) {
		int x = cord[i].first;
		int y = cord[i].second;
		for (int r = 1; r <= R; ++r) {
			for (int dx = -r; dx <= r; ++dx) {
				for (int dy = -r; dy <= r; ++dy) {
					int nx = x + dx;
					int ny = y + dy;
					if (!check(nx, n) || !check(ny, m)) {
						continue;
					}
					if ((x - nx) * (x - nx) + (y - ny) * (y - ny) <= r * r) {
						cover[i][r] += (gr[nx][ny] == '#');
					}
				}
			}
		}
	}
	vector<vector<int> > dp(k + 1, vector<int>(1 << R, -INF));
	dp[0][0] = 0;
	for (int i = 1; i <= k; ++i) {
		for (int mask = 0; mask < (1 << R); ++mask) {
			dp[i][mask] = dp[i - 1][mask];
			for (int r = 1; r <= R; ++r) {
				int j = r - 1;
				if (!(mask & (1 << j))) {
					continue;
				}
				dp[i][mask] = max(dp[i][mask], dp[i - 1][mask ^ (1 << j)] +
				                  p[i - 1] * cover[i - 1][r]);
			}
		}
	}
	int ans = 0;
	for (int mask = 0; mask < (1 << R); ++mask) {
		int hp = 0, mlt = 3;
		for (int j = 0; j < R; ++j) {
			if (mask & (1 << j)) {
				hp += mlt;
			}
			mlt *= 3;
		}
		for (int i = 0; i <= k; ++i) {
			ans = max(ans, dp[i][mask] - hp);
		}
	}
	cout << ans << '\n';
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}