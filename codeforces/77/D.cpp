#include <bits/stdc++.h>
#define pii pair<int, int>
#define fi first
#define se second
#define MP make_pair
#define ep emplace
#define eb emplace_back
#define int long long
#define rep(i, j, k) for (int i = j; i <= k; i++)
#define per(i, j, k) for (int i = j; i >= k; i--)
typedef double db;
typedef long double ldb;
typedef long long ll;
typedef __int128 lll;
typedef unsigned long long ull;
typedef unsigned int ui;
using namespace std;

int read() {
	int s = 0, f = 1;
	char c = getchar();
	while (c < '0' || c > '9') f ^= (c == '-'), c = getchar();
	while (c >= '0' && c <= '9') s = s * 10 + c - '0', c = getchar();
	return f ? s : -s;
}
const int mod = 1e9 + 7;
int n, m, a[255][255], dp[255], f[255], g[255];
char s[1005][1005];
bool chk(int j) {
	if (n & 1) return 0;
	bool res = 1;
	rep(i, 1, n) res &= (a[i][j] >> 1 & 1);
	return res;
}

signed main() {
	n = read(), m = read();
	rep(i, 1, (n << 2 | 1)) scanf("%s", s[i] + 1);
	rep(i, 1, n) rep(j, 1, m) {
		int cnt = 0;
		rep(x, 4 * i - 2, 4 * i) rep(y, 4 * j - 2, 4 * j) cnt += (s[x][y] == 'O');
		if (cnt == 2 || cnt == 3) a[i][j] = (s[4 * i][4 * j - 2] == 'O') + 1;
		else if (cnt == 6) a[i][j] = (s[4 * i - 1][4 * j] == 'O') + 1;
		else a[i][j] = 3;
	}
	dp[0] = 1;
	rep(j, 1, m) {
		dp[j] = dp[j - 1] * chk(j);
		if (j > 1) {
			g[0] = 1;
			rep(i, 1, n) {
				f[i] = g[i] = 0;
				if ((a[i][j] & 1) && (a[i][j - 1] & 1)) f[i] = f[i - 1] + g[i - 1];
				if ((a[i][j] >> 1 & 1) && (a[i][j - 1] >> 1 & 1) && (a[i - 1][j] >> 1 & 1) && (a[i - 1][j - 1] >> 1 & 1)) f[i] = (f[i] + f[i - 2]) % mod, g[i] = (g[i] + g[i - 2] % mod);
			}
			dp[j] = (dp[j] + f[n] * dp[j - 2]) % mod;
		}
	}
	printf("%lld\n", dp[m]);
    return 0;
}
 			   	 	 	     	   		  				