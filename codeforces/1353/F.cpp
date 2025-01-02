#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); ++i)

const long long INF64 = 1e18;

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		vector<vector<long long>> a(n, vector<long long>(m));
		forn(i, n) forn(j, m) {
			cin >> a[i][j];
		}
		long long a00 = a[0][0];
		long long ans = INF64;
		forn(x, n) forn(y, m) {
			long long need = a[x][y] - x - y;
			if (need > a00) continue;
			a[0][0] = need;
			vector<vector<long long>> dp(n, vector<long long>(m, INF64));
			dp[0][0] = a00 - need;
			forn(i, n) forn(j, m) {
				long long need = a[0][0] + i + j;
				if (need > a[i][j]) continue;
				if (i > 0) dp[i][j] = min(dp[i][j], dp[i - 1][j] + a[i][j] - need);
				if (j > 0) dp[i][j] = min(dp[i][j], dp[i][j - 1] + a[i][j] - need);
			}
			ans = min(ans, dp[n - 1][m - 1]);
		}
		cout << ans << endl;
	}
	
	return 0;
}