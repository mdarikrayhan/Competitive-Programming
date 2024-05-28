#include <bits/stdc++.h>
using namespace std;
int a[100005], b[100005];
vector <int> id[100005];
int dp[305];
signed main() {
	int n, m, s, e;
	cin >> n >> m >> s >> e;
	int C = s / e;
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	for(int i = 0; i < m; i++) {
		scanf("%d", &b[i]);
		id[b[i]].push_back(i);
	}
	for(int j = 0; j <= s / e; j++) {
		dp[j] = m;
	}
	dp[0] = -1;
	int mx = 0;
	for(int i = 0; i <= n; i++) {
		for (int j = s / e; j >= 0; j--) {
			if (dp[j] < m) {
				if (i + dp[j] + 1 + j * e <= s) {
					mx = max(mx, j);
				}
				vector <int> :: iterator it = upper_bound(id[a[i]].begin(), id[a[i]].end(), dp[j]);
				if (it != id[a[i]].end()) {
					dp[j + 1] = min(dp[j + 1], *it);
				}
			}
		}
	}
	cout << mx;
	return 0;
}
