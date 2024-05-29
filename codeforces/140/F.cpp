#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	int n, k; std::cin >> n >> k;
	if (k >= n) {
		std::cout << "-1\n";
		return 0;
	}
	std::vector <std::pair <int, int>> a(n);
	for (auto& p : a) std::cin >> p.first >> p.second;
	std::sort(a.begin(), a.end());
	std::vector <std::pair <int,int>> ans;
	for (int l = 0; l <= k; l++) {
		for (int r = n - 1; r >= n - k - 1; r--) {
			if (l > r) continue;
			std::pair <int,int> cen = { (int) (a[l].first + a[r].first)/* / 2.0*/, (int) (a[l].second + a[r].second)/* / 2.0*/ };
			bool ex = false;
			for (auto p : ans) ex |= p == cen;
			if (ex) continue;
			// std::cerr << cen.first << " " << cen.second << "\n";
			// std::unordered_set <std::pair <int, int>> st;
			std::vector <std::pair <int,int>> v1, v2;
			for (int i = 0; i < n; i++) {
				// if ((std::pair <long double,long double>) { (long double) a[i].first/* * 2*/, (long double) a[i].second/* * 2*/ } == cen) continue;
				if (a[i].first * 2 == cen.first && a[i].second * 2 == cen.second) continue;
				std::pair <int,int> oth = { cen.first /** 2*/ - (int) a[i].first, cen.second /** 2*/ - (int) a[i].second };
				// if (st.count(oth)) st.erase(oth);
				// else st.insert(a[i]);
				v2.push_back(oth);
				v1.push_back(a[i]);
			}
			// std::sort(v1.begin(), v1.end());
			// std::sort(v2.begin(), v2.end());
			std::reverse(v2.begin(), v2.end());
			int cnt = 0;
			for (int i = 0, j = 0; i < (int) v1.size(); i++) {
				while (j < (int) v1.size() && v1[j] < v2[i]) j++;
				if (j <(int) v1.size() && v1[j] == v2[i]) {
					j++;
					continue;
				}
				cnt++;
				if ( cnt > k) break;
			}
			// for (int i = 0; i < (int) v.size(); i++) {
			// 	if (i + 1 == (int) v.size()) cnt++;
			// 	else {
			// 		if (v[i] == v[i + 1]) i++;
			// 		else cnt++;
			// 	}
			// }
			// if ((int) st.size() <= k) ans.push_back(cen);
			if (cnt <= k) ans.push_back(cen);
		}
	}
	// std::sort(ans.begin(), ans.end());
	// ans.erase(std::unique(ans.begin(), ans.end()), ans.end());
	std::cout << ans.size() << "\n";
	// std::cout << std::fixed << std::setprecision(1);
	for (auto p : ans) {
		std::cout << (p.first == -1 ? "-" : "") << p.first / 2 << (p.first & 1 ? ".5 " : " ") << (p.second == -1 ? "-" : "") <<  p.second / 2 << (p.second & 1 ? ".5\n" : "\n");
		// std::cout << p.first << " " << p.second << "\n";
	}
}
