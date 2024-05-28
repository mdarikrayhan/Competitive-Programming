#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#include <debug-template.hpp>
#define debug(...) cerr << "[ " << #__VA_ARGS__ << " ]: ", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int N, M; cin >> N >> M;
	vector<int> L(N+1); for (int i = 1; i <= N; i++) cin >> L[i];
	vector<int> S(N+1); for (int i = 1; i <= N; i++) cin >> S[i];
	vector<int> C(N+M+1); for (int i = 1; i <= N+M; i++) cin >> C[i];
	vector<vector<int>> dp(N+M+1, vector<int>(N+1, -1e9));
	for (int i = 1; i <= N+M; i++) dp[i][0] = 0;
	for (int i = N; i >= 1; i--) {
		for (int j = N-1; j >= 0; j--) dp[L[i]][j+1] = max(dp[L[i]][j+1], dp[L[i]][j] + C[L[i]] - S[i]);
		for (int j = L[i], k = N; j < N+M; j++, k /= 2) {
			for (int l = 0; l <= k; l++) dp[j+1][l/2] = max(dp[j+1][l/2], dp[j][l] + (l/2) * C[j+1]);
		}
	}
	cout << dp[N+M][0];
	
	return 0;
}
