#include <algorithm>
#include <iostream>
#include <vector>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	std::cin >> n;

	std::vector<std::vector<std::pair<int, int>>> v(3);

	for (int i = 0; i < n; ++i) {
		int x, y, c;
		std::cin >> x >> y >> c;
		v[c - 1].emplace_back(x, y);
	}

	n /= 3;

	int ans = 0;

	std::vector<std::pair<int, int>> a(n), b(n);

	for (int t = 0; t < 2; ++t) {
		for (int u = 0; u < 2; ++u) {
			for (int p = 0; p < 2; ++p) {
				for (int i = 0; i < 3; ++i) {
					std::sort(v[i].begin(), v[i].end());
				}

				std::sort(v.begin(), v.end());

				do {
					for (int r0 = ans, r1 = ans, r2 = ans; r0 < n; ++r0) {
						r1 = std::max(r1, r0);
						while (r1 < n && v[1][r1 - r0].first <= v[0][r0].first) ++r1;
						if (r1 >= n) break;
						r2 = std::max(r2, r0);
						while (r2 < n && v[2][r2 - r0].first <= v[1][r1].first) ++r2;
						if (r2 >= n) break;
						++ans;
					}

					for (int j = 0; j < n; ++j) {
						a[j].first = v[1][j].second;
						a[j].second = v[1][j].first;
						b[j].first = v[2][j].second;
						b[j].second = v[2][j].first;
					}

					std::sort(a.begin(), a.end());
					std::sort(b.begin(), b.end());

					int low = ans + 1;
					int high = n;

					while (low <= high) {
						int k = low + (high - low) / 2;
						int l = -1;
						int r = n;
						for (int i = 0; i < k; ++i) {
							++l;
							while (l < n && a[l].second <= v[0][k - 1].first) ++l;
							--r;
							while (r >= 0 && b[r].second <= v[0][k - 1].first) --r;
						}
						if (l >= n || r < 0) {
							high = k - 1;
							continue;
						}
						if (a[l].first >= b[r].first) {
							high = k - 1;
							continue;
						}
						ans = k;
						low = k + 1;
					}
				}
				while (std::next_permutation(v.begin(), v.end()));

				for (int i = 0; i < 3; ++i) {
					for (int j = 0; j < n; ++j) {
						std::swap(v[i][j].first, v[i][j].second);
					}
				}
			}

			for (int i = 0; i < 3; ++i) {
				for (int j = 0; j < n; ++j) {
					v[i][j].first = -v[i][j].first;
				}
			}
		}

		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < n; ++j) {
				v[i][j].second = -v[i][j].second;
			}
		}
	}

	std::cout << 3 * ans << '\n';

	return 0;
}

