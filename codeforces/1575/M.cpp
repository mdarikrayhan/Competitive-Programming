#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll int, ll int>
#define ff first
#define ss second
#define pb push_back
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;
// debug template
#ifdef POTATO
#include "debug.h"
#define debug(...) cerr << "[" << #__VA_ARGS__ << "] = ["; _print(__VA_ARGS__)
#else
#define debug(...)
#endif
// convenient functions
inline void yes() { cout << "YES\n"; return; }
inline void no() { cout << "NO\n"; return; }
template <class T>
inline void out(T temp) { cout << temp << '\n'; return; }
// globals
const int mxN = 2010;
bool cmp(pii lhs, pii rhs, int x) {
	return (x * lhs.ff + lhs.ss <= x * rhs.ff + rhs.ss);
}
pii seg[4 * mxN];
bool seghv[4 * mxN];
int n, m;
void build(int l = 0, int r = n, int idx = 1) {
	if (l == r) {
		seg[idx] = {0, 0};
		seghv[idx] = false;
		return;
	}
	int mid = (l + r) >> 1;
	build(l, mid, (idx << 1));
	build(mid + 1, r, (idx << 1) | 1);
	seg[idx] = {0, 0}; seghv[idx] = false;
}
void update(pii val, int l = 0, int r = n, int idx = 1) {
	if (!seghv[idx]) {
		seg[idx] = val;
		seghv[idx] = true;
		return;
	}
	if (val < seg[idx]) swap(val, seg[idx]);
	int mid = (l + r) >> 1;
	if (cmp(val, seg[idx], mid)) {
		if (cmp(val, seg[idx], r)) {
			seg[idx] = val; return;
		}
		if (l != r) update(seg[idx], mid + 1, r, (idx << 1) | 1);
		seg[idx] = val;
	} else {
		if (!cmp(val, seg[idx], l)) return;
		if (l != r) update(val, l, mid, (idx << 1));
	}
}
int query(int pos, int l = 0, int r = n, int idx = 1) {
	// debug(idx, seg[idx]);
	int res = (!seghv[idx] ? 1e9 : pos * seg[idx].ff + seg[idx].ss);
	if (l == r) return res;
	int mid = (l + r) >> 1;
	if (pos <= mid) res = min(res, query(pos, l, mid, (idx << 1)));
	else res = min(res, query(pos, mid + 1, r, (idx << 1) | 1));
	return res;
}
void init() {
	// initialize
	
}
void solve() {
	// solve
	cin >> n >> m;
	bool a[n + 1][m + 1];
	pii ways[n + 1][m + 1];
	for (int i = 0; i <= n; i++) {
		string str; cin >> str;
		for (int j = 0; j <= m; j++) {
			a[i][j] = (str[j] == '1');
		}
		int prev = -1;
		for (int j = 0; j <= m; j++) {
			if (a[i][j]) prev = j;
			ways[i][j].ff = prev;
		}
		prev = -1;
		for (int j = m; j >= 0; j--) {
			if (a[i][j]) prev = j;
			ways[i][j].ss = prev;
		}
	}

	auto calc = [&](int x1, int y1, int x2) -> pii {
		pii res;
		res.ff = -2 * y1;
		res.ss = (x1 - x2) * (x1 - x2) + y1 * y1;
		// debug(x1, y1, x2, res);
		return res;
	};
	ll ans = 0;
	for (int i = 0; i <= m; i++) {
		build();
		for (int j = 0; j <= n; j++) {
			if (ways[j][i].ff != -1) {
				// debug(i, j, ways[j][i].ff);
				update(calc(ways[j][i].ff, j, i));
			}
			if (ways[j][i].ss != -1) {
				// debug(i, j, ways[j][i].ss);
				update(calc(ways[j][i].ss, j, i));
			}
		}
		for (int j = 0; j <= n; j++) {
			int cur = query(j) + j * j;
			ans += cur;
			// debug(i, j, cur);
		}
		// debug(i, ans);
	}
	out(ans);
}
int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	srand(time(NULL));
	#ifdef POTATO
		auto start = chrono::high_resolution_clock::now();
	#endif

	init();
	int t = 1;
	// cin >> t;
	while (t--) solve();

	#ifdef POTATO
		auto end = chrono::high_resolution_clock::now();
		cerr << "Execution time: "
			<< chrono::duration_cast<chrono::milliseconds>(end - start).count()
			<< " ms" << endl;
	#endif
}
/*

*/