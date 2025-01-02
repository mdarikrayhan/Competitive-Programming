#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define X first
#define Y second
#define umap unordered_map
using ll = long long;
typedef pair<int, int> pii;
const int maxn = 2e5 + 5, mod = 1e9 + 7, maxp = 26, inf = 1e9;
const ll INF = 1e18;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<ll> a(n), b(m);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> b[i];
	}
	for (int i = n - 1; i > 0; i--) {
		a[i] -= a[i - 1];
	}
	ll gcd = 0;
	for (int i = 1; i < n; i++) {
		gcd = __gcd(a[i], gcd);
	}
	for (int i = 0; i < m; i++) {
		if (gcd % b[i] == 0) {
			cout << "YES" << endl;
			cout << a[0] << " " << i + 1 << endl;
			return;
		}
	}
	cout << "NO" << endl;
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