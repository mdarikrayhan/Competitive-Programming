#include<iostream>
#include<set>
#include<vector>
#include <algorithm>
#define int long long
#define fr first
#define sc second
#define vi vector<int>
#define pb push_back
using namespace std; const int N = 2e5 + 7, mod = 998244353, inf = 1e18 + 7; typedef pair<vi, int> pa;
int n, m, i, j, dfn[N], pw[N], rdfn[N], mn[22][N], dep[N], cnt, Log[N], h[N]; vi g[N]; set<pa>s;
int calc(int x, int y) { return dep[x] < dep[y] ? x : y; }
int calc1(int x, int y) { return dep[x] > dep[y] ? x : y; }
void dfs(int x, int fa) {
	rdfn[dfn[x] = ++cnt] = x; mn[0][cnt] = fa; dep[x] = dep[fa] + 1;
	for (auto& y : g[x])dfs(y, x);
}
int lca(int x, int y) {
	if (x == y)return x; x = dfn[x]; y = dfn[y]; if (x > y)swap(x, y);
	int t = Log[y - x++]; return calc(mn[t][x], mn[t][y - pw[t] + 1]);
}
int get(auto it) {
	auto nxt = it, pre = it; int q = 0;
	if ((nxt = next(it))->fr == it->fr)q = calc1(q, lca(rdfn[it->sc], rdfn[nxt->sc]));
	if ((pre = prev(it))->fr == it->fr)q = calc1(q, lca(rdfn[it->sc], rdfn[pre->sc]));
	return q;
}
void ins(int p) {
	if (!h[p])return; vi num;
	for (int i = 30; i >= 0; --i)if ((h[p] - 1) >> i & 1)num.pb(dep[p] + i);
	auto it = s.insert(pa(num, dfn[p])).fr; while (it != s.end()) {
		int q = get(it); if (q == 0)break;
		num.pb(dep[q]); it = s.insert(pa(num, dfn[q])).fr;
	}
}
void era(int p) {
	if (!h[p])return; vi num;
	for (int i = 30; i >= 0; --i)if ((h[p] - 1) >> i & 1)num.pb(dep[p] + i);
	auto it = s.find(pa(num, dfn[p])); while (it != s.end()) {
		int q = get(it); s.erase(it); if (q == 0)break;
		num.pb(dep[q]); it = s.find(pa(num, dfn[q]));
	}
}
int cal() {
	if (s.size() == 2)return 0; int v = 1;
	for (auto i : (----s.end())->fr)(v += pw[i]) %= mod; return v;
}
signed main() {
	scanf("%lld", &n); dep[n + 1] = inf; dep[0] = -1; s.insert(pa(vi{ inf }, 0)); s.insert(pa(vi{ -1 }, 0));
	for (i = 2; i <= n; ++i)scanf("%lld", &j), g[j].pb(i);
	for (pw[0] = 1, i = 1; i < N; ++i)pw[i] = pw[i - 1] * 2 % mod;
	for (Log[0] = -1, i = 1; i < N; ++i)Log[i] = Log[i >> 1] + 1;
	for (dfs(1, 0), i = 1; i <= 20; ++i)for (j = 1; j + pw[i] - 1 <= n; ++j)mn[i][j] = calc(mn[i - 1][j], mn[i - 1][j + pw[i - 1]]);
	for (i = 1; i <= n; ++i)scanf("%lld", &h[i]), ins(i);
	for (printf("%lld\n", cal()), scanf("%lld", &m); m--;)
		scanf("%lld%lld", &i, &j), era(i), h[i] = j, ins(i), printf("%lld\n", cal());
}
 	  			 	   	    	 	 			  		