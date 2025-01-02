#include <bits/stdc++.h>
#define int long long

using namespace std;

const int kMaxN = 2e5 + 10, kInf = 1e18;

int a[kMaxN], t, n, ans, maxn;

signed main() {
	for (cin >> t; t; t--) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		sort(a + 1, a + 1 + n);
		ans = maxn = a[n];
		bool f2 = 0, f3 = 0, f5 = 0;
		for (int i = 1; i <= n; i++) {
			if (a[i] * 2 == a[n]) {
				f2 = 1;
			} else if (a[i] * 3 == a[n]) {
				f3 = 1;
			} else if (a[i] * 5 == a[n]) {
				f5 = 1;
			}
		}
		if (f2 == 1 && f3 == 1 && f5 == 1) {
			ans = max(ans, maxn / 2 + maxn / 3 + maxn / 5);
		}
		for (int i = 1; i <= n; i++) {
			if (!(a[n] % a[i])) {
				a[i] = kInf;
			}
		}
		sort(a + 1, a + 1 + n);
		for (; a[n] == kInf; n--) {
		}
		ans = max(ans, maxn + a[n]);
		for (int i = 1; i <= n; i++) {
			if (maxn % a[i] && a[n] % a[i]) {
				ans = max(ans, maxn + a[n] + a[i]);
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
	  		  		   	 			    	  		  		