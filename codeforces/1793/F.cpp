// LUOGU_RID: 160501766
#include<bits/stdc++.h>
#define ll long long
#define rep(i, x, y) for(int i = x; i <= y; ++i)
#define drep(i, x, y) for(int i = x; i >= y; --i)
#define pb push_back
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define fi first
#define se second
using namespace std;
const int N = 300030, inf = 1e9 + 1;
int n, m, rt, tot, a[N], ans[N * 4];
vector<pair<int, int> > q[N];
struct SegTree {
	int ls[N * 32], rs[N * 32], mx[N * 32];
	inline void clear() {
		rt = tot = 0;
		memset(ls, 0, sizeof ls);
		memset(rs, 0, sizeof rs);
		memset(mx, 0, sizeof mx);
	}
	void upd(int &p, int x, int y, int l = 0, int r = inf) {
		if(!p) p = ++tot;
		mx[p] = max(mx[p], y);
		if(l == r) return;
		int mid = (l + r) >> 1;
		if(x <= mid) upd(ls[p], x, y, l, mid);
		else upd(rs[p], x, y, mid + 1, r);
	}
	int qry(int p, int ql, int qr, int l = 0, int r = inf) {
		if(!p || qr < l || r < ql) return 0;
		if(ql <= l && r <= qr) return mx[p];
		int mid = (l + r) >> 1;
		return max(qry(ls[p], ql, qr, l, mid), qry(rs[p], ql, qr, mid + 1, r));
	}
} T;
struct BIT {
	int t[N];
	inline void clear() {
		memset(t, 0x3f, sizeof t);
	}
	inline void upd(int x, int y) {
		for(int i = x; i; i -= (i & -i))
			t[i] = min(t[i], y);
	}
	inline int qry(int x) {
		int res = inf;
		for(int i = x; i < N; i += (i & -i)) res = min(res, t[i]);
		return res;
	}
} B;
//ai - ak < ai - aj & ak - aj < ai - ak
// aj <= ak < (ai + aj) / 2
inline void solve() {
	T.clear(), B.clear();
	rep(i, 1, n) {
		int x = T.qry(rt, a[i], inf);
		while(x) {
			//cout << x << " " << i << "\n";
			B.upd(x, a[x] - a[i]);
			x = T.qry(rt, a[i], min(a[x] - 1, (a[x] + a[i]) / 2));
		}
		T.upd(rt, a[i], i);
		for(pair<int, int> u : q[i])
			ans[u.se] = min(ans[u.se], B.qry(u.fi));
	}
} 
int main() {
	IOS;
	cin >> n >> m;
	rep(i, 1, n) cin >> a[i];
	rep(i, 1, m) {
		int x, y; cin >> x >> y;
		q[y].pb({x, i}); ans[i] = 1e9;
	}
	solve();
	rep(i, 1, n) a[i] = inf - a[i];
	solve();
	rep(i, 1, m) cout << ans[i] << '\n';
	return 0;
}