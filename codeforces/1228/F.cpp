// LUOGU_RID: 159906154
// Problem: F. One Node is Gone
// Contest: Codeforces - Codeforces Round 589 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1228/F
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define pb emplace_back
#define fst first
#define scd second
#define mkp make_pair
#define mems(a, x) memset((a), (x), sizeof(a))

using namespace std;
typedef long long ll;
typedef double db;
typedef unsigned long long ull;
typedef long double ldb;
typedef pair<int, int> pii;

const int maxn = 133333;

int n, m, fa[maxn], mxd, U, a[maxn], tot;
bool fl;
vector<int> G[maxn], ans, T[maxn];

void dfs(int u, int f, int d) {
	if (d > mxd) {
		mxd = d;
		U = u;
	}
	for (int v : G[u]) {
		if (v == f) {
			continue;
		}
		fa[v] = u;
		dfs(v, u, d + 1);
	}
}

int dfs2(int u, int fa) {
	int mx = 0;
	for (int v : G[u]) {
		if (v == fa) {
			continue;
		}
		mx = max(mx, dfs2(v, u) + 1);
	}
	return mx;
}

void dfs(int u, int fa) {
	vector<int> son;
	for (int v : G[u]) {
		if (v == fa) {
			continue;
		}
		son.pb(v);
		if (U || !fl) {
			return;
		}
	}
	if ((int)son.size() == 1) {
		U = u;
		T[u].pb(m + 1);
		T[m + 1].pb(u);
		return;
	}
	if ((int)son.size() == 3) {
		U = u;
		vector<pii> vc;
		for (int v : son) {
			vc.pb(dfs2(v, u), v);
		}
		sort(vc.begin(), vc.end());
		int v0 = vc[0].scd, v1 = vc[1].scd;
		T[u].pb(m + 1);
		T[m + 1].pb(u);
		T[u].erase(find(T[u].begin(), T[u].end(), v0));
		T[u].erase(find(T[u].begin(), T[u].end(), v1));
		T[v0].erase(find(T[v0].begin(), T[v0].end(), u));
		T[v1].erase(find(T[v1].begin(), T[v1].end(), u));
		T[m + 1].pb(v0);
		T[m + 1].pb(v1);
		T[v0].pb(m + 1);
		T[v1].pb(m + 1);
		return;
	}
	if ((int)son.size() == 2) {
		dfs(son[0], u);
		dfs(son[1], u);
		return;
	}
	if (son.empty()) {
		return;
	}
	fl = 0;
}

int f[maxn];

void dfs3(int u, int fa, int d) {
	++f[d];
	int cnt = 0;
	for (int v : T[u]) {
		if (v == fa) {
			continue;
		}
		++cnt;
		dfs3(v, u, d + 1);
	}
	// printf("%d %d\n", u, cnt);
	fl &= (cnt == 2 || cnt == 0);
}

inline bool check(int rt) {
	mems(f, 0);
	fl = 1;
	dfs3(rt, -1, 0);
	if (!fl) {
		return 0;
	}
	// puts("here");
	for (int i = 0; i < n; ++i) {
		if (f[i] != (1 << i)) {
			return 0;
		}
	}
	return 1;
}

void solve() {
	scanf("%d", &n);
	m = (1 << n) - 2;
	for (int _ = 1, u, v; _ < m; ++_) {
		scanf("%d%d", &u, &v);
		G[u].pb(v);
		G[v].pb(u);
	}
	if (n == 2) {
		puts("2\n1 2");
		return;
	}
	mxd = -1;
	U = 0;
	dfs(1, -1, 0);
	int s = U;
	mxd = -1;
	U = 0;
	dfs(s, -1, 0);
	int t = U;
	for (int i = t; i != s; i = fa[i]) {
		a[++tot] = i;
	}
	a[++tot] = s;
	for (int i = 1; i <= m + 1; ++i) {
		T[i] = G[i];
	}
	U = 0;
	fl = 1;
	dfs(a[(tot + 1) / 2], -1);
	if (check(a[(tot + 1) / 2]) && U && fl) {
		ans.pb(U);
	}
	if (tot % 2 == 0) {
		U = 0;
		fl = 1;
		for (int i = 1; i <= m + 1; ++i) {
			T[i] = G[i];
		}
		dfs(a[tot / 2 + 1], -1);
		if (check(a[tot / 2 + 1]) && U && fl) {
			ans.pb(U);
		}
	}
	sort(ans.begin(), ans.end());
	printf("%d\n", (int)ans.size());
	for (int i : ans) {
		printf("%d ", i);
	}
}

int main() {
	int T = 1;
	// scanf("%d", &T);
	while (T--) {
		solve();
	}
	return 0;
}
