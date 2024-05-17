// LUOGU_RID: 159214814
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 110;
const int MAXM = 1e5 + 10;
int n;
int s;
int a[MAXN];
int p[MAXN];
int dp[MAXN][MAXM];
void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		s += a[i];
		
		int t = a[i];
		while (t % 2 == 0) {
			p[i]++;
			t /= 2;
		}
	}	
	if (s % 2) {
		cout << 0 << endl;
		return;
	}
	s/=2;
	for (int i = 1; i <= n; i++) {
		dp[i][0] = 1;
		for (int j = 1; j <= s; j++) {
			dp[i][j] = dp[i-1][j];
			if (j >= a[i]) {
				dp[i][j] = max(dp[i][j], dp[i-1][j-a[i]]);
			}
		}
	}
	if (dp[n][s] == 0) {
		cout << 0 << endl;
		return;
	}
	int minn = 1e9;
	for (int i = 1; i <= n; i++) {
		minn = min(minn, p[i]);
	}
	cout << 1 << endl;
	for (int i = 1; i <= n; i++) {
		if (p[i] == minn) {
			cout << i << endl;
			break;
		}
	}
}
int main() {
	int T = 1;
	while(T--) {
		solve();
	}	
	return 0;
}