#include <bits/stdc++.h>
using namespace std;
 
int n, k, d, a[500005], pf[500005];
bool can;
 
main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k >> d;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + 1 + n);
	pf[0] = 1;
	for (int i = 1, l = 1; i <= n; i++) {
		while (a[i] - a[l] > d) l++;
		if (i - k + 1 < l) {
			pf[i] = pf[i - 1];
			continue;
		}
		bool c = !!(pf[i - k] - (l == 1 ? 0 : pf[l - 2]));
		if (i == n && c) {
			can = 1;
			break;
		}
		pf[i] = pf[i - 1] + c;
	}
	cout << (can ? "YES" : "NO") << '\n';
}