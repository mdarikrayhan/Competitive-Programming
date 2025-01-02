// In the name of Allah

#include <bits/stdc++.h>
using namespace std;

typedef		long long int			ll;
typedef		long double				ld;
typedef		pair<int, int>			pii;
typedef		pair<ll, ll>			pll;
typedef		complex<ld>				cld;

#define		all(x)					(x).begin(),(x).end()
#define		len(x)					((ll) (x).size())
#define		F						first
#define		S						second
#define		X						real()
#define		Y						imag()
#define		pb						push_back
#define		sep						' '
#define		endl					'\n'
#define		Mp						make_pair
#define		kill(x)					cout << x << '\n', exit(0)
#define		set_dec(x)				cout << fixed << setprecision(x);
#define		file_io(x,y)			freopen(x, "r", stdin); freopen(y, "w", stdout);

int n, m, s, t;
const int maxn = 1000 + 4;
const int maxm = 3e4 + 4;
const ll oo = 1e18 + 7;
vector<pii> adj[maxn];
vector<pair<pii, ll>> E;
int mark[maxn], M[maxn];
int mn[maxn], h[maxn]; vector<int> ls;
ll res; vector<int> ans;

void pre_dfs(int v, int ind) {
	mark[v] = 1;
	M[v] = (v == t);
	for (auto f : adj[v]) {
		int u = f.F, j = f.S;
		if (!mark[u]) {
			pre_dfs(u, j);
			M[v] |= M[u];
		}
	}
	if (M[v] && ind != -1) ls.pb(ind);
}

void dfs(int v, int ind, int i) {
	mark[v] = 1;
	M[v] = (v == t); mn[v] = h[v];
	for (auto f : adj[v]) {
		int u = f.F, j = f.S;
		if (i == j) continue;
		if (!mark[u]) {
			h[u] = h[v] + 1;
			dfs(u, j, i);
			mn[v] = min(mn[v], mn[u]); M[v] |= M[u];
		}
		else if (j != ind) {
			mn[v] = min(mn[v], h[u]);
		}
	}
	
	if (M[v] && ind != -1 && mn[v] == h[v]) {
		if (E[i].S + E[ind].S < res) {
			res = E[i].S + E[ind].S;
			ans = {i, ind};
		}
	}
}

void cal(int j) {
	fill(mark, mark + n, 0);
	h[s] = 0; dfs(s, -1, j);
	if (!mark[t] && E[j].S < res) {
		res = E[j].S;
		ans = {j};
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	cin >> n >> m;
	cin >> s >> t; s--; t--;
	for (int i = 0; i < m; i++) {
		int u, v; ll w;
		cin >> u >> v >> w; u--; v--;
		adj[u].pb(Mp(v, i)); adj[v].pb(Mp(u, i));
		E.pb(Mp(Mp(u, v), w));
	}
	
	pre_dfs(s, -1);
	if (!mark[t]) res = 0;
	else res = oo;
	
	for (int j : ls) cal(j);
	
	if (res == oo) kill(-1);
	cout << res << endl;
	cout << len(ans) << endl;
	for (int j : ans) cout << j + 1 << sep;
	cout << endl;
	
	return 0;
}
