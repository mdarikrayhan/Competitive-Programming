#include <bits/stdc++.h>
using namespace std;

const int P = 1000000007;
int lg[1000005];
int sum[1000005];
int vis[1000005];
signed main() {
	int n, m, k;
	cin >> n >> m >> k;
	lg[0] = 1;
	for (int i = 1; i <= n; i++) {
		lg[i] = (lg[i - 1] * 2) % P;
	}
	int cnt = 0;
	for (int i = 1; i <= m; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		if (x > y) {
			swap(x, y);
		}
		if (x + 1 == y) {
			;
		}
		else if (x + k + 1 == y) {
			vis[x] = 1;
			cnt++;
		}
		else {
			cout << 0;
			return 0;
		}
	}
	if (cnt == 0) {
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			if (i + k + 1 > n) {
				continue;
			}int v;
			if (i + 2 * k >= n) {
				v = n - k - 1;
			}else {
				v = i + k;
			}
			ans += lg[v - i];
			ans %= P;
	   }
	   cout << ans + 1; 
	   return 0;
	}
	int a = 0, b = 0;
	for (int i = 1; i <= n; i++) {
		if (vis[i]) {
			a = i;
		}sum[i] = sum[i - 1] + vis[i];
	}
	for (int i = n; i >= 1; i--) {
		if (vis[i]) {
			b = i;
		}
	}
	if (b + k + 1 <= a) {
		cout << 0;
		return 0;
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (vis[i] || i + k + 1 > n || i >= b + k + 1 || i + k + 1 <= a) {
			continue;
		}
		int ta = a, tb = b;
		if (i < b) {
			b = i;
		}
		if (i > a) {
			a = i;
		}
		int v;
		if (b + 2 * k >= n) {
			v = n - k - 1;
		}else {
			v = b + k;
		}
		int id = v - i + 1 - sum[v] + sum[i - 1];
		ans += lg[id - 1];
		ans %= P;
		a = ta;
		b = tb;
	}
	cout << ans + 1;
	return 0;
}
