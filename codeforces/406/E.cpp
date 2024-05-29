#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	long long n, m; std::cin >> n >> m;
	std::map <long long, long long> a[2];
	for (long long i = 0; i < m; i++) {
		long long u, v; std::cin >> u >> v;
		a[!u][n * !u + v * -(1 - 2 * u)]++;
	}
	long long ans = 0;
	long long best = ~0ULL >> 1;
	for (long long it = 0; it < 2; it++, std::swap(a[0], a[1])) {
		if (a[0].empty()) continue;
		long long cur = n + a[0].begin()->first - a[0].rbegin()->first;
		for (auto p : a[1]) {
			long long x1 = n - a[0].rbegin()->first - p.first;
			long long x2 = - n + a[0].begin()->first + p.first;
			cur = std::min(cur, std::max(0LL, x1) + std::max(0LL, x2));
		}
		long long s0 = 0;
		for (auto p : a[0]) s0 += p.second;
		ans *= best <= cur;
		best = std::min(best, cur);
		if (best < cur) continue;
		if (!(s0 ^ 1)) continue;
		if (!best) {
			std::vector <std::pair <long long, long long>> t;
			for (auto p : a[0]) t.emplace_back(p);
			for (long long i = 1; i < ( long long) t.size(); i++) t[i].second += t[i - 1].second;
			t.insert(t.begin(), { ~0LL ^ (long long) (~0ULL >> 1), 0 });
			t.emplace_back(~0ULL >> 1, t.back().second);
			for (auto p : a[1]) {
				long long pref = std::lower_bound(t.begin(), t.end(), (std::pair <long long, long long>) { n - p.first, 0 }) - t.begin();
				pref = t[pref - 1].second;
				pref *= s0 - pref - (a[0].count(n - p.first) ? a[0][n - p.first] : 0);
				if (a[0].count(n - p.first)) pref += a[0][n - p.first] *(long long) (a[0][n - p.first] - 1) / 2;
				if (a[0].count(n - p.first)) pref += a[0][n - p.first] *(long long) (s0 - a[0][n - p.first]);
				ans += pref * p.second;
			}
			continue;
		}
		if (a[1].count(n - a[0].rbegin()->first - best)) {
			long long range = s0 * (s0 - 1) / 2;
			range -= (s0 - a[0].rbegin()->second) * (s0 - a[0].rbegin()->second - 1) / 2;
			ans += a[1][n - a[0].rbegin()->first - best] * range;
		}
		if (a[1].count(n - a[0].begin()->first + best)) {
			long long range = s0 * (s0 - 1) / 2;
			range -= (s0 - a[0].begin()->second) * (s0 - a[0].begin()->second - 1) / 2;
			ans += a[1][n - a[0].begin()->first + best] * range;
		}
		if (n + a[0].begin()->first - a[0].rbegin()->first == best) {
			long long fr = a[0].begin()->second;
			long long bk = a[0].rbegin()->second;
			ans += !(a[0].begin()->first - a[0].rbegin()->first) * bk * (bk - 1) * (bk - 2) / 6;
			ans += !!(a[0].begin()->first - a[0].rbegin()->first) * fr * bk * (fr + bk - 2) / 2;
			ans += !!(a[0].begin()->first - a[0].rbegin()->first) * fr * bk * (s0 - fr - bk);
		}
	}
	std::cout << ans << "\n";
}
