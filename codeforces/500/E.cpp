#include <bits/stdc++.h>
using namespace std;
int p[200005], l[200005];
int dp[200005][20];
int sum[200005][20];
int mx[200005];
signed main() {
	int n;
	cin >> n; 
	for (int i = 1; i <= n; i++) {
		scanf("%d%d", &p[i], &l[i]);
	}
	dp[n][0] = 0;
	int lg = log2(n);
	for (int i = n - 1; i >= 1; i--) {
		int cur = i + 1;
		mx[i] = max(mx[i], p[i] + l[i]);
		while (cur && p[cur] <= p[i] + l[i]) {
			mx[i] = max(mx[i], mx[cur]);
			cur = dp[cur][0];
		}
		dp[i][0] = cur;
		sum[i][0] = p[cur] - mx[i];
	}
	for (int i = 1; i <= lg; i++) {
		for (int x = 1;  x <= n; x++) {
			sum[x][i] = sum[x][i - 1] + sum[dp[x][i - 1]][i - 1];
			dp[x][i] = dp[dp[x][i - 1]][i - 1];
		}
	}
	int m;
	cin >> m;
	while (m--) {
		int l, r;
		scanf("%d%d", &l, &r);
		if (dp[l][0] > r) {
			printf("0\n");
		}
		else {
			int ans = 0;
			for (int i = lg; i >= 0; i--) {
				if (dp[l][i] && dp[l][i] <= r) {
					ans += sum[l][i];
					l = dp[l][i];
				}
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}
