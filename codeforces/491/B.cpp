// LUOGU_RID: 158665368
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1e9 + 7;
const int N = 200005;
const ll INF = 1e18;
int main() {
	int n, m;
	ll x, y;
	scanf("%lld%lld", &x, &y);
	scanf("%d", &n);
	ll minx = INF, maxx = -INF, miny = INF, maxy = -INF;
	for (int i = 1; i <= n; i++) {
		scanf("%lld%lld", &x, &y);
		minx = min(minx, x + y), maxx = max(maxx, x + y);
		miny = min(miny, x - y), maxy = max(maxy, x - y);
	}
	scanf("%d", &m);
	ll ans = INF, u = 0;
	for (int i = 1; i <= m; i++) {
		scanf("%lld%lld", &x, &y);
		ll xx = x, yy = y;
		x = xx + yy, y = xx - yy;
		ll s = max(max(abs(x - minx), abs(x - maxx)), max(abs(y - miny), abs(y - maxy)));
		if (s < ans) {
			ans = s;
			u = i;
		}
	}
	printf("%lld\n%lld\n", ans, u);
	return 0;
}
