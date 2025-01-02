#pragma warning (disable:4998)
#pragma warning (disable:4996)

#include <bits/stdc++.h>
#include <cassert>

const int inf = 2e9;
const long long ill = 4e18;
const long long mod = 1e9 + 7;
const long double eps = 1e-6;

//#define int long long
#define pii pair<int, int>
#define tui tuple<int, int, ll>
typedef long long ll;
typedef long double ld;

using namespace std;

vector<vector<int>> g;
vector<int> used;


struct girl {
	int g=-1, b=0, w=0;
};

bool cmp(girl a, girl b) {
	return a.g < b.g;
}

void dfs(int v, int col, vector<girl>& db) {
	used[v] = 1;
	db[v].g = col;
	for (int u : g[v])
		if (!used[u])
			dfs(u, col, db);
}

void solve() {
	int n, m, W;
	cin >> n>>m>>W;
	vector<girl> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i].w;
	for (int i = 0; i < n; i++)
		cin >> a[i].b;
	g.resize(n);
	used.resize(n);
	for (int i = 0; i < m; i++) {
		int v, u;
		cin >> v >> u;
		v--, u--;
		g[v].push_back(u);
		g[u].push_back(v);
	}
	int col =0;
	for (int i = 0; i < n; i++) {
		if (!used[i])
			dfs(i, col++, a);
	}
	vector<int> dp(W+1, -inf);
	vector<int> dp2(W + 1, -inf);
	dp[0] =0;
	dp2[0] =0;
	sort(a.begin(), a.end(), cmp);
	col = 0;
	int sb = 0, sw = 0;
	for (int i = 0; i < n; i++) {
		if (a[i].g != col) {
			for (int cw = W; cw >= sw; cw--)
					dp2[cw] =max(dp2[cw],dp[cw-sw]+sb);
			for (int cw = W; cw >= 0; cw--)
				dp[cw] = max(dp2[cw], dp[cw]);
			sw = 0, sb = 0, col=a[i].g;
			dp2.clear();
			dp2.resize(W + 1, -inf);
			dp2[0] = 0;
		}
		for (int cw = W; cw >= a[i].w; cw--)
			dp2[cw] =max(dp[cw - a[i].w] + a[i].b, dp2[cw]);
		sw += a[i].w, sb += a[i].b;
	}
	for (int cw = W; cw >= sw; cw--)
		dp2[cw] = max(dp2[cw], dp[cw - sw] + sb);
	for (int cw = W; cw >= 0; cw--)
		dp[cw] = max(dp2[cw], dp[cw]);
	int mx = 0;
	for (int i = 1; i <= W; i++)
		mx = max(mx, dp[i]);
	cout << mx << '\n';
	
}

signed main() {
	//freopen("snakes.in", "r", stdin);
	//freopen("snakes.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	int t = 1;
	//cin >> t;
	while (t--)
		solve();

}