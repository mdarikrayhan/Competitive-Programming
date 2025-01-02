// LUOGU_RID: 157776490
// Problem: C. Petya and Tree
// Contest: Codeforces - Yandex.Algorithm 2011: Round 1
// URL: https://codeforces.com/problemset/problem/85/C
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define rep1(i, l, r) for (int i = l; i <= int(r); ++i)
#define rep2(i, l, r) for (int i = l; i >= int(r); --i)
#define cop(i, l, r, a, b) rep1(i, l, r) a[i] = b[i]
#define rep(i, x) for (int i = pnt[x]; i; i = nxt[i])
#define rer(i, l, r, a) rep1(i, l, r) read(a[i])
#define ptc putchar
#define il inline
#define eb emplace_back
#define ef emplace_front
#define mp make_pair
#define fst first
#define snd second
#define sqr(x) ((x) * (x))
#define ls(x) x << 1
#define rs(x) x << 1 | 1
#define rout return 0
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
// typedef __int128 bll;
// typedef unsigned __int128 ubll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int MAXN = 2e5 + 10, inf = ~0U >> 2, INF = ~0U >> 1;
const int LOGN = log2(MAXN) + 1;
const int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
namespace stupid_lrc {
	template <typename T> il bool read(T &x) {
		x = 0; bool f = false; char ch;
		while (!isdigit(ch = getchar())) {
			f ^= !(ch ^ '-');
			if (ch == EOF) return false;
		}
		while (isdigit(ch)) x = (x << 1) + (x << 3) + (ch & 15), ch = getchar();
		if (f) x = ~x + 1; return true;
	}
	il int read() {int x; read(x); return x;}

	template <typename T> il bool read(pair <T, T> &x) {return read(x.fst) && read(x.snd);}
	
	template <typename T> il void gmin(T &x, T y) {x = x < y ? x : y;}
	
	template <typename T> il void gmax(T &x, T y) {x = x > y ? x : y;}

	template <typename T, typename ...L>
	il bool read(T &x, L &...y) {return read(x) && read(y...);}

	template <typename T> il T lowbit(const T &x) {return x & -x;}
}
using namespace stupid_lrc;
int n, k, lg[MAXN], lp[MAXN], rp[MAXN], pa[MAXN], val[MAXN], dep[MAXN];
ll s1[MAXN], s2[MAXN], p1[MAXN], p2[MAXN]; // s1: LRRRRR   s2: RLLLLL   p1: LLLLL  p2: RRRRR
int c1[MAXN], c2[MAXN], mii[MAXN], maa[MAXN];
int cp1[MAXN], cp2[MAXN];
long double ans[MAXN];
vector <pii> q, lfs;
int f[MAXN][20];

il void dfs(int x) {
	mii[x] = maa[x] = val[x];
	if (lp[x]) dep[lp[x]] = dep[x] + 1, dfs(lp[x]), gmin(mii[x], mii[lp[x]]), gmax(maa[x], maa[rp[x]]);
	if (rp[x]) dep[rp[x]] = dep[x] + 1, dfs(rp[x]), gmin(mii[x], mii[rp[x]]), gmax(maa[x], maa[rp[x]]);
	p1[x] = p1[lp[x]] + mii[rp[x]]; p2[x] = p2[rp[x]] + maa[lp[x]];
	cp1[x] = lp[x] ? cp1[lp[x]] + 1 : 0; cp2[x] = rp[x] ? cp2[rp[x]] + 1 : 0;
	s1[x] = p2[lp[x]] + mii[rp[x]]; s2[x] = p1[rp[x]] + maa[lp[x]];
	c1[x] = lp[x] ? cp2[lp[x]] + 1 : 0; c2[x] = rp[x] ? cp1[rp[x]] + 1 : 0;
}

il int lca(int u, int v) {
	if (dep[u] < dep[v]) swap(u, v);
	rep2(i, lg[n], 0) if (dep[u] - dep[v] >= 1 << i) u = f[u][i];
	if (u == v) return u;
	rep2(i, lg[n], 0) if (f[u][i] ^ f[v][i]) u = f[u][i], v = f[v][i];
	return f[u][0];
}

int main() {
	read(n); int rt;
	rep1(i, 1, n) read(pa[i], val[i]);
	rep1(i, 1, n) {
		f[i][0] = pa[i];
		if (!~pa[i]) rt = i;
		else val[i] < val[pa[i]] ? lp[pa[i]] = i : rp[pa[i]] = i;
	} f[rt][0] = 0;
	rep1(i, 2, n) lg[i] = lg[i >> 1] + 1;
	dfs(rt);
	rep1(j, 1, lg[n]) rep1(i, 1, n) f[i][j] = f[f[i][j - 1]][j - 1];
	read(k);
	rep1(i, 1, k) q.eb(read(), i);
	sort(begin(q), end(q)); ll sum = 0; int cnt = 0, now;
	rep1(i, 1, n) if (!lp[i] && !rp[i]) lfs.eb(val[i], i);
	sort(begin(lfs), end(lfs)); now = lfs[0].fst - 1; sum = p1[rt]; cnt = cp1[rt];
	const int mxv = lfs.back().fst; int id = 0;
	for (auto t : q) {
		int v = t.fst, w = id < lfs.size() - 1 ? lca(lfs[id].snd, lfs[id + 1].snd) : inf;
		while (id != lfs.size() - 1 && v > val[w]) {
			sum -= s1[w]; sum += s2[w];
			cnt -= c1[w]; cnt += c2[w];
			++id; w = id < lfs.size() - 1 ? lca(lfs[id].snd, lfs[id + 1].snd) : inf;
		} ans[t.snd] = (long double)sum / cnt;
	}
	rep1(i, 1, k) printf("%.10Lf\n", ans[i]);
	rout;
}
