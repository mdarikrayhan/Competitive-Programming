// LUOGU_RID: 160526283
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

	i64 t;
	std::cin >> t;

	std::vector<int> s(n);
	std::vector<char> d(n);

	for (int i = 0; i < n; i++) {
		std::cin >> s[i] >> d[i];
		s[i]--;
	}

	std::vector<int> a(n);
	for (int i = 0; i < n; i++) {
		a[i] = d[i] == 'L' ? (s[i] - t % m + m) % m : (s[i] + t % m) % m;
	}
	std::ranges::sort(a);

	int x = 0;
	for (int i = 0; i < n; i++) {
		if (d[i] == 'L') {
			x = (x - (t + m - 1 - s[i]) / m % n + n) % n;
		} else {
			x = (x + (t + s[i]) / m % n) % n;
		}
	}

	std::vector<int> o(n);
	std::iota(o.begin(), o.end(), 0);
	std::ranges::sort(o, [&](int i, int j) -> bool {
		return s[i] < s[j];
	});

	std::vector<int> ans(n);
	for (int i = 0; i < n; i++) {
		ans[o[i]] = a[(i + x) % n];
	}

	for (int i = 0; i < n; i++) {
		std::cout << ans[i] + 1 << " ";
	}
	std::cout << "\n";
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.setf(std::ios::fixed);
	std::cout.precision(10);

	solve();

	return 0;
}