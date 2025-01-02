#include <bits/stdc++.h>
#define int long long

using namespace std;

const int kMaxN = 2e5 + 10, kMaxM = 20, kInf = 1e18;

int s1[kMaxN], s2[kMaxN], s3[kMaxN], dp[kMaxN][kMaxM], n, sum1, sum2, sum3, ans;

signed main() {
	cin >> n;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= 9; j++) {
			dp[i][j] = -kInf;
		}
	}
	dp[0][0] = 0;
	for (int i = 1, k; i <= n; i++) {
		sum1 = sum2 = sum3 = 0;
		cin >> k;
		for (int j = 1, c, d; j <= k; j++) {
			cin >> c >> d;
			if (c == 1) {
				s1[++sum1] = d;
			} else if (c == 2) {
				s2[++sum2] = d;
			} else {
				s3[++sum3] = d;
			}
		}
		sort(s1 + 1, s1 + 1 + sum1, greater<int>());
		sort(s2 + 1, s2 + 1 + sum2, greater<int>());
		sort(s3 + 1, s3 + 1 + sum3, greater<int>());
		for (int j = 0; j <= 9; j++) {
			dp[i][j] = dp[i - 1][j];
		}
		if (sum3) {
			for (int j = 0; j <= 9; j++) {
				if (j == 9) {
					dp[i][0] = max(dp[i][0], dp[i - 1][9] + 2 * s3[1]);
				} else {
					dp[i][j + 1] = max(dp[i][j + 1], dp[i - 1][j] + s3[1]);
				}
			}
		}
		if (sum2) {
			for (int j = 0; j <= 9; j++) {
				if (j == 9) {
					dp[i][0] = max(dp[i][0], dp[i - 1][9] + 2 * s2[1]);
				} else {
					dp[i][j + 1] = max(dp[i][j + 1], dp[i - 1][j] + s2[1]);
				}
			}
		}
		if (sum1) {
			for (int j = 0; j <= 9; j++) {
				if (j == 9) {
					dp[i][0] = max(dp[i][0], dp[i - 1][9] + 2 * s1[1]);
				} else {
					dp[i][j + 1] = max(dp[i][j + 1], dp[i - 1][j] + s1[1]);
				}
			}
		}
		if (sum2 && sum1) {
			for (int j = 0; j <= 9; j++) {
				if (j == 9) {
					dp[i][1] = max(dp[i][1], dp[i - 1][9] + 2 * max(s2[1], s1[1]) + min(s2[1], s1[1]));
				} else if (j == 8) {
					dp[i][0] = max(dp[i][0], dp[i - 1][8] + 2 * max(s2[1], s1[1]) + min(s2[1], s1[1]));
				} else {
					dp[i][j + 2] = max(dp[i][j + 2], dp[i - 1][j] + s2[1] + s1[1]);
				}
			}
		}
		if (sum1 > 1) {
			for (int j = 0; j <= 9; j++) {
				if (j == 9) {
					dp[i][1] = max(dp[i][1], dp[i - 1][9] + 2 * s1[1] + s1[2]);
				} else if (j == 8) {
					dp[i][0] = max(dp[i][0], dp[i - 1][8] + 2 * s1[1] + s1[2]);
				} else {
					dp[i][j + 2] = max(dp[i][j + 2], dp[i - 1][j] + s1[1] + s1[2]);
				}
			}
		}
		if (sum1 > 2) {
			for (int j = 0; j <= 9; j++) {
				if (j == 9) {
					dp[i][2] = max(dp[i][2], dp[i - 1][9] + 2 * s1[1] + s1[2] + s1[3]);
				} else if (j == 8) {
					dp[i][1] = max(dp[i][1], dp[i - 1][8] + 2 * s1[1] + s1[2] + s1[3]);
				} else if (j == 7) {
					dp[i][0] = max(dp[i][0], dp[i - 1][7] + 2 * s1[1] + s1[2] + s1[3]);
				} else {
					dp[i][j + 3] = max(dp[i][j + 3], dp[i - 1][j] + s1[1] + s1[2] + s1[3]);
				}
			}
		}
	}
	for (int i = 0; i <= 9; i++) {
		ans = max(ans, dp[n][i]);
	}
	cout << ans << '\n';
	return 0;
}
		  			 		  	 							 	 			   	