#include"bits/stdc++.h"

using namespace std;

inline void solve() {
	int n;
	cin >> n;
	vector<int> b(n, 0), a(n + 1, 0);
	for (int i = 1; i < n; i++) cin >> b[i];
	a[1] = b[1];
	a[n] = b[n - 1];
	for (int i = 2; i < n; i++) a[i] = min(b[i], b[i - 1]);
	for (int i = 1; i <= n; i++) {
		if (i == n) {
			cout << a[i] << endl;
			break;
		}
		cout << a[i] << ' ';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}