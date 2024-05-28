#include <bits/stdc++.h>
#define x first
#define y second
#define eps 1e-8
#define endl '\n'
#define int long long
#define INF 0x3f3f3f3f3f3f3f3f
#define IOS ios::sync_with_stdio(false);cin.tie(NULL);

using namespace std;
using PII = pair<int, int>;

const int N = 2e5 + 5, M = N << 1, MOD = 998244353;
vector<int> ve[N];
int dp[N][2];
int n, m;

int qmi(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1)
			res = (res * a) % MOD;
		a = (a * a) % MOD;
		b >>= 1;
	}
	return res;
}

void dfs(int p) {
	if (ve[p].empty()) {
		dp[p][0] = dp[p][1] = 1;
		return;
	}
	int now = 1, now2 = 1;
	for (auto j : ve[p]) {
		dfs(j);
		now = (now * (dp[j][0] + dp[j][1])) % MOD;
		now2 = (now2 * dp[j][0]) % MOD;
	}
	int g = 0;
	for (auto j : ve[p])
		g = (g + now2 * qmi(dp[j][0], MOD - 2) % MOD * dp[j][1]) % MOD;
	dp[p][0] = (now - g + MOD) % MOD;
	dp[p][1] = (now - now2 + MOD) % MOD;
}

void solve() {
	cin >> n;
	for (int i = 2; i <= n; i++) {
		cin >> m;
		ve[m].push_back(i);
	}
	dfs(1);
	cout << dp[1][0] << endl;
}

signed main(void) {
	IOS;
	int t = 1;
	//cin >> t;
	while (t--)
		solve();
	return 0;
}

