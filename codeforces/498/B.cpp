// LUOGU_RID: 158765627
#include <bits/stdc++.h>
using namespace std;
const int N = 5e3 + 5;
int n, T, a[N];
double dp[N][N], ans, p[N][3];
double qkpow(double a, int b) {
	if(!b) return 1;
	if(b & 1) return a * qkpow(a, b - 1);
	double t = qkpow(a,b >> 1); return t * t;
}
signed main() {
	cin >> n >> T;
	for(int i = 1;i <= n; ++i) {
		cin >> p[i][1] >> a[i]; p[i][0] = p[i][2] = 1; 
		p[i][1] = 1 - p[i][1] / 100.0; // 表示 1 - p[i] 
		p[i][2] = qkpow(p[i][1], a[i]);
	}
	dp[0][0] = 1.0;
	for(int i = 1;i <= n; ++i) {
		double sum = 0;
		for(int j = i;j <= T; ++j) {
			sum = sum * p[i][1] + dp[i - 1][j - 1];
			if(j > a[i]) sum -= dp[i - 1][j - a[i] - 1] * p[i][2];
			dp[i][j] = sum * (1 - p[i][1]);	
			if(j >= a[i]) dp[i][j] += dp[i - 1][j - a[i]] * p[i][2];
		}
	}
	for(int i = 1;i <= n; ++i) for(int j = 1;j <= T; ++j) ans += dp[i][j];
	printf("%.8lf", ans);
	return 0;
}
// 它是在特定时间听出特定歌曲的概率，类似于一个特定事件的概率。
// 期望应当是所有事件的概率乘上所有事件的贡献。

// 优化 dp 