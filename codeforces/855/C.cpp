// LUOGU_RID: 159626673
#include <bits/stdc++.h>
#define int long long
typedef long long LL;
const int N = 1E5 + 5, X = 11, mod = 1E9 + 7;
int n, x, sz[N], dp[N][X][3], mem[X][3];
LL m, K;
std::vector<int> adj[N];
void get_sz(int u, int p) {
	sz[u] = 1;
	for (int i = 0; i < adj[u].size(); i++) {
		int &v = adj[u][i];
		if (v == p) continue;
		get_sz(v, u);
		sz[u] += sz[v];
	}
}
void knapsack(int u, int p) {
	dp[u][0][0] = K - 1;
	dp[u][1][1] = 1;
	dp[u][0][2] = m - K;
	for (int i = 0; i < adj[u].size(); i++) {
		int &v = adj[u][i];
		if (v == p) continue;
		knapsack(v, u);
		memcpy(mem, dp[u], sizeof(dp[u]));
		memset(dp[u], 0, sizeof(dp[u]));
		for (int j = std::min(sz[u], x); j >= 0; j--) {
			for (int k = 0; k <= std::min(sz[v], j); k++) {
				dp[u][j][0] = (dp[u][j][0] + mem[j - k][0] * (dp[v][k][0] + dp[v][k][1] + dp[v][k][2]) % mod) % mod;
				dp[u][j][1] = (dp[u][j][1] + mem[j - k][1] * dp[v][k][0] % mod) % mod;
				dp[u][j][2] = (dp[u][j][2] + mem[j - k][2] * (dp[v][k][0] + dp[v][k][2]) % mod) % mod;
			}
		}
	}
}
signed main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cin >> n >> m;
	for (int i = 1; i < n; i++) {
		int u, v; std::cin >> u >> v;
		adj[u].emplace_back(v);
		adj[v].emplace_back(u);
	}
	std::cin >> K >> x;
	get_sz(1, 0);
	knapsack(1, 0);
	int ans = 0;
	for (int i = 0; i <= x; i++) {
		for (int j = 0; j < 3; j++) {
			ans = (ans + dp[1][i][j]) % mod;
		}
	}
	std::cout << ans % mod << '\n';
	return 0;
}