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
	int n, p;
	std::cin >> n >> p;

	std::vector<std::string> s(n);
	for (int i = 0; i < n; i++) {
		std::cin >> s[i];
	}

	i64 x = 0, ans = 0;
	for (int i = n - 1; i >= 0; i--) {
		if (s[i] == "halfplus") {
			x += p / 2;
		}
		ans += x;
		x *= 2;
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