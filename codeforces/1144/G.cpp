// LUOGU_RID: 160045091
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define all(tar) tar.begin(),tar.end()
#define pii pair<int,int>
#define AC return 0;
int n, m, t;
const int maxx = 1e6 + 5;
const int mod = 1e9 + 7;
int a[maxx];
int dp[maxx][2];
pii pre[maxx][2];
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)cin >> a[i];
	for (int i = 1; i <= n; i++) {
		dp[i][1] = 1e18;
		dp[i][0] = -1e18;
	}
	//0递增序列 1递减序列
	dp[1][0] = 1e18;
	dp[1][1] = -1e18;
	for (int i = 2; i <= n; i++) {
		if (a[i] > a[i - 1]) {
			dp[i][0] = dp[i - 1][0];
			pre[i][0] = {i - 1, 0};
		}
		if (a[i] < a[i - 1]) {
			dp[i][1] = dp[i - 1][1];
			pre[i][1] = {i - 1, 1};
		}
		if (a[i] > dp[i - 1][1] && dp[i][0] < a[i - 1]) {
			dp[i][0] = a[i - 1];
			pre[i][0] = {i - 1, 1};
		}
		if (a[i] < dp[i - 1][0] && dp[i][1] > a[i - 1]) {
			dp[i][1] = a[i - 1];
			pre[i][1] = {i - 1, 0};
		}
//		cout << dp[i][0] << " " << dp[i][1] << '\n';
	}
	vector<int>ans(n + 1);
	if (dp[n][1] != 1e18) {
		int now = 1;
		for (int i = n; i >= 1; i--) {
//			cout << now;
			ans[i] = now;
			now = pre[i][now].second;
		}
		cout << "YES\n";
		for (int i = 1; i <= n; i++)cout << ans[i] << " ";
		AC
	}
	if (dp[n][0] != -1e18) {
		int now = 0;
		for (int i = n; i >= 1; i--) {
			//			cout << now;
			ans[i] = now;
			now = pre[i][now].second;
		}
		cout << "YES\n";
		for (int i = 1; i <= n; i++)cout << ans[i] << " ";
		AC
	}
	cout << "NO\n";
	AC
}