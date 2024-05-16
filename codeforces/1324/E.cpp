#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 1e9;
void solve() {
	int n, h, l, r;
	cin >> n >> h >> l >> r;
	vector<int> dp(h, -inf), a(n + 1);
	dp[0] = 0;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++) {
		vector<int> tmp(h, -inf);
		for(int j = 0; j < h; j++) {
			int t1 = (j + a[i]) % h, t2 = (j + a[i] - 1 + h) % h;
			if(t1 >= l && t1 <= r) {
				tmp[t1] = max(dp[j] + 1, tmp[t1]); 
			} else {
				tmp[t1] = max(dp[j], tmp[t1]);
			}
			if(t2 >= l && t2 <= r) {
				tmp[t2] = max(dp[j] + 1, tmp[t2]); 
			} else {
				tmp[t2] = max(dp[j], tmp[t2]);
			}
		}
		dp = tmp;
	}
	int ans = 0;
	for(int i = 0; i < h; i++) {
		ans = max(ans, dp[i]);
	}
	cout << ans;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
	return 0;
}