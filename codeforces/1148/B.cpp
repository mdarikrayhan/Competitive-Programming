#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define X first
#define Y second
#define umap unordered_map
using ll = long long;
typedef pair<int, int> pii;
const int maxn = 5e5 + 5, mod = 998244353, maxp = 25, inf = 1e9;
const ll INF = 1e18;

void solve() {
	ll n, m, ta, tb, k;
	cin >> n >> m >> ta >> tb >> k;
	ll ans = 0;
	vector<ll> a(n + 1), b(m + 1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= m; i++) {
		cin >> b[i];
	}
	if (k >= min(n, m)) {
		cout << -1 << endl;
		return;
	}
	for (int i = 0; i <= min(n, k); i++) {
		int j = k - i;
		auto idx = lower_bound(b.begin(), b.end(), a[i + 1] + ta) - b.begin();
		if (idx + j > m) {
			cout << -1 << endl;
			return;
		}
		ans = max(ans, b[idx + j] + tb);
	}
	cout << ans << endl;
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