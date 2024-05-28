#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, i, j, k, ans;
char a[2024][2024], b[2024], c[2024];

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	#endif
	cin >> n;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) cin >> a[i][j], b[i] = c[i] = '0';
	}
	for (int d = n - 1; d >= 1; d--) {
		for (i = 1; i <= n; i++) {
			j = i + d;
			if (j < 1 || j > n) continue;
			if (a[i][j] ^ b[i] ^ c[j] == '1') {
				b[i] ^= 1;
				c[j] ^= 1;
				a[i][i] ^= 1;
				a[j][j] ^= 1;
				a[i][j] = '0';
				ans++;
			}
		}
	}
	for (i = 1; i <= n; i++) b[i] = c[i] = '0';
	for (int d = n - 1; d >= 1; d--) {
		for (j = 1; j <= n; j++) {
			i = j + d;
			if (i < 1 || i > n) continue;
			if (a[i][j] ^ b[i] ^ c[j] == '1') {
				b[i] ^= 1;
				c[j] ^= 1;
				a[i][i] ^= 1;
				a[j][j] ^= 1;
				a[i][j] = '0';
				ans++;
			}
		}
	}
	for (i = 1; i <= n; i++) ans += (a[i][i] == '1');
	//for (i = 1; i <= n; i++) {
		//for (j = 1; j <= n; j++) {
			//cout << a[i][j];
		//}
		//cout << "\n";
	//}
	cout << ans;
}