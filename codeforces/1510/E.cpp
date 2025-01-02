#include <bits/stdc++.h>
using namespace std;

#define Fi first
#define Se second
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<(n);i++)
typedef tuple<int, int, int> t3;

const int INF = 1e9;
using FL = double;
int n;
FL cx, cy;
int D, DX, DY;

pll get_d(int x, int y, int dir) {
	int y1 = y;
	if(dir == -1) --y1;
	ll ds1 = 6 * y1 + 3;
	ll dx = (ll)(6 * x * y1 + 3 * (x + y1) + (dir == 1 ? 2 : 1)) * D - ds1 * DX;
	ll dy = (ll)(3 * y1 * y1 + 3 * y1 + 1) * D - ds1 * DY;
	return {dx, dy};
}

string ans;
pll Range[55][55][2];

bool same(FL x, FL y) { return abs(x - y) <= 1e-8; }
int dfs(int x, int y, ll sx, ll sy) {
	if(!(sx + Range[x][y][0].Fi <= 0 && 0 <= sx + Range[x][y][0].Se)) return 0;
	if(!(sy + Range[x][y][1].Fi <= 0 && 0 <= sy + Range[x][y][1].Se)) return 0;
	if(x == n) {
		if(sx == 0 && sy == 0) {
			printf("%s\n", ans.c_str());
			return 1;
		}
		return 0;
	}
	if(x + y + 2 <= n) {
		auto [dx, dy] = get_d(x, y, 1);
		ans.pb('(');
		if(dfs(x + 1, y + 1, sx + dx, sy + dy)) return 1;
		ans.pop_back();
	}

	if(y > 0) {
		auto [dx, dy] = get_d(x, y, -1);
		ans.pb(')');
		if(dfs(x + 1, y - 1, sx + dx, sy + dy)) return 1;
		ans.pop_back();
	}
	return 0;
}

int main() {
	cin >> n >> cx >> cy;
	for(int i=1;;i++) {
		FL vx = round(cx * i), vy = round(cy * i);
		if(same(cx, vx / i) && same(cy, vy / i)) {
			D = i;
			DX = vx, DY = vy;
			break;
		}
	}
	auto update = [&](pll &a, pll &b, ll c) {
		a.Fi = min(a.Fi, b.Fi + c);
		a.Se = max(a.Se, b.Se + c);
	};
	for(int i=n-1;i>=0;i--) {
		for(int j=0;j<=i;j++) {
			if((i+j) & 1) continue;
			if(i + j > n) continue;

			rep(k, 2) Range[i][j][k] = {INF, -INF};
			if(i + j + 2 <= n) {
				auto [v1, v2] = get_d(i, j, 1);
				update(Range[i][j][0], Range[i+1][j+1][0], v1);
				update(Range[i][j][1], Range[i+1][j+1][1], v2);
			}
			if(j > 0) {
				auto [v1, v2] = get_d(i, j, -1);
				update(Range[i][j][0], Range[i+1][j-1][0], v1);
				update(Range[i][j][1], Range[i+1][j-1][1], v2);
			}
		}
	}
	assert(dfs(0, 0, 0, 0));
	return 0;
}
