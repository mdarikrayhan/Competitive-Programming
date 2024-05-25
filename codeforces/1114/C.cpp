// LUOGU_RID: 159608717
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

int n, b, p[105], cnt[105], tot, ans = 1e18;

signed main() {
	n = read(), b = read();
	for (int i = 2; i * i <= b; i++) {
		if (b % i == 0) {
			p[++tot] = i;
			while (b % i == 0) {
				b /= i;
				cnt[tot]++;
			}
		}
	}
	if (b > 1) {
		p[++tot] = b;
		cnt[tot] = 1;
	}
	rep(i, 1, tot) {
		int nn = n, cntt = 0;
		while (nn) cntt += nn / p[i], nn /= p[i];
		ans = min(ans, cntt / cnt[i]);
	}
	printf("%lld\n", ans);
	return 0;	
}