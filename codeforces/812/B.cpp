#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1e3 + 1;

int n, m, dp[MAXN][2], a[MAXN][2];
string s[MAXN];

int main() {
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> s[i];
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 0; j < m + 2; j++) {
			if(s[i][j] == '1') {
				a[i][0] = max(a[i][0], m + 1 - j), a[i][1] = max(a[i][1], j);
			}
		}
	}
	dp[n][1] = m + 1;
	for(int i = n - 1; i >= 1; i--) {
		for(int j = 0; j <= 1; j++) {
			dp[i][j] = min(dp[i + 1][!j] + m + 2, dp[i + 1][j] + a[i + 1][!j] * 2 + 1);
		}
	}
	int i;
	for(i = 1; i < n && a[i][0] == 0; i++) {
	}
	cout << min(dp[i][0] + a[i][1], dp[i][1] + a[i][0]);
	return 0;
} 
	 			  	 		     	 									 	