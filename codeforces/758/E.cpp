#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct Tree {
	vector<vector<int>> adj;
	vector<ll> dp_min, dp_max, dp_w, reduce, w, p;
	int n;
	Tree (int n) : n(n) {
		adj.resize(n+1);
		dp_min.resize(n+1);
		dp_max.resize(n+1);
		dp_w.resize(n+1);
		w.resize(n+1);
		p.resize(n+1);
		reduce.resize(n+1);
		p[1] = LLONG_MAX;
	}
	bool dfs(int v) {
		for (int u: adj[v]) {
			if (!dfs(u)) return false;
			dp_min[v] += dp_min[u] + w[u] - min(w[u]-1, p[u]-dp_min[u]);
			dp_max[v] += dp_max[u] + w[u];
			dp_w[v] += dp_w[u] + w[u];
		}
		if (dp_min[v] > p[v]) return false;
		dp_max[v] = min(p[v], dp_max[v]);
		return true;
	}
	void dfs(int v, ll s) {
		for (int u: adj[v]) {
			ll new_reduce = dp_w[u] - dp_max[u];
			reduce[u] = new_reduce, s -= new_reduce;
		}
		for (int u: adj[v]) {
			if (s == 0) break;
			ll new_reduce = min(s, dp_max[u]-dp_min[u]);
			reduce[u] += new_reduce, s -= new_reduce; 
		}
		for (int u: adj[v]) {
			if (s == 0) break;
			ll new_reduce = min(s, min(w[u]-1, p[u]-dp_min[u]));
			w[u] -= new_reduce, p[u] -= new_reduce, s -= new_reduce;
		}
		for (int u: adj[v]) {
			dfs(u, reduce[u]);
		}
	}
};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int n, x, y, w, p;
	cin >> n;
	Tree tree(n);

	vector<pair<int, int>> idx;
	for (int i = 1; i < n; i++) {
		cin >> x >> y >> w >> p;
		idx.push_back({x, y});
		tree.adj[x].push_back(y);
		tree.w[y] = w, tree.p[y] = p;
	}
	if (tree.dfs(1)) {
		tree.dfs(1, tree.dp_w[1]-tree.dp_max[1]);
		cout << n << endl;
		for (auto [u, v]: idx)
			cout << u << " " << v << " " << tree.w[v] << " " << tree.p[v] << endl;
	} else {
		cout << -1 << endl;
	}


}