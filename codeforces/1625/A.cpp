#include<bits/stdc++.h>

using i64 = long long;

int main(void) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	auto solve = [&]() {
		int n, l; std::cin >> n >> l;

		std::vector<int>a(n + 1);
		for (int i = 1; i <= n; i += 1) {
			std::cin >> a[i];
		}

		int ans = 0;

		for (int i = 0; i <= l; i += 1) {
			i64 pre = 0;
			for (int j = 1; j <= n; j += 1) {
				if (~a[j] >> i & 1) {
					pre += 1 << i;
				}
			}
			i64 suf = 0;
			for (int j = 1; j <= n; j += 1) {
				if (a[j] >> i & 1) {
					suf += 1 << i;
				}
			}
			if (pre < suf) {
				ans |= 1 << i;
			}
		}
		std::cout << ans << "\n";
	};

	int t;
	std::cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}