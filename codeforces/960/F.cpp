#include <bits/stdc++.h>
#define x first
#define y second
#define eps 1e-8
#define endl '\n'
#define int long long
#define INF 0x3f3f3f3f3f3f3f3f
#define IOS ios::sync_with_stdio(false);cin.tie(NULL);

using namespace std;
using PII = pair<int, int>;

const int N = 1e5 + 5, M = N * 20;
int lc[M], rc[M], maxv[M], rt[N], idx;
int n, m, k;

void insert(int &p, int l, int r, int pos, int val) {
	if (!p)
		p = ++idx;
	maxv[p] = max(maxv[p], val);
	if (l == r)
		return;
	int mid = l + r >> 1;
	if (pos <= mid)
		insert(lc[p], l, mid, pos, val);
	else
		insert(rc[p], mid + 1, r, pos, val);
}

int query(int p, int l, int r, int L, int R) {
	if (!p)
		return 0;
	if (L <= l && r <= R)
		return maxv[p];
	int mid = l + r >> 1, res = 0;
	if (L <= mid)
		res = max(res, query(lc[p], l, mid, L, R));
	if (R > mid)
		res = max(res, query(rc[p], mid + 1, r, L, R));
	return res;
}

void solve() {
	cin >> n >> m;
	int ans = 0;
	while (m--) {
		int a, b, c;
		cin >> a >> b >> c;
		int res = query(rt[a], 0, 1e5, 0, c - 1);
		ans = max(ans, res + 1);
		insert(rt[b], 0, 1e5, c, res + 1);
	}
	cout << ans;
}

signed main(void) {
	IOS;
	int t = 1;
	//cin >> t;
	while (t--)
		solve();
	return 0;
}

