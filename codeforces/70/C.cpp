/*
BuzzyBeez
21:19 UTC+7
06/04/2024 
*/
#include <bits/stdc++.h>
using namespace std;

const long long coef = 1e6;

vector<long long> tbc; // to be compressed

void compress() {sort(tbc.begin(), tbc.end()); tbc.resize(unique(tbc.begin(), tbc.end()) - tbc.begin());}
int get(long long x) {return lower_bound(tbc.begin(), tbc.end(), x) - tbc.begin() + 1;}

long long a[100008], b[100008];
int fa[200008], fb[200008];

int res;
int rev(int x) {
	res = 0;
	while (x) {
		res = res * 10 + x % 10;
		x /= 10;
	}
	return res;
}

int d;
long long frac_hash(int x, int y) {
	d = __gcd(x, y);
	return (x / d) * coef + (y / d);
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n, m, w; cin >> n >> m >> w;
	for (int i = 1; i <= n; ++i) a[i] = frac_hash(i, rev(i)), tbc.push_back(a[i]);
	for (int i = 1; i <= m; ++i) b[i] = frac_hash(rev(i), i), tbc.push_back(b[i]);
	compress();
	for (int i = 1; i <= n; ++i) a[i] = get(a[i]);
	for (int i = 1; i <= m; ++i) b[i] = get(b[i]), ++fb[b[i]];
	int pt1 = 1, pt2 = m; long long cur = 0;
	pair<int, int> ans = {n + 1, m + 1};
	for (pt1 = 1; pt1 <= n; ++pt1) {
		cur += fb[a[pt1]]; ++fa[a[pt1]];
		while (cur - fa[b[pt2]] >= w && pt2 > 1) cur -= fa[b[pt2]], --fb[b[pt2]], --pt2;
		if (cur < w) continue;
		// cout << pt1 << ' ' << pt2 << ' ' << cur << '\n';
		if (1LL * pt1 * pt2 < 1LL * ans.first * ans.second) ans = {pt1, pt2};
	}
	if (ans.first > n) cout << -1; 
	else cout << ans.first << ' ' << ans.second;
}