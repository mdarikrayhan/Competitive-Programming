#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define F first
#define S second
#define All(x) (x).begin(),(x).end()
#define len(x) (int) (x).size()
#define pb push_back

const int N = 1e5 + 7;
vector<int> adj[N], cmp[N], cmp2[N];
int n, m1, m2, par[N], cmp_num[N];
vector<pii> e1, e2, ans;
bool good[N], mark[N];
queue<int> q;
set<pii> s;

void read_input() {
	cin >> n >> m1 >> m2;
	for (int i = 0; i < m1; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		e1.pb({u, v});
	}
	for (int i = 0; i < m2; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		e2.pb({u, v});
	}
}

void add_ed1(int u, int v) {
	ans.pb({u + 1, v + 1});
	for (int x: cmp2[cmp_num[v]]) {
		q.push(x);
		good[x] = false;
		s.erase({par[x], x});
	}
	
}

void add_ed2(int u, int v) {
	u = par[u], v = par[v];
	if (len(cmp[u]) > len(cmp[v]))
		swap(u, v);
	for (int x: cmp[u]) {
		cmp[v].pb(x);
		if (good[x]) {
			s.erase({par[x], x});
			s.insert({v, x});
		}
		par[x] = v;
	}
}

void graph() {
	if (m1 < m2) 
		swap(e1, e2), swap(m1, m2);
	for (auto [u, v]: e1)
		adj[u].pb(v), adj[v].pb(u);
	for (int i = 0; i < n; i++) {
		par[i] = i;
		cmp[i].pb(i);
	}
	for (auto [u, v]: e2)
		add_ed2(u, v);
}

void dfs(int u) {
	mark[u] = true;
	cmp_num[u] = cmp_num[n];
	cmp2[cmp_num[u]].pb(u);
	for (int v: adj[u])
		if (!mark[v])
			dfs(v);
}

void prepare() {
	for (int i = 0; i < n; i++)
		if (!mark[i]) {
			cmp_num[n]++;
			dfs(i);
		}
	for (int u = 0; u < n; u++)
		if (cmp_num[u] != 1) {
			good[u] = true;
			s.insert({par[u], u});
		}
		else
			q.push(u);
}

int32_t main() {
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	read_input(), graph(), prepare();
	while (m1 != n - 1) {
		int u = q.front(), v;
		int t = par[u];
		pii p1 = *s.begin(), p2 = *(--s.end());
		if (p1.F == t && p2.F == t) {
			q.pop();
			continue;
		}
		if (p1.F != t)
			v = p1.S;
		else
			v = p2.S;
		m1++;
		add_ed1(u, v);
		add_ed2(u, v);
	}
	cout << len(ans) << '\n';
	for (auto [u, v]: ans)
		cout << u << ' ' << v << '\n';
	return 0;
}
