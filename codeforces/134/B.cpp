// LUOGU_RID: 160096696
#include <bits/stdc++.h>

#ifdef LOCAL
#include <debug.h>
#else
#define debug(...)
#define debug_arr(...)
#define debug_endl(...)
#endif

constexpr int inf = 1e9;

void solve() {
	int n;
	std::cin >> n;

	auto solve = [&](auto &&self, int x, int y) -> int {
		if (!x) {
			return inf;
		} else if (x == 1) {
			return y - 1;
		} else {
			return self(self, y % x, x) + y / x;
		}
	};

	int ans = inf;
	for (int i = 1; i <= n; i++) {
		ans = std::min(ans, solve(solve, i, n));
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