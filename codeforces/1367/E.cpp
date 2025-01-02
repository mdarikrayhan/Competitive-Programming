#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
	int n, k;
	string s;
	cin >> n >> k >> s;

	vector<int> cnt(26);
	for (auto i : s)
		cnt[i - 'a']++;

	for (int i = n; i > 0; i--) {
		int x = 0;
		bool tr = true;
		vector<int> v = cnt;
		vector<bool> vis(i);
		for (int j = 0; j < i; j++) {
			if (vis[j]) continue;

			int x = j, cnt = 0;
			while (!vis[x]) {
				cnt++;
				vis[x] = true;
				x = (x + k) % i;
			}

			sort(v.begin(), v.end());

			if (v.back() < cnt) {
				tr = false;
				break;
			}

			v.back() -= cnt;
		}

		if (tr) return cout << i << '\n', void();
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	int T;
	cin >> T;
	while (T--) solve();
}