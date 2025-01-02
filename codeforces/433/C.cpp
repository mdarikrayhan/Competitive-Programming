// LUOGU_RID: 160090496
#include <bits/stdc++.h>

#ifdef LOCAL
#include <debug.h>
#else
#define debug(...)
#define debug_arr(...)
#define debug_endl(...)
#endif

using i64 = long long;

void solve() {
	int n, m;
	std::cin >> n >> m;

	std::vector<int> a(m);
	for (int i = 0; i < m; i++) {
		std::cin >> a[i];
		a[i]--;
	}

	std::vector<std::vector<int>> adj(n);
	i64 sum = 0;

	for (int i = 0; i < m - 1; i++) {
		if (a[i] != a[i + 1]) {
			adj[a[i]].push_back(a[i + 1]);
			adj[a[i + 1]].push_back(a[i]);
			sum += std::abs(a[i] - a[i + 1]);
		}
	}

	i64 ans = sum;
	for (int i = 0; i < n; i++) {
		if (adj[i].empty()) {
			continue;
		}

		std::nth_element(adj[i].begin(), adj[i].begin() + adj[i].size() / 2, adj[i].end());
		int x = adj[i][adj[i].size() / 2];
		i64 cur = sum;

		for (int j : adj[i]) {
			cur -= std::abs(i - j);
			cur += std::abs(x - j);
		}

		ans = std::min(ans, cur);
	}

	std::cout << ans << "\n";
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.setf(std::ios::fixed);
	std::cout.precision(10);

	solve();

	return 0;
}