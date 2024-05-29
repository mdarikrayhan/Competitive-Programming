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

int main() {
	int n, m;
	cin >> n >> m;
	vector<long long> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	long long first = 0, second = 0;
	for (int s = 2; s <= m << 1; ++s) {
		vector<int> b(n + 2);
		for (int i = 0; i < n; ++i) {
			b[i + 1] = a[i] % s;
		}
		b[0] = 0;
		b[n + 1] = s - 1;
		sort(b.begin(), b.end());
		for (int i = n + 1, who = 0; i; --i, who = !who) {
			int l = b[i - 1] + 1, r = min(b[i], m);
			if (!who) {
				l = max(l, (b[n] >> 1) + 1);
			} else {
				l = max(l, (b[n - 1] >> 1) + 1);
			}
			int low = max(l, s - r), high = min(r, s - l);
			if (low <= high) {
				if (!who) {
					second += high - low + 1;
				} else {
					first += high - low + 1;
				}
			}
		}
	}
	long long each = (long long)m * m - first - second >> 1;
	cout << each << " " << each << " " << first << " " << second << endl;
	return 0;
}
