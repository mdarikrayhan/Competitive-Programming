# include <iostream>
# include <cstdio>
# include <cmath>
# include <algorithm>
# include <cstring>
# include <vector>
# include <map>
# include <climits>
# include <unordered_map>
using namespace std;
int n;

vector <pair <int, pair <int, int> > > ans;
void add(int a, int b, int c) {
	ans.push_back({a, {b, c}});
}
void solve() {
	cin >> n;
	if (n <= 100) {
		for (int i = 4; i < n; i += 4) {
			if (4 * i + 6 >= n) {
				add(i - 1, i, i + 1);
			}
		}
	}
	if (n % 4 == 0) add(1, n - 1, n);
	if (n % 4 == 3) {
		add(1, 2, n);
	}
	if (n > 100) {
		for (int i = 4; i < n; i += 4) {
			if (2 * i + 6 >= n) {
				add(i - 1, i, i + 1);
			}
		}
		int s = n;
		while (s % 4 != 2) s--;
		while (2 * s > n) {
			add(s, s - 4, s - 8);
			s -= 12;
		}
	}

	cout << ans.size() << "\n";
	for (auto x : ans) {
		cout << x.first << " " << x.second.first << " " << x.second.second << "\n";
	}
	ans.clear();
}

int main() {
	ios_base::sync_with_stdio(false);
	int w;
	cin >> w;
	while (w--) {
		solve();
	}
	return 0;
}
