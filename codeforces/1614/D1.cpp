#include<bits/stdc++.h>
using ll = long long;
const int N = 2e7 + 1;
int p[N], b[N];
std::vector<int> pri;
void init() {
	for (int i = 2; i < N; i++) {
		if (p[i]) continue;
		pri.push_back(i);
		if (1ll * i * i >= N) continue;
		for (int j = i * i; j < N; j += i) {
			p[j] = 1;
		}
	}
}
int n;
ll dp[N];
ll dfs(int x) {
	if (dp[x] != -1) {
		return dp[x];
	}
	ll ans = n - b[x];
	for (int i = 2; i <= x / i; i++) {
		if (x % i == 0) {
			ans = std::max(ans , dfs(i) + 1ll * (b[i] - b[x]) * i);
			ans = std::max(ans , dfs(x / i) + 1ll * (b[x / i] - b[x]) * (x / i));
		}
	}
	return dp[x] = ans;
}
void solve() {
	memset(dp, -1, sizeof(dp));
	std::cin >> n;
	std::vector<int> a(n);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
		b[a[i]]++;
	}
	for (auto j : pri) {
		for (int i = (N - 1) / j; i > 0; i--) {
			b[i] += b[i * j];
		}
	}
	// for (int i = 0; i < 8; i++) {
	// 	std::cout << "i: " << i << " " << b[i] << std::endl;
	// }
	ll ans = 0;
	for (auto j : a) {
		ans = std::max(ans , dfs(j) + 1ll * b[j] * j);
	}
	std::cout << ans;
}
signed main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0), std::cout.tie(0);
	int t = 1;
	init();
	// std::cin >> t;
	while (t--) solve();
}