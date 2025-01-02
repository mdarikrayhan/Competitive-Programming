// LUOGU_RID: 160223549
#include <bits/stdc++.h>
#define int long long
#define fs first
#define sc second
#define ls (u << 1)
#define rs (u << 1 | 1)
#define mid ((l + r) >> 1)
#define lc ls, l, mid
#define rc rs, mid + 1, r
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, r, l) for (int i = (r); i >= (l); --i)
#define gc getchar
#define pc putchar

using namespace std;
using pii = pair<int, int>;
using vi = vector<int>;

const int maxn = 1e6 + 10;
const int maxd = 21;
const bool multidata = 0;

int read() {
	int x = 0, f = 1; char c = gc();
	while (c < '0' || c > '9') { if (c == '-') f = -f; c = gc(); }
	while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = gc();
	return x * f;
}

void write(int x) {
	if (x < 0) pc('-'), x = -x;
	if (x < 10) return void (pc(x + '0'));
	write(x / 10), pc(x % 10 + '0');
}

int n, k;
vector<int> tr[maxn];
int dfn[maxn], f[maxn], dep[maxn], idx, st[maxd][maxn];
int lg[maxn];
set<pii> s; int sum = 0;

void dfs(int u, int fa) {
	dfn[u] = ++idx;
	dep[u] = dep[fa] + 1;
	f[u] = fa;
	st[0][dfn[u]] = u;
	for (int v : tr[u]) if (v != fa) dfs(v, u);
}

int lca(int u, int v) {
	if (u == v) return u;
	if (dfn[u] > dfn[v]) swap(u, v);
	int d = lg[dfn[v] - dfn[u]];
	int x = st[d][dfn[u] + 1], y = st[d][dfn[v] - (1 << d) + 1];
	return f[dep[x] < dep[y] ? x : y];
}

int dis(int u, int v) {
	return dep[u] + dep[v] - dep[lca(u, v)] * 2;
}

void add(int u) {
	pii cur = {dfn[u], u};
	s.insert(cur);
	if (s.size() == 1) return;
	pii lst = (*s.begin() == cur ? *prev(s.end()) : *prev(s.find(cur)));
	pii nxt = (*prev(s.end()) == cur ? *s.begin() : *next(s.find(cur)));
	sum -= dis(lst.sc, nxt.sc);
	sum += dis(u, lst.sc) + dis(u, nxt.sc);
}

void del(int u) {
	pii cur = {dfn[u], u};
	if (s.size() != 1) {
		pii lst = (*s.begin() == cur ? *prev(s.end()) : *prev(s.find(cur)));
		pii nxt = (*prev(s.end()) == cur ? *s.begin() : *next(s.find(cur)));
		sum += dis(lst.sc, nxt.sc);
		sum -= dis(u, lst.sc) + dis(u, nxt.sc);
	} 
	s.erase(cur);
}

void fake_main() {
	n = read(), k = read();
	rep(i, 1, n - 1) {
		int u = read(), v = read();
		tr[u].push_back(v);
		tr[v].push_back(u);
	}
	lg[0] = -1, lg[1] = 0;
	for (int i = 2; i < maxn; i++) lg[i] = lg[i >> 1] + 1;
	dep[0] = -1, dfs(1, 0);
	for (int j = 1; j < maxd; j++) {
		for (int i = 1; i + (1 << j) - 1 <= n; i++) {
			int x = st[j - 1][i], y = st[j - 1][i + (1 << j - 1)];
			st[j][i] = dep[x] < dep[y] ? x : y;
		}
	}
	int r = 0, ans = 0;
	rep(l, 1, n) {
		while (r < n && sum / 2 + 1 <= k) add(++r);
		ans = max(ans, r - l + (sum / 2 + 1 <= k)); 
		del(l);
	}
	write(ans), pc('\n');
}

signed main() {
	int T = multidata ? read() : 1;
	while (T--) fake_main();
	return 0;
}