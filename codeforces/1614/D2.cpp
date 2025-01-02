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
void solve() {
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
	for (int i = 1; i < N; i++) {
		if (!b[i]) continue;
		for (auto j : pri) {
			if (j * i >= N) break;
			dp[j * i] = std::max(dp[j * i] , dp[i] + 1ll * (b[i] - b[j * i]) * i);
		}
	}
	ll ans = 0;
	for (auto j : a) {
		ans = std::max(ans , dp[j] + 1ll * b[j] * j);
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