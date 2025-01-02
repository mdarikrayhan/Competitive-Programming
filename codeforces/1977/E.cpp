#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t; cin >> t;
	auto ask = [&](int u, int v) {
		if (u > v) {
			swap(u, v);
		}
		cout << "? " << u + 1 << " " << v + 1 << endl;
		string ret; cin >> ret; return ret == "YES";
	};
	while (t--) {
		int n; cin >> n;
		vector<int> left = {n - 1}, right = {}, tail = {};
		for (int u = n - 2; u >= 0; u--) {
			if (!tail.empty()) {
				if (ask(tail.back(), u)) {
					tail.push_back(u);
				} else if (ask(left.back(), u)) {
					left.push_back(u);
					right.insert(right.end(), tail.begin(), tail.end());
					tail.clear();
				} else {
					right.push_back(u);
					left.insert(left.end(), tail.begin(), tail.end());
					tail.clear();
				}
			} else {
				bool lf = ask(left.back(), u);
				bool rf = right.empty() ? false : ask(right.back(), u);
				(lf && rf ? tail : lf ? left : right).push_back(u);
			}
		}
		vector<bool> ok(n);
		for (auto x : left) {
			ok[x] = true;
		}
		cout << "!";
		for (int i = 0; i < n; i++) {
			cout << " " << ok[i];
		}
		cout << endl;
	}
}