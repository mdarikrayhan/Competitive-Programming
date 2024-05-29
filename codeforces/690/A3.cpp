// LUOGU_RID: 159871775
#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
int sol(const vector<int>& v, int p) {
	int sum = 0, n = v.size() + 1;
	for (int q : v) sum += q;
	return (p - sum % n + n) % n + 1;
}
signed main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	while (T --) {
		static int n, r;
		cin >> n >> r;
		static vector<int> c;
		c.clear();
		for (int i = 1, x; i < n; ++ i) {
			cin >> x;
			c.push_back(x);
		}
		cout << sol(c, r) << '\n';
	}
	return 0;
}