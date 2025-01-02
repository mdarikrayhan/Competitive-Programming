// LUOGU_RID: 160560722
// #pragma GCC target("avx")
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 200005, B = 1001;
int n, m, a[N], b[N], t, dfn[N], siz[N], tmp[N];
int len, tot, blk[N], L[B], R[B], d[B];
vector<int> ch[N];
void dfs(int x) {
	dfn[x] = ++t, siz[x] = 1;
	for (int v : ch[x]) {
		a[v] += a[x], b[v] += b[x];
		dfs(v), siz[x] += siz[v];
	}
}
struct line {
	int k, b;
	int val(int x) { return k * x + b; }
};
bool check(line a, line b, line c) {
	return (__int128_t) (b.b - c.b) * (b.k - a.k) <= (__int128_t) (a.b - b.b) * (c.k - b.k);
}
struct hull {
	vector<line> v;
	void insert(line x) {
		#define vs v.size()
		while (vs > 1 && check(v[vs - 2], v[vs - 1], x)) v.resize(vs - 1);
		v.push_back(x);
	}
	int query(int x) {
		if (v.empty()) return -1e18;
		int l = 0, r = v.size() - 1, mid;
		while (l < r) {
			mid = l + r >> 1;
			if (v[mid].val(x) <= v[mid + 1].val(x)) l = mid + 1;
			else r = mid;
		}
		return v[l].val(x);
	}
	void clear() { v.clear(); }
} c1[B], c2[B];
void build(int B) {
	c1[B].clear(), c2[B].clear();
	vector<line> tmp;
	for (int i = L[B]; i <= R[B]; i++) {
		a[i] += d[B];
		tmp.push_back({b[i], a[i] * b[i]});
	}
	sort(tmp.begin(), tmp.end(), [](line a, line b) { return a.k < b.k; });
	for (line x : tmp) c1[B].insert(x);
	for (line x : tmp) c2[B].insert({x.k, -x.b});
	d[B] = 0;
}
void update(int l, int r, int x) {
	const int Bl = blk[l], Br = blk[r];
	if (Bl == Br) {
		for (int i = l; i <= r; i++) a[i] += x;
		return build(Bl);
	}
	for (int i = l; i <= R[Bl]; i++) a[i] += x;
	for (int i = L[Br]; i <= r; i++) a[i] += x;
	for (int i = Bl + 1; i < Br; i++) d[i] += x;
	build(Bl), build(Br);
}
int query(int l, int r) {
	const int Bl = blk[l], Br = blk[r];
	int ans = -1e18;
	if (Bl == Br) {
		for (int i = l; i <= r; i++) ans = max(ans, abs(a[i] + d[Bl]) * b[i]);
		return ans;
	}
	for (int i = l; i <= R[Bl]; i++) ans = max(ans, abs(a[i] + d[Bl]) * b[i]);
	for (int i = L[Br]; i <= r; i++) ans = max(ans, abs(a[i] + d[Br]) * b[i]);
	for (int i = Bl + 1; i < Br; i++) {
		ans = max(ans, c1[i].query(d[i]));
		ans = max(ans, c2[i].query(-d[i]));
	}
	return ans;
}
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 2, f; i <= n; i++) {
		cin >> f;
		ch[f].emplace_back(i);
	}
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cin >> b[i];
	dfs(1);
	memcpy(tmp, a, sizeof(a));
	for (int i = 1; i <= n; i++) a[dfn[i]] = tmp[i];
	memcpy(tmp, b, sizeof(b));
	for (int i = 1; i <= n; i++) b[dfn[i]] = abs(tmp[i]);
	len = max(sqrt(n) * 0.8, 1.0);
	for (int i = 1; i <= n; i++) blk[i] = (i - 1) / len + 1;
	tot = blk[n];
	for (int i = 1; i <= tot; i++) L[i] = R[i - 1] + 1, R[i] = i * len;
	R[tot] = n;
	for (int i = 1; i <= tot; i++) build(i);
	int op, v, x;
	while (m--) {
		cin >> op >> v;
		if (op == 1) cin >> x, update(dfn[v], dfn[v] + siz[v] - 1, x);
		else cout << query(dfn[v], dfn[v] + siz[v] - 1) << '\n';
	}
}