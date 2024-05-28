// Problem: https://codeforces.com/contest/1902/problem/F
// Status: Accepted
// Submission: https://codeforces.com/contest/1902/submission/261648278
#include <bits/stdc++.h>
using namespace std;

#define fst first
#define snd second
#define pb push_back
#define fore(i, a, b) for (ll i = a, gmat = b; i < gmat; i++)
#define ALL(x) begin(x), end(x)
#define SZ(x) (ll)(x).size()
#define mset(a, v) memset((a), (v), sizeof(a))
typedef long long ll;
typedef pair<ll, ll> ii;
typedef vector<ll> vi;

/// content/graph/TreePathQueries.h
struct PathQueries {
/// START diff
	typedef vector<int> T;
	const T neut = {};
	T f(const T& a, const T& b) {
		T ans = a;
		for (int x : b) {
			for (int y : ans) {
				x = min(x, x ^ y);
			}
			if (x != 0) {
				ans.pb(x);
			}
		}
		return ans;
	} // (any associative and commutative fn)
/// END diff

	ll n, K;
	vector<vi> anc;
	vector<vector<T>> part;
	vi depth;
	PathQueries(const vector<vi>& g, vector<T>& vals) // NODES
		: n(SZ(g)), K(64 - __builtin_clzll(n)), anc(K, vi(n, -1)),
			part(K, vector<T>(n, neut)), depth(n) {
		part[0] = vals;
//PathQueries(vector<vector<pair<ll, T>>> &g_) // EDGES
//	: n(SZ(g_)), K(64 - __builtin_clzll(n)), anc(K, vi(n, -1)),
//		part(K, vector<T>(n, neut)), depth(n) {
//	vector<vi> g(n);
//	fore(u, 0, n) for (auto [v, data] : g_[u]) {
//		g[u].pb(v);
//	}
		vi s = {0};
		while (!s.empty()) {
			ll u = s.back();
			s.pop_back();
			for (ll v : g[u]) if (v != anc[0][u]) {
				anc[0][v] = u, depth[v] = depth[u] + 1, s.pb(v);
			}
		}
//	fore(u, 0, n) for (auto [v, data] : g_[u]) { // EDGES
//		part[0][depth[u] > depth[v] ? u : v] = data;
//	}
		fore(k, 0, K - 1) fore(v, 0, n) {
			if (anc[k][v] != -1) {
				anc[k + 1][v] = anc[k][anc[k][v]];
				part[k + 1][v] = f(part[k][v], part[k][anc[k][v]]);
			}
		}
	}
	T query(ll u, ll v) {
		if (depth[u] < depth[v]) swap(u, v);
		T ans = neut;
		fore(k, 0, K) if ((depth[u] - depth[v]) & (1 << k))
			ans = f(ans, part[k][u]), u = anc[k][u];
		if (u == v) return f(ans, part[0][u]); // NODES
//	if (u == v) return ans; // EDGES
		for (ll k = K; k--;) if (anc[k][u] != anc[k][v]) {
			ans = f(ans, f(part[k][u], part[k][v]));
			u = anc[k][u], v = anc[k][v];
		}
		ans = f(ans, f(part[0][u], part[0][v]));
		return f(ans, part[0][anc[0][u]]); // NODES
//	return ans; // EDGES
	}
};
/// END content

int main() {
	cin.tie(0)->sync_with_stdio(0);

	ll n;
	cin >> n;
	vector<PathQueries::T> vals(n);
	for (PathQueries::T& b : vals) {
		int a;
		cin >> a;
		b = {a};
	}

	vector<ii> edges(n - 1);
	for (auto& [u, v] : edges) {
		cin >> u >> v;
		u--; v--;
	}

	vector<vi> g(n);
	for (auto [u, v] : edges) {
		g[u].pb(v), g[v].pb(u);
	}

	PathQueries pq(g, vals);

	ll q;
	cin >> q;

	while (q--) {
		ll x, y;
		int k;
		cin >> x >> y >> k;
		x--, y--;

		PathQueries::T path = pq.query(x, y);

		for (int b : path) {
			k = min(k, k ^ b);
		}

		cout << (k == 0 ? "YES" : "NO") << '\n';
	}
}
