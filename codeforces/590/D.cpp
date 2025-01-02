#include <bits/stdc++.h>
using namespace std;
#define int long long
int dp[2][155][23000];
int a[155];
signed main() {
	int n, k, s;
	cin >> n >> k >> s;
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	memset(dp, 0x3f3f3f3f, sizeof(dp));
	dp[0][0][0] = 0;
	int flag = 1;
	for (int i = 1; i <= n; i++) {
		memset(dp[flag][0], 0, sizeof(dp[flag][0]));
		for (int j = 1; j <= i; j++) {
			for (int l = 0; l <= i * j; l++) {
				dp[flag][j][l] = dp[!flag][j][l];
				if (l >= i - j) {
					dp[flag][j][l] = min(dp[flag][j][l], dp[!flag][j - 1][l - (i - j)] + a[i]);
				}
			}
		}flag = !flag;
	}
	int mi = 0x3f3f3f3f;
	for (int i = 0; i <= min(s, n * (n - 1) / 2); i++) {
		mi = min(mi, dp[n % 2][k][i]);
	}
	cout << mi;
	return 0;
}
