#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, k, mx;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
	cin >> n >> k;
	if (k >= 1e6) {
	    cout << "-1";
	    return 0;
	}
	int x = k * (k + 1) / 2;
	for (int i = 1; i * i <= n; i++) {
		if (n % i == 0) {
			if (n / i >= x) {
				mx = max(mx, i);
			}
			if (n != i * i) {
				if (i >= x) {
					mx = max(mx, n / i);
				}
			}
		}
	}
	if (mx == 0) {
		cout << "-1";
		return 0;
	}
	for (int i = 1; i < k; i++) {
		cout << mx * i << " ";
	}
	cout << mx * (n / mx - k * (k - 1) / 2);
}