#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a, _##i = b; i <= _##i; ++i)
#define per(i, a, b) for (int i = a, _##i = b; i >= _##i; --i)
using namespace std;
typedef long long ll;
const int maxn = 3e5 + 5;
int d[maxn];
ll c[maxn];
int stk[maxn], top, tr[maxn][2], lg[maxn];
ll st[maxn][25], ts[maxn][25];
int main() {
	int n, a;
	scanf("%d%d", &n, &a);
	rep(i, 1, n) {
		scanf("%d%lld", d + i, c + i);
		c[i] += c[i - 1] - a;
	}
//	rep(i, 1, n) {
//		cout << c[i] << " ";
//	} 
//	puts("");
	per(i, n, 2) {
		d[i] = abs(d[i] - d[i - 1]);
	}
	rep(i, 2, n) {
		while (top && d[stk[top]] <= d[i]) {
			tr[i][0] = stk[top--];
		}
		if (top) tr[stk[top]][1] = i;
		stk[++top] = i;
	}
	auto init=[&]()->void{
		lg[0] = -1; 
		rep(i, 1, n) st[i][0] = ts[i][0] = c[i], lg[i] = lg[i / 2] + 1;	lg[0] = 0;
		rep(k, 1, lg[n]) {
			rep(l, 1, n - (1 << k) + 1) {
				st[l][k] = max(st[l][k - 1], st[l + (1 << (k - 1))][k - 1]);
				ts[l][k] = min(ts[l][k - 1], ts[l + (1 << (k - 1))][k - 1]);
			}
		} 
	};
	init();
	ll min_ = 1e18;
	rep(i, 1, n) {
		min_ = min(min_, c[i] - c[i - 1]);
	}
	auto askmax=[&](int l, int r) {
		ll ans = -1e18;
		if (l <= 0) l = 1, ans = 0; 
		int k = lg[r - l + 1];
		return max(ans, max(st[l][k], st[r - (1 << k) + 1][k]));
	};
	auto askmin=[&](int l, int r) {
		int k = lg[r - l + 1];
		return min(ts[l][k], ts[r - (1 << k) + 1][k]);
	};
	auto dfs=[&](auto &&self, int x, int l, int r) -> void {
//		cout << x << " " << l << " " << r << " --> " ;
//		printf("[%d , %d] = %lld -- [%d, %d] = %lld", l, x - 2, askmin(l, x - 2), x, r, askmax(x, r));
//		cout << endl;
		if (tr[x][0]) self(self, tr[x][0], l, x - 1);
		if (tr[x][1]) self(self, tr[x][1], x-1, r);
		min_ = min(min_, askmin(x, r) - askmax(l, x - 2) + 1ll * d[x] * d[x]);
	};
	if (n > 1)
		dfs(dfs, stk[1], 0, n);
	cout << max(0ll, -min_) << endl;
	return 0;
}