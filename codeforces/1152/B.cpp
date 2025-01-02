#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define X first
#define Y second
#define umap unordered_map
using ll = long long;
typedef pair<int, int> pii;
const int maxn = 2e5 + 5, mod = 1e9 + 7, maxp = 30, inf = 1e9;
const ll INF = 1e18;

void solve() {
	int x;
	cin >> x;
	vector<int> ans;
	while (1) {
		bool f = 0, ff = 0, fff = 0;
		for (int i = maxp; i >= 0; i--) {
			if (f == 0) {
				if (x >> i & 1) f = 1;
			}
			else {
				if ((x >> i & 1) == 0) {
					ff = 1;
					x ^= (1 << (i + 1)) - 1;
					ans.push_back(i + 1);
					break;
				}
			}
		}
		for (int i = 0; i <= maxp; i++) {
			if (x == (1 << (i)) - 1) {
				fff = 1;
				break;
			}
		}
		if (fff) break;
		x++;
		ans.push_back(1);
		for (int i = 0; i <= maxp; i++) {
			if (x == (1 << (i)) - 1) {
				fff = 1;
				break;
			}
		}
		if (fff) break;
	}
	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); i += 2) {
		cout << ans[i] << " ";
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int tt = 1;
	// cin >> tt;
	while (tt--) solve();
	return 0;
}