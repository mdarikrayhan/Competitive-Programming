// LUOGU_RID: 159215670
#include <bits/stdc++.h>
#define int long long
using namespace std;
int t;
int l, r;
const int mod = 998244353;

signed main() {
	cin >> t;
	while (t--) {
		cin >> l >> r;
		int x = 0;
		while ((l << x) <= r)
			x++;
		cout << x << " ";
		int ans = r / (1 << (x - 1)) - l + 1;
		if (x > 1)
			ans += max((r / ((1 << (x - 2)) * 3) - l + 1), 0ll) * (x - 1) % mod;
		cout << ans % mod << endl;
	}
	return 0;
}
